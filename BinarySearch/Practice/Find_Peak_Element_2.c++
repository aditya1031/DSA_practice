// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int maxElement(vector<vector<int>> &mat, int n, int col)
{
     int maxRow = 0;
     for (int i = 0; i < n; i++)
     {
          if (mat[maxRow][col] < mat[i][col])
          {
               maxRow = i;
          }
     }
     return maxRow;
}

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
     int row = mat.size();
     int col = mat[0].size();
     int low = 0;
     int high = col - 1;
     while (low <= high)
     {
          int mid = (low + high) / 2;
          int maxRow = maxElement(mat, row, mid);
          int curr = mat[maxRow][mid];
          int left = mid - 1 >= 0 ? mat[maxRow][mid - 1] : -1;
          int right = mid + 1 < col ? mat[maxRow][mid + 1] : -1;
          if (curr > left && curr > right)
          {
               return {maxRow, mid};
          }
          else if (curr < left)
          {
               high = mid - 1;
          }
          else
          {
               low = mid + 1;
          }
     }
     return {-1, -1};
}

int main()
{

     return 0;
}
