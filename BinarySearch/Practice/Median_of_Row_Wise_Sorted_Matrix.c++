// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int medianBrute(vector<vector<int>> &mat)
{
     int n = mat.size();
     int m = mat[0].size();

     vector<int> ls;

     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++)
          {
               ls.push_back(mat[i][j]);
          }
     }

     sort(ls.begin(), ls.end());

     return ls[(n * m) / 2];
}

int UpperBound(vector<int> &nums, int k)
{
     int n = nums.size();

     int low = 0;
     int high = n - 1;
     int ans = n;
     while (low <= high)
     {
          int mid = (low + high) / 2;

          if (nums[mid] > k)
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
int smallerEqualCal(vector<vector<int>> &mat, int K)
{
     int n = mat.size();
    
     int cnt = 0;
     for (int i = 0; i < n; i++)
     {
          cnt += UpperBound(mat[i], K);
     }
     return cnt;
}

int medianOptimal(vector<vector<int>> &mat)
{
     int n = mat.size();
     int m = mat[0].size();

     int low = INT_MAX;
     int high = INT_MIN;
     for (int i = 0; i < n; i++)
     {
          low = min(low, mat[i][0]);
          high = max(high, mat[i][m - 1]);
     }

     int req = (n * m) / 2;
     while (low <= high)
     {
          int mid = (low + high) / 2;
          int smallerEqual = smallerEqualCal(mat, mid);

          if (smallerEqual <= req)
          {
               low = mid + 1;
          }
          else
          {
               high = mid - 1;
          }
     }
     return low;
}

int main()
{

     return 0;
}