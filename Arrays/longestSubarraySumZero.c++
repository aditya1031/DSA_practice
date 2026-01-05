// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int subarryBrute(vector<int> &nums) // TC O(n^2)
{                                   // SC = O(1)
     int n = nums.size();
     int mxaLen = 0;
     for (int i = 0; i < n; i++)
     {
          int sum = 0;

          for (int j = i; j < n; j++)
          {
               sum += nums[j];

               if (sum == 0)
               {
                    mxaLen = max(mxaLen, j - i + 1);
               }
          }
     }
     return mxaLen;
}

int subArrayOptimal(vector<int> &nums) // TC O(n) , SC O(n)
{
     int n = nums.size();
     int maxLen = 0;
     int sum = 0;
     unordered_map<int, int> mpp;

     for (int i = 0; i < n; i++)
     {
          sum += nums[i];
          if (sum == 0)
          {
               maxLen = i + 1;
          }
          else if (mpp.find(sum) != mpp.end())
          {
               maxLen = max(maxLen, i - mpp[sum]);
          }
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

     subarryBrute(arr);

     return 0;
}