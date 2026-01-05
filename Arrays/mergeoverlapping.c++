#include <bits/stdc++.h>
using namespace std;

// Overall Time Complexity (TC): O(n log n) → sorting dominates
// Overall Space Complexity (SC): O(n) → for answer vector
vector<vector<int>> mergeOverlap_Brute(vector<vector<int>> &nums)
{
     sort(nums.begin(), nums.end());
     int n = nums.size();
     vector<vector<int>> ans;
     for (int i = 0; i < n; i++)
     {
          int start = nums[i][0];
          int end = nums[i][1];
          if (!ans.empty() && end <= ans.back()[1])
          {
               continue;
          }
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

vector<vector<int>> mergeOverlap_Better(vector<vector<int>> &nums)
{
     sort(nums.begin(), nums.end());
     int n = nums.size();
     vector<vector<int>> ans;
     for (int i = 0; i < n; i++)
     {
          if (ans.empty() || nums[i][0] > ans.back()[1])
          {
               ans.push_back(nums[i]);
          }
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

     // Create a 2D vector with n rows
     vector<vector<int>> arr(n, vector<int>(2)); // each interval has 2 elements

     // Take input for each interval
     for (int i = 0; i < n; i++)
     {
          cin >> arr[i][0] >> arr[i][1]; // start and end of interval
     }

     // Call function
     vector<vector<int>> merged = mergeOverlap_Brute(arr);

     // Optional: print result
     for (auto &interval : merged)
     {
          cout << interval[0] << " " << interval[1] << "\n";
     }

     return 0;
}
