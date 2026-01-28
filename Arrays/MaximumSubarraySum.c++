#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
-------------------------------------------------------
Brute Force Approach
-------------------------------------------------------
Idea:
- Generate all possible subarrays
- Compute sum for each subarray
- Track the maximum sum

Time Complexity: O(n^3)
Space Complexity: O(1)
-------------------------------------------------------
*/
int maxSubArrayBrute(vector<int> &nums)
{
     int n = nums.size();

     int maxx = INT_MIN;   // stores maximum subarray sum found so far

     // starting index of subarray
     for (int i = 0; i < n; i++)
     {
          // ending index of subarray
          for (int j = i; j < n; j++)
          {
               int sum = 0;

               // calculate sum of subarray [i ... j]
               for (int k = i; k <= j; k++)
               {
                    sum += nums[k];
               }

               // update maximum sum
               maxx = max(maxx, sum);
          }
     }
     return maxx;
}

/*
-------------------------------------------------------
Better (Optimized Brute Force) Approach
-------------------------------------------------------
Idea:
- Fix starting index
- Extend subarray to the right
- Reuse previous sum instead of recalculating

Time Complexity: O(n^2)
Space Complexity: O(1)
-------------------------------------------------------
*/
int maxSubArrayBetter(vector<int> &nums)
{
     int n = nums.size();

     int maxx = INT_MIN;

     // starting index of subarray
     for (int i = 0; i < n; i++)
     {
          int sum = 0;   // cumulative sum from index i

          // ending index of subarray
          for (int j = i; j < n; j++)
          {
               sum += nums[j];     // extend subarray
               maxx = max(maxx, sum);
          }
     }
     return maxx;
}

/*
-------------------------------------------------------
Optimal Approach (Kadane's Algorithm)
-------------------------------------------------------

Intuition (simple & exam-ready):

- We traverse the array from left to right while maintaining a running sum.
- At each index, we decide:
  "Is it better to extend the previous subarray
   or start a new subarray from this element?"

Core Idea:
- A negative sum will only reduce the sum of any future subarray.
- Hence, if the current sum becomes negative, we discard it
  and start fresh from the next element.

Thought Process:
1. Add the current element to the running sum.
2. Update the maximum subarray sum seen so far.
3. If the running sum becomes negative, reset it to 0.

One-Line Intuition (Interview Gold ⭐):
- A negative prefix never helps in forming a maximum subarray.

Time Complexity: O(n)
Space Complexity: O(1)
-------------------------------------------------------
*/
int maxSubArrayOptimal(vector<int> &nums)
{
     int n = nums.size();

     int maxx = INT_MIN;   // stores maximum subarray sum
     int sum = 0;          // current subarray sum

     for (int i = 0; i < n; i++)
     {
          sum += nums[i];          // extend subarray
          maxx = max(maxx, sum);   // update best answer

          // if sum becomes negative, drop the subarray
          if (sum < 0)
          {
               sum = 0;
          }
     }
     return maxx;
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

     // Functions can be called here if needed
     cout << maxSubArrayOptimal(arr);

     return 0;
}
