// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

vector<int> searchMatrixBrute(vector<vector<int>> &matrix, int target)
{
     if (matrix.empty() || matrix[0].empty())
          return {-1, -1};
     int r = matrix.size();
     int c = matrix[0].size();

     for (int i = 0; i < r; i++)
     {
          for (int j = 0; j < c; j++)
          {
               if (matrix[i][j] == target)
               {
                    return {i, j};
               }
          }
     }
     return {-1, -1};
}

int binarySearch(vector<int> &arr, int target)
{
     int n = arr.size();
     int low = 0;
     int high = n - 1;
     while (low <= high)
     {
          int mid = low + (high - low) / 2;
          if (arr[mid] == target)
          {
               return mid;
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
     return -1;
}
vector<int> searchMatrixBetter(vector<vector<int>> &matrix, int target)
{
     if (matrix.empty() || matrix[0].empty())
          return {-1, -1};
     int r = matrix.size();
     for (int i = 0; i < r; i++)
     {
          int col = binarySearch(matrix[i], target);
          if (col != -1)
          {
               return {i, col};
          }
     }
     return {-1, -1};
}


// TC= O(r+c)
vector<int> searchMatrixOptimal(vector<vector<int>> &matrix, int target)
{
     if(matrix.empty() || matrix[0].empty()) return {-1,-1};
     int r = matrix.size();
     int c = matrix[0].size();

     int row = 0;
     int col = c - 1;
     while (row < r && col >= 0)
     {
          if(matrix[row][col]==target)
          {
               return {row,col} ;
          }
          else if(matrix[row][col]<target)
          {
               row++;
          }
          else{
               col--;
          }
     }
     return{-1,-1};
}

int main()
{

     return 0;
}