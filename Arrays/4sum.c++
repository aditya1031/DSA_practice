// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
 Brute Force 4Sum
 TC: O(n^4)
 SC: O(k)  (k = number of unique quadruplets)
*/
vector<vector<int>> sumBrute(vector<int> &nums, int target)
{
     int n = nums.size();
     vector<vector<int>> Ans;
     set<vector<int>> st;

     for (int i = 0; i < n; i++)
     {
          for (int j = i + 1; j < n; j++)
          {
               for (int k = j + 1; k < n; k++)
               {
                    for (int l = k + 1; l < n; l++)
                    {
                         if ((long long)nums[i] + nums[j] + nums[k] + nums[l] == target)
                         {
                              vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                              sort(temp.begin(), temp.end());
                              st.insert(temp);
                         }
                    }
               }
          }
     }

     Ans = {st.begin(), st.end()};
     return Ans;
}

/*
 Better 4Sum using Hashing
 TC: O(n^3)
 SC: O(n + k)
*/
vector<vector<int>> sumBetter(vector<int> &nums, int target)
{
     int n = nums.size();
     vector<vector<int>> Ans;
     set<vector<int>> st;

     for (int i = 0; i < n; i++)
     {
          for (int j = i + 1; j < n; j++)
          {
               set<int> hashset;
               for (int k = j + 1; k < n; k++)
               {
                    long long fourth = target - ((long long)nums[i] + nums[j] + nums[k]);

                    if (hashset.find(fourth) != hashset.end())
                    {
                         vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                         sort(temp.begin(), temp.end());
                         st.insert(temp);
                    }

                    hashset.insert(nums[k]);
               }
          }
     }

     Ans = {st.begin(), st.end()};
     return Ans;
}

/*
 Optimal 4Sum (Sorting + Two Pointers)
 TC: O(n^3)
 SC: O(1)  (excluding output)
*/
vector<vector<int>> sumOptimal(vector<int> &nums, int target)
{
     int n = nums.size();
     vector<vector<int>> Ans;
     sort(nums.begin(), nums.end());

     for (int i = 0; i < n; i++)
     {
          if (i > 0 && nums[i] == nums[i - 1]) continue;

          for (int j = i + 1; j < n; j++)
          {
               if (j > i + 1 && nums[j] == nums[j - 1]) continue;

               int left = j + 1;
               int right = n - 1;

               while (left < right)
               {
                    long long sum =
                         (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target)
                    {
                         Ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                         left++;
                         right--;

                         while (left < right && nums[left] == nums[left - 1]) left++;
                         while (left < right && nums[right] == nums[right + 1]) right--;
                    }
                    else if (sum < target)
                    {
                         left++;
                    }
                    else
                    {
                         right--;
                    }
               }
          }
     }

     return Ans;
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

     int target;
     cin >> target;

     // choose which method you want
     vector<vector<int>> ans = sumOptimal(arr, target);

     // print result
     for (auto &quad : ans)
     {
          for (int x : quad)
          {
               cout << x << " ";
          }
          cout << "\n";
     }

     return 0;
}
