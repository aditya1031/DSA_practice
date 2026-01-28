// git - aditya1031
// Maximum Product Subarray (LeetCode 152)

#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Approach
Try all subarrays and compute product

Time Complexity: O(n^2)
Space Complexity: O(1)
*/
int maxProductBrute(vector<int> &nums)
{
     int n = nums.size();
     int ans = INT_MIN;

     for (int i = 0; i < n; i++)
     {
          int product = 1;
          for (int j = i; j < n; j++)
          {
               product *= nums[j];
               ans = max(ans, product);
          }
     }
     return ans;
}

/*
Optimal Approach (Prefix + Suffix Scan)

Idea:
- Product sign flips on negative numbers
- Zero breaks subarrays
- Scan from both left and right

Time Complexity: O(n)
Space Complexity: O(1)
*/
int maxProductOptimal(vector<int> &nums)
{
     int n = nums.size();
     int ans = INT_MIN;

     int prefix = 1;
     int suffix = 1;

     for (int i = 0; i < n; i++)
     {
          // Reset when product becomes zero
          if (prefix == 0)
               prefix = 1;
          if (suffix == 0)
               suffix = 1;

          prefix *= nums[i];
          suffix *= nums[n - i - 1];

          ans = max(ans, max(prefix, suffix));
     }
     return ans;
}

int main()
{
     int n;
     cin >> n;

     vector<int> arr(n);
     for (int i = 0; i < n; i++)
          cin >> arr[i];

     // cout << maxProductBrute(arr) << endl;
     // For optimal:
     cout << maxProductOptimal(arr) << endl;

     return 0;
}
