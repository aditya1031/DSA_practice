// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Brute Approach (Assumes equal positives & negatives)
-------------------------------------------------------

Idea:
- First separate positives and negatives
- Then place them alternately at even & odd indices

Important:
- Works ONLY when number of positives == number of negatives
- Otherwise may cause out-of-bounds access

Time Complexity: O(n)
Space Complexity: O(n)   // extra arrays tpos, tneg
-------------------------------------------------------
*/
vector<int> rearrangeArrayBrute(vector<int> &nums)
{
     int n = nums.size();
     vector<int> tpos;
     vector<int> tneg;

     // Separate positives and negatives
     for (int i = 0; i < n; i++)
     {
          if (nums[i] > 0)
          {
               tpos.push_back(nums[i]);
          }
          else
          {
               tneg.push_back(nums[i]);
          }
     }

     // Place alternately (assumes equal count)
     for (int i = 0; i < n / 2; i++)
     {
          nums[2 * i] = tpos[i];
          nums[2 * i + 1] = tneg[i];
     }

     return nums;
}

/*
-------------------------------------------------------
Optimal Approach (Equal positives & negatives)
-------------------------------------------------------

Idea:
- Positives go to even indices (0,2,4,...)
- Negatives go to odd indices (1,3,5,...)
- Uses direct indexing instead of extra arrays

Important:
- Works ONLY when positives == negatives

Time Complexity: O(n)
Space Complexity: O(n)   // uses extra answer array
-------------------------------------------------------
*/
vector<int> rearrangeArrayOptimal(vector<int> &nums)
{
     int n = nums.size();
     int pos = 0;   // even index
     int neg = 1;   // odd index

     vector<int> ans(n, 0);

     for (int i = 0; i < n; i++)
     {
          if (nums[i] > 0)
          {
               ans[pos] = nums[i];
               pos = pos + 2;
          }
          else
          {
               ans[neg] = nums[i];
               neg = neg + 2;
          }
     }
     return ans;
}

/*
-------------------------------------------------------
General Solution (Handles unequal positives & negatives)
-------------------------------------------------------

Idea:
- Separate positives and negatives
- Place alternately while both exist
- Append remaining elements at the end

Works for:
- Equal count
- Unequal count (safe & general)

Time Complexity: O(n)
Space Complexity: O(n)
-------------------------------------------------------
*/
vector<int> rearrangeArray(vector<int> &nums)
{
     vector<int> tpos;
     vector<int> tneg;

     // Separate positives and negatives
     for (int x : nums)
     {
          if (x > 0)
          {
               tpos.push_back(x);
          }
          else
          {
               tneg.push_back(x);
          }
     }

     int p = 0; // index for positives
     int n = 0; // index for negatives
     int i = 0; // index for original array

     // Place alternately
     while (p < tpos.size() && n < tneg.size())
     {
          nums[i++] = tpos[p++];
          nums[i++] = tneg[n++];
     }

     // Append remaining negatives
     while (n < tneg.size())
     {
          nums[i++] = tneg[n++];
     }

     // Append remaining positives
     while (p < tpos.size())
     {
          nums[i++] = tpos[p++];
     }

     return nums;
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

     
     arr = rearrangeArrayOptimal(arr);

     for (int i = 0; i < n; i++)
     {
          cout << arr[i] << " ";
     }

     return 0;
}
