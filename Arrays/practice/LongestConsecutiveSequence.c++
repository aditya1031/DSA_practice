// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

bool linearsearch(vector<int> &nums, int val)
{
     for (int i = 0; i < nums.size(); i++)
     {
          if (nums[i] == val)
          {
               return true;
          }
     }
     return false;
}

int sequensceBrute(vector<int> &nums) // TC - O(n^2)
{
     int longest = 1;
     for (int i = 0; i < nums.size(); i++)
     {
          int x = nums[i];
          int count = 1;

          while (linearsearch(nums, x + 1))
          {
               x++;
               count++;
          }

          longest = max(longest, count);
     }
     return longest;
}

int sequensceBetter(vector<int> &nums) // TC - O(nlogn)
{
     if (nums.empty())
          return 0;
     sort(nums.begin(), nums.end());

     int lastSmaller = INT_MIN;
     int longest = 1;
     int currCnt = 1;
     for (int i = 0; i < nums.size(); i++)
     {
          if ((nums[i] - 1) == lastSmaller)
          {
               currCnt++;
               lastSmaller = nums[i];
          }
          else if (lastSmaller != nums[i])
          {
               currCnt = 1;
               lastSmaller = nums[i];
          }

          longest = max(longest, currCnt);
     }

     return longest;
}

int sequensceOptimal(vector<int> &nums) // Time Complexity: O(n) (average case) o(n*n)
// Space Complexity: O(n)
{
     if (nums.empty())
          return 0;
     int longest = 1;
     unordered_set<int> st;
     for (int i = 0; i < nums.size(); i++)
     {
          st.insert(nums[i]);
     }

     for (auto it : st)
     {
          if (st.find(it - 1) == st.end())
          {
               int cnt = 1;
               int x = it;

               while (st.find(x + 1) != st.end())
               {
                    x++;
                    cnt++;
               }
               longest = max(longest, cnt);
          }
     }
     return longest;
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

     (arr);

     for (int i = 0; i < n; i++)
     {
          cout << arr[i] << " ";
     }
     cout << endl;

     return 0;
}