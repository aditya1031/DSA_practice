// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> foursumBrute(vector<int> &nums, int target) // TC = O(n^4)
{                                                          // SC = O(no.quad)*2
     int count = nums.size();
     set<vector<int>> st;
     for (int i = 0; i < count; i++)
     {
          for (int j = i + 1; j < count; j++)
          {
               for (int k = j + 1; k < count; k++)
               {
                    for (int l = k + 1; l < count; l++)
                    {
                         long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                         if (sum == target)
                         {
                              vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};

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

vector<vector<int>> foursumBetter(vector<int> &nums, int target) // TC = O(n^3*logM)
{                                                           // SC = O(N)+O(quads)*2
     int count = nums.size();
     set<vector<int>> st;

     for (int i = 0; i < count; i++)
     {
          for (int j = i + 1; j < count; j++)
          {
               set<long long> hashset;
               for (int k = j + 1; k < count; k++)
               {
                    long long sum = nums[i] + nums[j] + nums[k];

                    long long fourth = target - (sum);

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
     vector<vector<int>> ans(st.begin(), st.end());
     return ans;
}

vector<vector<int>> foursumBetter(vector<int> &nums, int target) // TC =O(n^2*n)=O(n^3)
{                                                           // SC = O(M)  only to return the ans

     int n = nums.size();
     sort(nums.begin(), nums.end());
     vector<vector<int>> ans;
     for (int i = 0; i < n; i++)
     {
          if (i > 0 && nums[i] == nums[i - 1])
          {
               continue;
          }
          for (int j = i + 1; j < n; j++)
          {
               if (j != i + 1 && nums[j] == nums[j - 1])
               {
                    continue;
               }
               int k = j + 1;
               int l = n - 1;
               while (k < l)
               {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target)
                    {
                         vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                         ans.push_back(temp);
                         k++;
                         l--;
                         while (k < l && nums[k] == nums[k - 1])
                         {
                              k++;
                         }
                         while (k < l && nums[l] == nums[l + 1])
                         {
                              l--;
                         }
                    }
                    else if (sum < k)
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

     int k = 0;
     cin >> k;

     foursumBrute(arr, k);
     return 0;
}