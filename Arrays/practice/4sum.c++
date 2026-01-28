// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Brute Force 4-Sum
TC = O(n^4)
SC = O(2 * Q)
Q = number of unique quadruplets
---------------------------------------------------------
*/
vector<vector<int>> foursumBrute(vector<int> &nums, int target)
{
     int count = nums.size();
     set<vector<int>> st; // store unique quadruplets

     for (int i = 0; i < count; i++)
     {
          for (int j = i + 1; j < count; j++)
          {
               for (int k = j + 1; k < count; k++)
               {
                    for (int l = k + 1; l < count; l++)
                    {
                         long long sum =
                             (long long)nums[i] + nums[j] + nums[k] + nums[l];

                         if (sum == target)
                         {
                              vector<int> temp =
                                  {nums[i], nums[j], nums[k], nums[l]};
                              sort(temp.begin(), temp.end());
                              st.insert(temp);
                         }
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
TC = O(n^3 * logM)
SC = O(N) + O(2 * Q)
---------------------------------------------------------
*/
vector<vector<int>> foursumBetter(vector<int> &nums, int target)
{
     int count = nums.size();
     set<vector<int>> st;

     for (int i = 0; i < count; i++)
     {
          for (int j = i + 1; j < count; j++)
          {
               set<long long> hashset; // stores visited nums[k]

               for (int k = j + 1; k < count; k++)
               {
                    long long sum =
                        (long long)nums[i] + nums[j] + nums[k];

                    long long fourth = target - sum;

                    if (hashset.find(fourth) != hashset.end())
                    {
                         vector<int> temp =
                             {nums[i], nums[j], nums[k], (int)fourth};
                         sort(temp.begin(), temp.end());
                         st.insert(temp);
                    }

                    hashset.insert(nums[k]);
               }
          }
     }

     vector<vector<int>> ans(st.begin(), st.end());
     return ans;
}

/*
---------------------------------------------------------
Optimal Approach (Sorting + Two Pointers)
TC = O(n^3)
SC = O(M)   [only to store answer]
---------------------------------------------------------
*/
vector<vector<int>> foursumOptimal(vector<int> &nums, int target)
{
     int n = nums.size();
     sort(nums.begin(), nums.end());
     vector<vector<int>> ans;

     for (int i = 0; i < n; i++)
     {
          // skip duplicate first element
          if (i > 0 && nums[i] == nums[i - 1])
               continue;

          for (int j = i + 1; j < n; j++)
          {
               // skip duplicate second element
               if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;

               int k = j + 1;
               int l = n - 1;

               while (k < l)
               {
                    long long sum =
                        (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target)
                    {
                         ans.push_back(
                             {nums[i], nums[j], nums[k], nums[l]});
                         k++;
                         l--;

                         // skip duplicate third element
                         while (k < l && nums[k] == nums[k - 1])
                              k++;

                         // skip duplicate fourth element
                         while (k < l && nums[l] == nums[l + 1])
                              l--;
                    }
                    else if (sum < target)
                    {
                         k++;
                    }
                    else
                    {
                         l--;
                    }
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

     int k;
     cin >> k;
vector<vector<int>> res = foursumOptimal(arr, k);

for (auto &quad : res)
{
     for (int x : quad)
     {
          cout << x << " ";
     }
     cout << endl;
}

     return 0;
}
