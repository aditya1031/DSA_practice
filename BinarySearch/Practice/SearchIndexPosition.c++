// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int insertPosition(vector<int>&nums, int x)
{
     int n = nums.size();
     int ans = n;
     int low = 0;
     int high = n - 1;
     while (low<=high)
     {
          int mid=(low+high)/2;
          if(nums[mid]>=x)
          {
               ans=mid;
               high=mid-1;
          }
          else{
               low=mid+1;
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

     int x;
     cin >> x;
     cout << insertPosition(arr, x);

     return 0;
}