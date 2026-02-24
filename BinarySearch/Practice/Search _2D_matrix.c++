// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

bool searchMatrixBrute(vector<vector<int>> &matrix, int target)
{
     int r = matrix.size();
     int c = matrix[0].size();

     for (int i = 0; i < r; i++)
     {
          for (int j = 0; j < c; j++)
          {
               if (matrix[i][j] == target)
               {
                    return true;
               }
          }
     }
     return false;
}

bool binarySearch(vector<int> &arr, int target)
{
     int n = arr.size();
     int low = 0;
     int high = n - 1;
     while (low <= high)
     {
          int mid = low + (high - low) / 2;
          if (arr[mid] == target)
          {
               return true;
          }
          else if (arr[mid] < target)
          {
               low = mid + 1;
          }
          else
          {
               high = mid - 1;
          }
     }
     return false;
}
bool searchMatrixBetter(vector<vector<int>> &matrix, int target)
{
     int r = matrix.size();
     for (int i = 0; i < r; i++)
     {
          if (binarySearch(matrix[i], target))
          {
               return true;
          };
     }
     return false;
}

bool searchMatrixOptimal(vector<vector<int>> &matrix, int target)
{
     int r = matrix.size();
     int c = matrix[0].size();

     int low = 0;
     int high = (c * r) - 1;

     while (low <= high)
     {
       int mid = low + (high - low) / 2;
          int row = mid / c;
          int col = mid % c;

          if (matrix[row][col] == target)
          {
               return true;
          }
          else if (matrix[row][col] < target)
          {
               low=mid+1;
          }
          else{
               high=mid-1;
          }
     }

     return false;
}

int main()
{

     return 0;
}