// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
==================== BRUTE FORCE ROTATION (Using Extra Matrix) ====================

Idea:
- Create a temporary matrix `tempM`
- Place element matrix[i][j] to its rotated position:
      tempM[j][n - i - 1] = matrix[i][j]
- Copy tempM back to matrix

This rotates the matrix by 90 degrees clockwise.

Time Complexity (TC):
- Filling temp matrix: O(n^2)
- Copying back: O(n^2)
=> TC = O(n^2)

Space Complexity (SC):
- Extra matrix of size n x n
=> SC = O(n^2)
*/
void rotateBrute(vector<vector<int>> &matrix)
{
     int n = matrix.size();

     vector<vector<int>> tempM(n, vector<int>(n));

     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n; j++)
          {
               // placing element in rotated position
               tempM[j][n - i - 1] = matrix[i][j];
          }
     }

     // copying rotated matrix back
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n; j++)
          {
               matrix[i][j] = tempM[i][j];
          }
     }
}

/*
==================== OPTIMAL ROTATION (In-Place) ====================

Idea:
1. Transpose the matrix (swap across diagonal)
2. Reverse each row

This achieves 90-degree clockwise rotation without extra space.

Time Complexity (TC):
- Transpose: O(n^2)
- Reverse rows: O(n^2)
=> TC = O(n^2)

Space Complexity (SC):
- No extra matrix used
=> SC = O(1)
*/
void rotateBrute(vector<vector<int>> &matrix)
{
     int n = matrix.size();

     // Step 1: Transpose matrix
     for (int i = 0; i < n; i++)
     {
          for (int j = i + 1; j < n; j++)
          {
               swap(matrix[i][j], matrix[j][i]);
          }
     }

     // Step 2: Reverse each row
     for (int i = 0; i < n; i++)
     {
          reverse(matrix[i].begin(), matrix[i].end());
     }
}

int main()
{
     int m, n; // m = rows, n = columns
     cin >> n;

     vector<vector<int>> arr(n, vector<int>(n));

     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n; j++)
          {
               cin >> arr[i][j];
          }
     }

     cout << "the rotated matrix : ";
     for (int i = 0; i < m; i++)
     {
          for (int j = 0; j < n; j++)
          {
               cout << arr[i][j];
          }
     }
     return 0;
}
