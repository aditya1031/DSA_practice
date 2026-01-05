// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

void matrixZeroBrute(vector<vector<int>> &matrix) // TC = O(r × c × (r + c))
// SC = O(1)

{
     if (matrix.empty())
          return;
     int r = matrix.size();
     int c = matrix[0].size();
     for (int i = 0; i < r; i++)
     {
          for (int j = 0; j < c; j++)
          {
               if (matrix[i][j] == 0)
               {
                    for (int col = 0; col < c; col++)
                    {
                         if (matrix[i][col] != 0)
                         {
                              matrix[i][col] = -1;
                         }
                    }

                    for (int row = 0; row < r; row++)
                    {
                         if (matrix[row][j] != 0)
                         {
                              matrix[row][j] = -1;
                         }
                    }
               }
          }
     }

     for (int i = 0; i < r; i++)
     {
          for (int j = 0; j < c; j++)
          {
               if (matrix[i][j] == -1)
               {
                    matrix[i][j] = 0;
               }
          }
     }
}

void matrixZerobetter(vector<vector<int>> &matrix) // Time Complexity: O 2(r × c)
// Space Complexity: O(r + c)

{
     if (matrix.empty())
          return;

     int r = matrix.size();
     int c = matrix[0].size();

     vector<int> markRow(r, 0);
     vector<int> markCol(c, 0);

     // Step 1: mark rows and columns
     for (int i = 0; i < r; i++)
     {
          for (int j = 0; j < c; j++)
          {
               if (matrix[i][j] == 0)
               {
                    markRow[i] = 1;
                    markCol[j] = 1;
               }
          }
     }

     // Step 2: set marked rows to zero
     for (int i = 0; i < r; i++)
     {
          for (int j = 0; j < c; j++)
          {
               if (markRow[i] == 1 || markCol[j] == 1)

                    matrix[i][j] = 0;
          }
     }
}

void matrixZeroOptimal(vector<vector<int>> &matrix) // Time Complexity: O 2(r × c)
// Space Complexity: O(1)
{
     if (matrix.empty())
          return;

     int r = matrix.size();
     int c = matrix[0].size();
     // markinf for row-> matrix[0][...]
     // marking for column -> matrix[...][0]
     int col0 = 1; // to keep the row colmn overlap in edge

     for (int i = 0; i < r; i++)
     {
          for (int j = 0; j < c; j++)
          {
               if (matrix[i][j] == 0)
               {
                    //mark the ith row
                    matrix[i][0] = 0;
                    //mark the jth col
                    if (j != 0)
                    {
                         matrix[0][j] = 0;
                    }
                    //
                    else
                    {
                         col0 = 0;
                    }
               }
          }
     }

     for (int i = 1; i < r; i++)
     {
          for (int j = 1; j < c; j++)
          {
               if (matrix[i][0] == 0 || matrix[0][j] == 0)
               {
                    matrix[i][j] = 0;
               }
          }
     }
     if (matrix[0][0] == 0)
     {
          for (int j = 0; j < c; j++)
          {
               matrix[0][j] = 0;
          }
     }

     if (col0 == 0)
     {
          for (int i = 0; i < r; i++)
          {
               matrix[i][0] = 0;
          }
     }
}

int main()
{
     int n, m;
     cout << "Enter number of rows and columns: ";
     cin >> n >> m;

     vector<vector<int>> matrix(n, vector<int>(m));

     cout << "Enter matrix elements:\n";
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++)
          {
               cin >> matrix[i][j];
          }
     }

     // Print the matrix to check input
     cout << "Matrix entered:\n";
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++)
          {
               cout << matrix[i][j] << " ";
          }
          cout << "\n";
     }

     return 0;
}