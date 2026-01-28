// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
==================== SPIRAL MATRIX TRAVERSAL ====================

Approach:
- Maintain four boundaries:
  top, bottom, left, right
- Traverse layer by layer in spiral order:
  1. Top row (left → right)
  2. Right column (top → bottom)
  3. Bottom row (right → left) [if valid]
  4. Left column (bottom → top) [if valid]
- Shrink boundaries after each traversal

Time Complexity (TC):
- Every element is visited exactly once
=> O(r * c)

Space Complexity (SC):
- Output vector stores all elements
=> O(r * c)
*/
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
     int r = matrix.size();
     int c = matrix[0].size();

     vector<int> ans;

     int top = 0, left = 0;
     int bottom = r - 1, right = c - 1;

     while (top <= bottom && left <= right)
     {
          // Top row
          for (int i = left; i <= right; i++)
               ans.push_back(matrix[top][i]);
          top++;

          // Right column
          for (int i = top; i <= bottom; i++)
               ans.push_back(matrix[i][right]);
          right--;

          // Bottom row
          if (top <= bottom)
          {
               for (int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);
               bottom--;
          }

          // Left column
          if (left <= right)
          {
               for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
               left++;
          }
     }

     return ans;
}

int main()
{
     int r, c;
     cin >> r >> c;          // rows and columns

     vector<vector<int>> matrix(r, vector<int>(c));

     // Input matrix
     for (int i = 0; i < r; i++)
          for (int j = 0; j < c; j++)
               cin >> matrix[i][j];

     // Get spiral order
     vector<int> result = spiralOrder(matrix);

     // Print spiral traversal
     for (int x : result)
          cout << x << " ";

     return 0;
}
