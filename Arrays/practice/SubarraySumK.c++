// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
==================== BRUTE FORCE ====================

Approach:
- Consider all possible subarrays using 3 loops
- For every subarray [i..j], calculate sum using another loop
- If sum == T, increment count

Time Complexity (TC):
- Three nested loops
=> O(n^3)

Space Complexity (SC):
- Only variables used
=> O(1)
*/
int subarraySumBrute(vector<int> &nums, int T)
{
     int n = nums.size();

     int cnt = 0;
     for (int i = 0; i < n; i++)
     {
          for (int j = i; j < n; j++)
          {
               int sum = 0;
               for (int k = i; k <= j; k++)
               {
                    sum += nums[k];
               }
               if (sum == T)
               {
                    cnt++;
               }
          }
     }

     return cnt;
}

/*
==================== BETTER APPROACH ====================

Approach:
- Fix starting index i
- Extend subarray to the right
- Maintain running sum instead of recalculating

Time Complexity (TC):
- Two nested loops
=> O(n^2)

Space Complexity (SC):
- No extra space
=> O(1)
*/
int subarraySumBetter(vector<int> &nums, int T)
{
     int n = nums.size();

     int cnt = 0;
     for (int i = 0; i < n; i++)
     {
          int sum = 0;
          for (int j = i; j < n; j++)
          {
               sum += nums[j];

               if (sum == T)
               {
                    cnt++;
               }
          }
     }

     return cnt;
}

/*
==================== OPTIMAL APPROACH ====================

Approach:
- Use Prefix Sum + HashMap
- If (currentSum - T) exists before,
  then subarray with sum T exists
- HashMap stores frequency of prefix sums

Key Idea:
prefixSum[j] - prefixSum[i] = T

Time Complexity (TC):
- Single traversal
=> O(n)

Space Complexity (SC):
- HashMap stores prefix sums
=> O(n)
*/
int subarraySumOptimal(vector<int> &nums, int T)
{
     int n = nums.size();

     int cnt = 0;
     int presum = 0;
     int sum = 0;

     unordered_map<int, int> mpp;
     mpp[0] = 1;   // base case for subarrays starting at index 0

     for (int i = 0; i < n; i++)
     {
          sum += nums[i];
          presum = sum - T;

          if (mpp.find(presum) != mpp.end())
          {
               cnt += mpp[presum];
          }

          mpp[sum]++;
     }

     return cnt;
}

int main()
{
     int n, T;
     cin >> n >> T;

     vector<int> arr(n);
     for (int i = 0; i < n; i++)
     {
          cin >> arr[i];
     }

     // Call any approach
     // cout << "Brute Force: "
     //      << subarraySumBrute(arr, T) << endl;

     // cout << "Better: "
     //      << subarraySumBetter(arr, T) << endl;

     cout << "Optimal: "
          << subarraySumOptimal(arr, T) << endl;

     return 0;
}
