// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
==================== BRUTE FORCE APPROACH ====================

Idea:
- Traverse the matrix
- When a 0 is found:
  - Mark its entire row and column as -1 (except existing 0s)
- After traversal, convert all -1 to 0

Why -1?
- Acts as a temporary marker so original zeros don’t interfere

Time Complexity (TC):
- For each cell (r * c)
- Row marking takes O(c)
- Column marking takes O(r)
=> TC = O(r * c * (r + c))

Space Complexity (SC):
- No extra data structures
=> SC = O(1)
*/
void setZeroBrute(vector<vector<int>> &matrix)
{
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
                              matrix[i][col] = -1;
                    }

                    for (int row = 0; row < r; row++)
                    {
                         if (matrix[row][j] != 0)
                              matrix[row][j] = -1;
                    }
               }
          }
     }

     // Convert all markers (-1) to 0
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

/*
==================== BETTER APPROACH ====================

Idea:
- Use two helper arrays:
  row[] → marks rows that must be zero
  col[] → marks columns that must be zero
- First pass: record where zeros appear
- Second pass: update matrix using row[] and col[]

Time Complexity (TC):
- Two full traversals of matrix
=> TC = O(r * c)

Space Complexity (SC):
- row[r] + col[c]
=> SC = O(r + c)
*/
void setZeroBetter(vector<vector<int>> &matrix)
{
     int r = matrix.size();
     int c = matrix[0].size();

     vector<int> row(r, 0);
     vector<int> col(c, 0);

     for (int i = 0; i < r; i++)
     {
          for (int j = 0; j < c; j++)
          {
               if (matrix[i][j] == 0)
               {
                    row[i] = -1;
                    col[j] = -1;
               }
          }
     }

     for (int i = 0; i < r; i++)
     {
          for (int j = 0; j < c; j++)
          {
               if (row[i] == -1 || col[j] == -1)
               {
                    matrix[i][j] = 0;
               }
          }
     }
}

/*
==================== OPTIMAL APPROACH ====================

Idea:
- Use first row and first column as marker arrays
- Extra variable `col` tracks whether column 0 should be zero
- Avoids extra space

Steps:
1. Mark rows & columns using matrix[0][j] and matrix[i][0]
2. Update inner matrix
3. Handle first row separately
4. Handle first column separately

Time Complexity (TC):
- Two matrix traversals
=> TC = O(r * c)

Space Complexity (SC):
- Uses constant extra variables only
=> SC = O(1)
*/
void setZeroOPtimal(vector<vector<int>> &matrix)
{
     int r = matrix.size();
     int c = matrix[0].size();

     int col = 1;

     for (int i = 0; i < r; i++)
     {
          for (int j = 0; j < c; j++)
          {
               if (matrix[i][j] == 0)
               {
                    matrix[i][0] = 0;

                    if (j == 0)
                         col = 0;
                    else
                         matrix[0][j] = 0;
               }
          }
     }

     for (int i = 1; i < r; i++)
     {
          for (int j = 1; j < c; j++)
          {
               if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
          }
     }

     if (matrix[0][0] == 0)
     {
          for (int i = 0; i < c; i++)
               matrix[0][i] = 0;
     }

     if (col == 0)
     {
          for (int i = 0; i < r; i++)
               matrix[i][0] = 0;
     }
}
int main()
{
     int m, n; // m = rows, n = columns
     cin >> m >> n;

     vector<vector<int>> arr(m, vector<int>(n));

     for (int i = 0; i < m; i++)
     {
          for (int j = 0; j < n; j++)
          {
               cin >> arr[i][j];
          }
     }
     // setZeroBrute(arr);
     // setZeroBetter(arr);
     setZeroOPtimal(arr);

     cout << "the resulted matrix : ";
     for (int i = 0; i < m; i++)
     {
          for (int j = 0; j < n; j++)
          {
               cout << arr[i][j];
          }
     }
     return 0;
}
