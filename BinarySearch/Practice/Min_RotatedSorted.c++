// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int minBrute(vector<int> &nums)
{
     int n = nums.size();
     int min = nums[0];
     for (int i = 0; i < n; i++)
     {
          if (nums[i] < min)
          {
               min = nums[i];
          }
     }
     return min;
}

int minOptimal(vector<int> &nums)
{
     int n = nums.size();
     int ans = INT_MAX;
     int low = 0;
     int high = n - 1;
     while (low <= high)
     {
          int mid = (low + high) / 2;

          if (nums[low] <= nums[high])
          {
               ans = min(ans, nums[low]);
               break;
          }

          if (nums[low] <= nums[mid])
          {
               ans = min(ans, nums[low]);
               low = mid + 1;
          }
          else
          {
               ans = min(ans, nums[mid]);
               high = mid - 1;
          }
     }
     return ans;
}

int main()
{
     int n;
     cin >> n;
     vector<int> arr(n);

     for (int i = 0; i < n; i++)
     {
          cin >> arr[i];
     }

     cout << "minimum in given array is:" << minOptimal(arr);
     return 0;
}