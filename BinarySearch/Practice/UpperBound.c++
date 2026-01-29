// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

// TC = O(log N)
// SC = O(1)
int UpperBound(vector<int> &nums, int k)
{
     int n = nums.size();

     int low = 0;
     int high = n - 1;
     int ans = n ;
     while (low <= high)
     {
          int mid = (low + high) / 2;

          if (nums[mid] > k)
          {
               ans = mid;
               high=mid-1;
          }
          else
          {
               low = mid + 1;
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

     int k = 0;
     cin >> k;
     // cout << binarySearchIterate(arr, k);
     cout << UpperBound(arr, k);

    int lb=upper_bound(arr.begin(),arr.end(),k)-arr.begin();

     return 0;
}