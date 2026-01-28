// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Brute Force Approach
Find length of longest subarray with sum = 0
TC = O(n^2)
SC = O(1)
---------------------------------------------------------
*/
int subarryBrute(vector<int> &nums)
{
     int n = nums.size();
     int mxaLen = 0;

     for (int i = 0; i < n; i++)
     {
          int sum = 0;

          for (int j = i; j < n; j++)
          {
               sum += nums[j];

               // if subarray sum becomes zero
               if (sum == 0)
               {
                    mxaLen = max(mxaLen, j - i + 1);
               }
          }
     }
     return mxaLen;
}

/*
---------------------------------------------------------
Optimal Approach (Prefix Sum + Hashing)
TC = O(n)
SC = O(n)
---------------------------------------------------------
*/
int subArrayOptimal(vector<int> &nums)
{
     int n = nums.size();
     int maxLen = 0;
     int sum = 0;

     // map stores first occurrence of prefix sum
     unordered_map<int, int> mpp;

     for (int i = 0; i < n; i++)
     {
          sum += nums[i];

          // if prefix sum is zero
          if (sum == 0)
          {
               maxLen = i + 1;
          }
          // if same prefix sum seen before
          else if (mpp.find(sum) != mpp.end())
          {
               maxLen = max(maxLen, i - mpp[sum]);
          }
          // store first occurrence of prefix sum
          else
          {
               mpp[sum] = i;
          }
     }
     return maxLen;
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

     subarryBrute(arr); // result not printed (same as original)

     return 0;
}
