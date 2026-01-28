// git - aditya1031
#include <bits/stdc++.h>
using namespace std;

/*
----------------------------------------
BRUTE FORCE
----------------------------------------
Works for: ✅ Positive, Negative, Zero
Idea:
- Check all subarrays and calculate sum

Time Complexity (TC): O(n^2)
Space Complexity (SC): O(1)
*/
int SubArraySum_Brute(vector<int> &nums, int T)
{
     int n = nums.size();
     int maxLen = 0;

     for (int i = 0; i < n; i++)
     {
          int sum = 0;
          for (int j = i; j < n; j++)
          {
               sum += nums[j];
               if (sum == T)
               {
                    maxLen = max(maxLen, j - i + 1);
               }
          }
     }
     return maxLen;
}

/*
----------------------------------------
BETTER (PREFIX SUM + HASHING)
----------------------------------------
Works for: ✅ Positive, Negative, Zero
Idea:
- Store first occurrence of prefix sum
- If (currentSum - T) exists → subarray found

Time Complexity (TC): O(n)
Space Complexity (SC): O(n)
*/
int SubArraySum_Better(vector<int> &nums, int T)
{
     int n = nums.size();
     int maxLen = 0;
     int sum = 0;
     unordered_map<int, int> mpp; // prefixSum -> index

     for (int i = 0; i < n; i++)
     {
          sum += nums[i];

          // subarray from index 0
          if (sum == T)
          {
               maxLen = i + 1;
          }

          // subarray between indices
          if (mpp.find(sum - T) != mpp.end())
          {
               maxLen = max(maxLen, i - mpp[sum - T]);
          }

          // store first occurrence only
          if (mpp.find(sum) == mpp.end())
          {
               mpp[sum] = i;
          }
     }
     return maxLen;
}

/*
----------------------------------------
OPTIMAL (SLIDING WINDOW - FOR LOOP)
----------------------------------------
Works for: ⚠️ POSITIVE NUMBERS ONLY
Idea:
- Expand window using right
- Shrink window using left when sum > T

Time Complexity (TC): O(n)
Space Complexity (SC): O(1)
*/
int SubArraySum_Optimal(vector<int> &nums, int T)
{
     int n = nums.size();
     int maxLen = 0;
     int sum = 0;
     int left = 0;

     for (int right = 0; right < n; right++)
     {
          sum += nums[right];

          while (sum > T)
          {
               sum -= nums[left];
               left++;
          }

          if (sum == T)
          {
               maxLen = max(maxLen, right - left + 1);
          }
     }
     return maxLen;
}

/*
----------------------------------------
OPTIMAL (SLIDING WINDOW - WHILE LOOP)
----------------------------------------
Works for: ⚠️ POSITIVE NUMBERS ONLY
Idea:
- Same as above, written using while loop

Time Complexity (TC): O(n)
Space Complexity (SC): O(1)
*/
int SubArraySum_Optimal2(vector<int> &nums, int T)
{
     int n = nums.size();
     int maxLen = 0;
     int sum = 0;
     int left = 0;
     int right = 0;

     while (right < n)
     {
          sum += nums[right];

          while (sum > T)
          {
               sum -= nums[left];
               left++;
          }

          if (sum == T)
          {
               maxLen = max(maxLen, right - left + 1);
          }
          right++;
     }
     return maxLen;
}

int main()
{
     vector<int> arr = {10, 5, 2, 7, 1, 9};
     int T = 15;

     cout << SubArraySum_Better(arr, T);
     return 0;
}
