// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Brute Force Approach
TC = O(n^3 * logM)
SC = O(2*M)
M = number of unique triplets
---------------------------------------------------------
*/
vector<vector<int>> sumBrute1(vector<int> &nums)
{
     int n = nums.size();
     set<vector<int>> st; // to store unique triplets

     for (int i = 0; i < n; i++)
     {
          for (int j = i + 1; j < n; j++)
          {
               for (int k = j + 1; k < n; k++)
               {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                         vector<int> temp = {nums[i], nums[j], nums[k]};
                         sort(temp.begin(), temp.end()); // avoid duplicates
                         st.insert(temp);
                    }
               }
          }
     }

     vector<vector<int>> ans(st.begin(), st.end());
     return ans;
}

/*
---------------------------------------------------------
Better Approach (Hashing)
TC = O(n^2 * logM)
SC = O(2N) + O(M)
---------------------------------------------------------
*/
vector<vector<int>> sumBrute2(vector<int> &nums)
{
     int n = nums.size();
     set<vector<int>> st;

     for (int i = 0; i < n; i++)
     {
          set<int> hashset; // stores visited elements for current i

          for (int j = i + 1; j < n; j++)
          {
               int third = 0 - (nums[i] + nums[j]);

               if (hashset.find(third) != hashset.end())
               {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
               }

               hashset.insert(nums[j]);
          }
     }

     vector<vector<int>> ans(st.begin(), st.end());
     return ans;
}

/*
---------------------------------------------------------
Optimal Approach (Sorting + Two Pointers)
TC = O(n^2)
SC = O(1)  [excluding answer]
---------------------------------------------------------
*/
vector<vector<int>> sumOptimal(vector<int> &nums)
{
     int n = nums.size();
     sort(nums.begin(), nums.end());
     vector<vector<int>> ans;

     for (int i = 0; i < n; i++)
     {
          // skip duplicate first element
          if (i > 0 && nums[i] == nums[i - 1])
               continue;

          int j = i + 1;
          int k = n - 1;

          while (j < k)
          {
               long long sum = 1LL * nums[i] + nums[j] + nums[k]; // overflow safe

               if (sum < 0)
                    j++;
               else if (sum > 0)
                    k--;
               else
               {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // skip duplicate second element
                    while (j < k && nums[j] == nums[j - 1])
                         j++;

                    // skip duplicate third element
                    while (j < k && nums[k] == nums[k + 1])
                         k--;
               }
          }
     }
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

    
     sumBrute1(arr); // function call (result not printed)
     return 0;
}
