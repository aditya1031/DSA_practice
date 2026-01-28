// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Brute Force Approach – Leaders in an Array
-------------------------------------------------------

Idea:
- For each element, check all elements to its right
- If no element on the right is greater, it is a leader

Time Complexity: O(n^2)
Space Complexity: O(n)   // for storing leaders
-------------------------------------------------------
*/
vector<int> leaderBrute(vector<int> &nums)
{
     int n = nums.size();
     vector<int> ans;

     // Pick each element
     for (int i = 0; i < n; i++)
     {
          bool flg = true;

          // Check elements to the right
          for (int j = i + 1; j < n; j++)
          {
               if (nums[i] < nums[j])
               {
                    flg = false;
               }
          }

          // If no greater element found on right
          if (flg == true)
          {
               ans.push_back(nums[i]);
          }
     }
     return ans;
}

/*
-------------------------------------------------------
Optimal Approach – Leaders in an Array
-------------------------------------------------------

Intuition:
- Traverse array from right to left
- Keep track of the maximum element seen so far
- If current element is greater than max, it is a leader

Steps:
1. Last element is always a leader
2. Move from right → left
3. Update maximum and store leaders
4. Reverse result to maintain original order

Time Complexity: O(n)
Space Complexity: O(1) extra (excluding output)
-------------------------------------------------------
*/
vector<int> leaderOptimal(vector<int> &nums)
{
     int n = nums.size();
     vector<int> ans;

     // Last element is always a leader
     int largest = nums[n - 1];
     ans.push_back(largest);

     // Traverse from right to left
     for (int i = n - 2; i >= 0; i--)
     {
          if (nums[i] > largest)
          {
               ans.push_back(nums[i]);
               largest = nums[i];
          }
     }

     // Reverse to restore left-to-right order
     reverse(ans.begin(), ans.end());

     return ans;
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

     // Example usage:
     // vector<int> leaders = leaderOptimal(arr);

     for (int i = 0; i < n; i++)
     {
          cout << arr[i] << " ";
     }

     return 0;
}
