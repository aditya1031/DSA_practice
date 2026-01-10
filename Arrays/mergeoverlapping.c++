#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Brute Force Merge Overlapping Intervals
TC = O(n log n) + O(n²)
   = O(n²)        // sorting + nested loops
SC = O(n)        // for answer vector
---------------------------------------------------------
*/
vector<vector<int>> mergeOverlap_Brute(vector<vector<int>> &nums)
{
     // Sort intervals based on starting time
     sort(nums.begin(), nums.end());

     int n = nums.size();
     vector<vector<int>> ans;

     for (int i = 0; i < n; i++)
     {
          int start = nums[i][0];
          int end = nums[i][1];

          // If current interval is already covered, skip it
          if (!ans.empty() && end <= ans.back()[1])
          {
               continue;
          }

          // Try to extend the current interval
          for (int j = i + 1; j < n; j++)
          {
               if (nums[j][0] <= end)
               {
                    end = max(end, nums[j][1]);
               }
               else
               {
                    break;
               }
          }

          ans.push_back({start, end});
     }
     return ans;
}

/*
---------------------------------------------------------
Optimal Merge Overlapping Intervals
TC = O(n log n)    // sorting dominates
SC = O(n)         // for answer vector
---------------------------------------------------------
*/
vector<vector<int>> mergeOverlap_Optimal(vector<vector<int>> &nums)
{
     // Sort intervals by start time
     sort(nums.begin(), nums.end());

     int n = nums.size();
     vector<vector<int>> ans;

     for (int i = 0; i < n; i++)
     {
          // If no overlap, push new interval
          if (ans.empty() || nums[i][0] > ans.back()[1])
          {
               ans.push_back(nums[i]);
          }
          // If overlapping, merge with last interval
          else
          {
               ans.back()[1] = max(ans.back()[1], nums[i][1]);
          }
     }
     return ans;
}

int main()
{
     int n;
     cin >> n; // number of intervals

     // Input intervals
     vector<vector<int>> arr(n, vector<int>(2));
     for (int i = 0; i < n; i++)
     {
          cin >> arr[i][0] >> arr[i][1];
     }

     // Using brute method (as in original)
     vector<vector<int>> merged = mergeOverlap_Brute(arr);

     // Print result
     for (auto &interval : merged)
     {
          cout << interval[0] << " " << interval[1] << "\n";
     }

     return 0;
}
