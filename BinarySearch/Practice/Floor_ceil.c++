// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

// Problem Statement: you're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1]. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x

int floorVal(vector<int> &nums, int x)
{
     int n = nums.size();
     int ans = -1;
     int low = 0;
     int high = n - 1;
     while (low <= high)
     {
          int mid = (low + high) / 2;
          if (nums[mid] <= x)
          {
               ans = nums[mid];
               low = mid + 1;
          }
          else
          {
               high = mid - 1;
          }
     }
     return ans;
}

int ceilVal(vector<int> &nums, int x)
{
     int n = nums.size();
     int ans = -1;
     int low = 0;
     int high = n - 1;
     while (low <= high)
     {
          int mid = (low + high) / 2;
          if (nums[mid] >= x)
          {
               ans = nums[mid];
               high = mid - 1;
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
     int x;
     cin >> x;
     sort(arr.begin(), arr.end());
     cout << "the floor is : " << floorVal(arr, x);
     cout << "the ceil is : " << ceilVal(arr, x);

     // int floorIdx = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
     // int ceilIdx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

     return 0;
}