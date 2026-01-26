// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
 Brute Force Approach
 -------------------
 Idea:
 - Try all possible subarrays
 - Maintain running sum for each starting index
 - If sum becomes 0, update maximum length

 Time Complexity: O(n^2)
 Space Complexity: O(1)
*/
int longestSubarrayBrute(vector<int> &nums)
{
     int n = nums.size();
     int maxLen = 0;

     for (int i = 0; i < n; i++)
     {
          int sum = 0;

          // check subarrays starting from index i
          for (int j = i; j < n; j++)
          {
               sum += nums[j];

               // if subarray sum is zero
               if (sum == 0)
               {
                    int currLen = j - i + 1;
                    maxLen = max(maxLen, currLen);
               }
          }
     }

     return maxLen;
}

/*
 Optimal Approach (Prefix Sum + HashMap)
 --------------------------------------
 Idea:
 - Maintain prefix sum
 - Store first occurrence of each prefix sum in map
 - If same prefix sum appears again, subarray in between has sum = 0

 Time Complexity: O(n)
 Space Complexity: O(n)
*/
int longestSubarrayOptimal(vector<int> &nums)
{
     int n = nums.size();
     int maxLen = 0;
     unordered_map<int, int> mpp; // prefixSum -> first index
     int sum = 0;

     for (int i = 0; i < n; i++)
     {
          sum += nums[i];

          // if prefix sum becomes zero
          if (sum == 0)
          {
               maxLen = i + 1;
          }
          else
          {
               // if same prefix sum seen before
               if (mpp.find(sum) != mpp.end())
               {
                    maxLen = max(maxLen, i - mpp[sum]);
               }
               else
               {
                    // store first occurrence of this prefix sum
                    mpp[sum] = i;
               }
          }
     }

     return maxLen;
}

int main()
{
     int n;
     cin >> n;

     vector<int> arr(n);

     // input array
     for (int i = 0; i < n; i++)
     {
          cin >> arr[i];
     }

     // calling brute force version
     cout << longestSubarrayBrute(arr);

     return 0;
}
