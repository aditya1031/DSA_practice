// git - aditya1031

#include <bits/stdc++.h>
using namespace std;
// TC = O(log N)
// SC = O(1)
int binarySearchIterate(vector<int> &nums, int k)
{
     int n = nums.size();

     int low = 0;
     int high = n - 1;
     while (low <= high)
     {
          int mid = (low + high) / 2;

          if (nums[mid] == k)
          {
               return mid;
          }
          else if (nums[mid] > k)
          {
               high = mid - 1;
          }
          else
          {
               low = mid + 1;
          }
     }

     return -1;
}

// TC = O(log N)
// SC = O(N)
int binarySearchRecursive(vector<int> &nums, int low, int high, int k)
{
     if (low > high)
          return -1;

     int mid = (low + high) / 2;

     if (nums[mid] == k)
     {
          return mid;
     }

     else if (nums[mid] < k)
     {
          return binarySearchRecursive(nums, mid + 1, high, k);
     }
     else
     {
          return binarySearchRecursive(nums, low, mid - 1, k);
     }
     return -1;
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
     cout << binarySearchRecursive(arr, 0, n - 1, k);

     return 0;
}