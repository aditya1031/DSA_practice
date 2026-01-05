// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int maxsubarrayBrute(vector<int> &nums)
{
     int maxSum = INT_MIN;
     for (int i = 0; i < nums.size(); i++)
     {
          for (int j = i; j < nums.size(); j++)
          {

               int sum = 0;
               for (int k = i; k <= j; k++)
               {
                    sum = sum + nums[k];
               }
               maxSum = max(maxSum, sum);
          }
     }
     return maxSum;
}

int maxsubarrayBetter(vector<int> &nums)
{
     int maxSum = INT_MIN;
     for (int i = 0; i < nums.size(); i++)
     {
          int sum = 0;
          for (int j = i; j < nums.size(); j++)
          {

               sum = sum + nums[j];
               maxSum = max(maxSum, sum);
          }
     }
     return maxSum;
}

int maxsubarrayBetterOptimal(vector<int> &nums) // kadane's algo
{
     int maxSum = INT_MIN;
     int sum = 0;

     for (int i = 0; i < nums.size(); i++)
     {

          sum += nums[i];

          if (maxSum < sum)
          {
               maxSum = sum;
          }

          if (sum < 0)
          {
               sum = 0;
          }
     }
     return maxSum;
}

int maxsubarrayBetterOptimaltoprintsubarray(vector<int> &nums)
{
     int maxSum = INT_MIN;
     int sum = 0;

     int start = 0, end = 0;
     int tempStart = 0; // candidate start index

     for (int i = 0; i < nums.size(); i++)
     {
          sum += nums[i];

          // update best
          if (sum > maxSum)
          {
               maxSum = sum;
               start = tempStart; // final start comes from candidate
               end = i;
          }

          // reset when negative
          if (sum < 0)
          {
               sum = 0;
               tempStart = i + 1; // next element can be new start
          }
     }

     cout << "subarray start: " << start << " end: " << end << endl;
     return maxSum;
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

     cout << maxsubarrayBetter(arr);

     return 0;
}