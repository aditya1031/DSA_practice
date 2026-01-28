// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int longestSubarrayBrute(vector<int> &nums, int num)
{
     int n = nums.size();
     int len = 0;
     for (int i = 0; i < n; i++)
     {

          for (int j = i; j < n; j++)
          {
               int sum = 0;
               for (int k = i; k <= j; k++)
               {
                    sum = sum + nums[k];
               }
               if (sum == num)
               {
                    len = max(len, j - i + 1);
               }
          }
     }
     return len;
}

int longestSubarrayBrute2(vector<int> &nums, int num)
{
     int n = nums.size();
     int len = 0;
     for (int i = 0; i < n; i++)
     {
          int sum = 0;
          for (int j = i; j < n; j++)
          {

               sum += nums[j];
               if (sum == num)
               {
                    len = max(len, j - i + 1);
               }
          }
     }
     return len;
}

int longestSubarrayBetter(vector<int> &nums, int num)

// int longestSubarrayBetter(vector<int> &nums, int num)
// Data Structure	          Find/Insert                  Total TC
// unordered_map	          O(1) avg	                   O(n) avg
// unordered_map	          O(n) worst	              O(n²) worst
// map (ordered)	          O(log n)	                   O(n log n)
{
     int n = nums.size();
     map<int, int> presumMap;
     int maxlen = 0;
     int sum = 0;
     for (int i = 0; i < n; i++)
     {
          sum += nums[i];
          if (sum == num)
          {
               maxlen = max(maxlen, i + 1);
          }
          int rem = sum - num;
          if (presumMap.find(rem) != presumMap.end())
          {
               int len = i - presumMap[rem];
               maxlen = max(maxlen, len);
          }
          if (presumMap.find(sum) == presumMap.end())
          {
               presumMap[sum] = i;
          }
     }
     return maxlen;
}

int longestSubarrayOptimal(vector<int> &nums, int num)
{

     //  TC - O(2n)
     // SC -O(1)

     int n = nums.size();
     int left = 0;
     int right = 0;
     int sum = 0;
     int maxlen = 0;
     while (right < n)
     {
          while (left <= right && sum > num)
          {
               sum -= nums[left];
               left++;
          }
          if (sum == num)
          {
               maxlen = max(maxlen, (right - left + 1));
          }

          right++;
          if (right < n)
               sum += nums[right];
     }

     return maxlen;
}

// not  for negative
int longestSubarrayOptimal2(vector<int> &nums, int num)
{
     int n = nums.size();
     int left = 0, sum = 0, maxlen = 0;

     for (int right = 0; right < n; right++)
     {
          sum += nums[right];
 
          while (sum > num && left <= right)
          {
               sum -= nums[left];
               left++;
          }

          if (sum == num)
          {
               maxlen = max(maxlen, right - left + 1);
          }
     }

     return maxlen;
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

     cout << " number is " << longestSubarrayOptimal(arr, k);
     return 0;
}