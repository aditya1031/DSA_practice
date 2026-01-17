// git - aditya1031
#include <bits/stdc++.h>
using namespace std;

/*
 Brute Force Approach
 Idea:
 - For every element, count its frequency by scanning the whole array.
 - The element with frequency = 1 is the answer.

 Time Complexity (TC): O(n^2)
 Space Complexity (SC): O(1)
*/
int SingleNumberBrute(vector<int> &nums)
{
     int n = nums.size();
     int ans = 0;

     for (int i = 0; i < n; i++)
     {
          int cnt = 0;
          for (int j = 0; j < n; j++)
          {
               if (nums[i] == nums[j])
               {
                    cnt++;
               }
          }
          if (cnt == 1)
          {
               ans = nums[i];
               break;
          }
     }
     return ans;
}

/*
 Better Approach (Hashing)
 Idea:
 - Store frequency of each element using unordered_map.
 - Return the element with frequency = 1.

 Time Complexity (TC): O(n)
 Space Complexity (SC): O(n)
*/
int SingleNumberBetter(vector<int> &nums)
{
     unordered_map<int, int> mpp;

     for (int i = 0; i < nums.size(); i++)
     {
          mpp[nums[i]]++;
     }

     for (auto it : mpp)
     {
          if (it.second == 1)
          {
               return it.first;
          }
     }
     return -1;
}

/*
 Optimal Approach (XOR)
 Idea:
 - XOR of same numbers is 0.
 - XOR with 0 gives the number itself.
 - All paired elements cancel out, leaving the single number.

 Time Complexity (TC): O(n)
 Space Complexity (SC): O(1)
*/
int SingleNumberOptimal(vector<int> &nums)
{
     int XOR = 0;
     for (auto x : nums)
     {
          XOR ^= x;
     }
     return XOR;
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

     //cout << SingleNumberBrute(arr);
     //cout << SingleNumberBetter(arr);
     cout << SingleNumberOptimal(arr);
     
     return 0;
}
