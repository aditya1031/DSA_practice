// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

void rotateBrtue(vector<vector<int>> &matrix) // tc O(2n^2)
// SC O(n^2)
{
     if (matrix.empty())
          return;
     int n = matrix.size();

     vector<vector<int>> Ans(n, vector<int>(n));
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n; j++)
          {
               Ans[j][(n - 1) - i] = matrix[i][j];
          }
     }

     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n; j++)
          {
               matrix[i][j] = Ans[i][j];
          }
     }
}

void rotateOptimal(vector<vector<int>> &matrix) // tc O(n^2)
// SC O(1)
{
     if (matrix.empty())
          return;
     int n = matrix.size();

     // Step 1: Transpose  O(n*n/2) tc
     for (int i = 0; i < n - 1; i++)
     {
          for (int j = i + 1; j < n; j++)
          {
               if (i != j)
               {
                    swap(matrix[i][j], matrix[j][i]);
               }
          }
     }
     // Step 2: Reverse each row  o(n*n/2) tc

     for (int i = 0; i < n; i++)
     {
          reverse(matrix[i].begin(), matrix[i].end());
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

     rotateOptimal(matrix);
     cout << "Matrix rotated:\n";
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