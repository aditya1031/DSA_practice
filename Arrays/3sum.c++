// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
 Brute Force Approach (O(n^3))
 - Try all possible triplets (i, j, k)
 - Use a set to avoid duplicate triplets
*/
vector<vector<int>> SumBrute(vector<int> &nums)
{
     int n = nums.size();

     vector<vector<int>> Ans;
     set<vector<int>> st; // to store unique triplets

     for (int i = 0; i < n; i++)
     {
          for (int j = i + 1; j < n; j++)
          {
               for (int k = j + 1; k < n; k++)
               {
                    // check if triplet sum is zero
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                         vector<int> temp = {nums[i], nums[j], nums[k]};
                         sort(temp.begin(), temp.end()); // sort to handle duplicates
                         st.insert(temp);
                    }
               }
          }
     }

     // convert set to vector
     Ans = {st.begin(), st.end()};
     return Ans;
}

/*
 Better Approach using Hashing (O(n^2))
 - Fix one element
 - Use hash set to find the third element
 - Still uses set to remove duplicates
*/
vector<vector<int>> SumBrute(vector<int> &nums)
{
     int n = nums.size();

     vector<vector<int>> Ans;
     set<vector<int>> st;
     int third = 0;

     for (int i = 0; i < n; i++)
     {
          set<int> hashset; // stores visited elements for current i
          for (int j = i + 1; j < n; j++)
          {
               // calculate required third value
               third = -(nums[i] + nums[j]);

               // if third exists, we found a triplet
               if (hashset.find(third) != hashset.end())
               {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
               }

               // insert current element into hashset
               hashset.insert(nums[j]);
          }
     }

     Ans = {st.begin(), st.end()};
     return Ans;
}

/*
 Optimal Two-Pointer Approach (O(n^2))
 - Sort the array
 - Fix one element and use two pointers
 - Skip duplicates explicitly
*/
vector<vector<int>> threeSum(vector<int> &nums)
{
     int n = nums.size();

     sort(nums.begin(), nums.end()); // required for two-pointer approach

     vector<vector<int>> Ans;

     for (int i = 0; i < n; i++)
     {
          // skip duplicate elements
          if (i > 0 && nums[i] == nums[i - 1])
          {
               continue;
          }

          int left = i + 1;
          int right = n - 1;

          while (left < right)
          {
               int sum = nums[i] + nums[left] + nums[right];

               if (sum == 0)
               {
                    // valid triplet found
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    Ans.push_back(temp);

                    left++;
                    right--;

                    // skip duplicates for left pointer
                    while (left < right && nums[left] == nums[left - 1])
                    {
                         left++;
                    }

                    // skip duplicates for right pointer
                    while (left < right && nums[right] == nums[right + 1])
                    {
                         right--;
                    }
               }
               else if (sum < 0)
               {
                    left++; // need larger sum
               }
               else
               {
                    right--; // need smaller sum
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

     // input array
     for (int i = 0; i < n; i++)
     {
          cin >> arr[i];
     }

     // call 3Sum
     vector<vector<int>> ans = threeSum(arr);

     // print triplets
     for (auto &triplet : ans)
     {
          for (int x : triplet)
          {
               cout << x << " ";
          }
          cout << "\n";
     }

     return 0;
}
