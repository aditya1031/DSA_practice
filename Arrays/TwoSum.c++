// git - aditya1031
#include <bits/stdc++.h>
using namespace std;

/*
----------------------------------------
BRUTE FORCE – TWO SUM
----------------------------------------
Works for:  Positive + Negative
Idea:
- Check all pairs (i, j)

Time Complexity (TC): O(n^2)
Space Complexity (SC): O(1)
*/
vector<int> TwoSum(vector<int> &nums, int T)
{
     int n = nums.size();

     for (int i = 0; i < n; i++)
     {
          for (int j = i + 1; j < n; j++)
          {
               if (nums[i] + nums[j] == T)
               {
                    return {i, j}; // return indices
               }
          }
     }
     return {};
}

/*
----------------------------------------
BETTER – HASHING
----------------------------------------
Works for:  Positive + Negative
Idea:
- Store elements in hashmap
- For each element, check (T - current)

Time Complexity (TC): O(n)
Space Complexity (SC): O(n)
*/
vector<int> TwoSum_better(vector<int> &nums, int T)
{
     unordered_map<int, int> mpp; // value -> index

     for (int i = 0; i < nums.size(); i++)
     {
          int req = T - nums[i];

          if (mpp.find(req) != mpp.end())
          {
               return {mpp[req], i};
          }

          mpp[nums[i]] = i;
     }
     return {};
}

/*
----------------------------------------
TWO POINTER – EXISTENCE CHECK
----------------------------------------
Works for: SORTED ARRAY ONLY
Returns: true / false (not indices)

Time Complexity (TC): O(n)
Space Complexity (SC): O(1)
*/
bool TwoSum_Tocheck(vector<int> &nums, int T)
{
     int left = 0;
     int right = nums.size() - 1;

     while (left < right)
     {
          int sum = nums[left] + nums[right];

          if (sum == T)
          {
               return true;
          }
          else if (sum > T)
          {
               right--;
          }
          else
          {
               left++;
          }
     }
     return false;
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

    int T;
    cin >> T;

    // Using hashing (best approach)
    vector<int> ans = TwoSum_better(arr, T);

    if (!ans.empty())
    {
        cout << ans[0] << " " << ans[1];
    }
    else
    {
        cout << "No pair found";
    }

    return 0;
}
