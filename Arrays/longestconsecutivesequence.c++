// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
Linear Search
TC: O(n)  -> checks all elements
SC: O(1)  -> no extra space
*/
bool linearSearch(vector<int> &a, int num)
{
     int n = a.size();
     for (int i = 0; i < n; i++)
     {
          if (a[i] == num)
          {
               return true;
          }
     }
     return false;
}

/*
Brute Force Approach
For each element, keep checking next consecutive numbers using linear search.

TC:
- Outer loop: O(n)
- Inner while loop with linearSearch: O(n)
=> Overall TC: O(n^2)

SC:
- No extra data structure used
=> O(1)
*/
int longestConsecutiveBrute(vector<int> &nums)
{
     int n = nums.size();
     int maxlen = 0;

     for (int i = 1; i < n; i++)
     {
          int x = nums[i];
          int cnt = 1;

          // keep checking if next consecutive number exists
          while (linearSearch(nums, x + 1))
          {
               cnt++;
               x++;
          }
          maxlen = max(maxlen, cnt);
     }
     return maxlen;
}

/*
Better Approach (Sorting)
Steps:
1. Sort the array
2. Count consecutive increasing elements

TC:
- Sorting: O(n log n)
- Single traversal: O(n)
=> Overall TC: O(n log n)

SC:
- Sorting uses extra space (depends on implementation)
=> O(1) to O(n)
*/
int longestConsecutiveBetter(vector<int> &nums)
{
     int n = nums.size();
     if (n == 0)
          return 0;

     sort(nums.begin(), nums.end());

     int lastSmaller = INT_MIN;
     int maxlen = 1;
     int cnt = 1;

     for (int i = 0; i < n; i++)
     {
          if (nums[i] - 1 == lastSmaller)
          {
               cnt++;
               lastSmaller = nums[i];
          }
          else if (nums[i] != lastSmaller) // handles duplicates
          {
               cnt = 1;
               lastSmaller = nums[i];
          }
          maxlen = max(maxlen, cnt);
     }
     return maxlen;
}

/*
Optimal Approach (Using Hash Set)
Idea:
- Insert all elements into a set
- Start counting only if current element is the start of a sequence

TC:
- Insertion in set: O(n)
- Each element processed once in while loop
=> Overall TC: O(n)

SC:
- Unordered set stores all elements
=> O(n)
*/
int longestConsecutiveOptimal(vector<int> &nums)
{
     int n = nums.size();
     if (n == 0)
          return 0;

     unordered_set<int> st;

     for (int i = 0; i < n; i++)
          st.insert(nums[i]);

     int maxlen = 1;

     for (auto it : st)
     {
          // check if it is the start of a sequence
          if (st.find(it - 1) == st.end())
          {
               int cnt = 1;
               int x = it;

               while (st.find(x + 1) != st.end())
               {
                    cnt++;
                    x++;
               }
               maxlen = max(maxlen, cnt);
          }
     }
     return maxlen;
}

int main()
{
     vector<int> a = {100, 4, 200, 1, 3, 2};

     int ans = longestConsecutiveBetter(a);
     cout << "The longest consecutive sequence is " << ans << "\n";

     return 0;
}
