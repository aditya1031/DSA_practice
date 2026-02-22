// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int maxRow(vector<vector<int>> &matrix)
{
     if (matrix.empty())
          return -1;
     int r = matrix.size();
     int c = matrix[0].size();

     int maxCount = -1;
     int ans = -1;

     for (int i = 0; i < r; i++)
     {
          int cntRow = 0;
          for (int j = 0; j < c; j++)
          {
               cntRow += matrix[i][j];
          }
          if (cntRow > maxCount)
          {
               maxCount = cntRow;
               ans = i;
          }
     }
     return ans;
}

int lowerBound(vector<int> &arr, int x)
{
     int n = arr.size();
     int low = 0;
     int high = n - 1;
     int ans = n;
     while (low <= high)
     {
          int mid = (low + high) / 2;
          if (arr[mid] >= x)
          {
               ans = mid;
               high = mid - 1;
          }
          else
          {
               low = mid + 1;
          }
     }
     return ans;
}

int maxRow(vector<vector<int>> &matrix)
{
     if (matrix.empty())
          return -1;
     int r = matrix.size();
     int c = matrix[0].size();

     int maxCount = 0;
     int ans = -1;

     for (int i = 0; i < r; i++)
     {
          int cnt = c - lowerBound(matrix[i], 1);
          if(cnt>maxCount)
          {
               ans=i;
               maxCount=cnt;
          }
     }

     return ans;
}

int main()
{

     return 0;
}