// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

// Brute force generates all permutations → O(n!) time → not feasible for n > 10.

vector<int> nextPermutation(vector<int> &nums)
{
     // Store all permutations
     vector<vector<int>> all;

     // Generate all permutations
     sort(nums.begin(), nums.end());
     do
     {
          all.push_back(nums);
     } while (next_permutation(nums.begin(), nums.end()));

     // Traverse the list to find current permutation
     for (int i = 0; i < all.size(); i++)
     {
          if (all[i] == nums)
          {
               // If it's the last permutation
               if (i == all.size() - 1)
                    return all[0];
               // Return the next one
               return all[i + 1];
          }
     }

     // Return original if not found (shouldn't happen)
     return nums;
}

// Uses C++ STL next_permutation (O(n) time)
// Only works in C++ because of STL support
vector<int> nextPermutationBetter(vector<int> &nums)
{
     next_permutation(nums.begin(), nums.end());
     return nums;
}

vector<int> nextPermutationOptimal(vector<int> &nums) // TC- O(n)  sc -O(1)
{

     int n = nums.size();
     int ind = -1;
     for (int i = n - 2; i >= 0; i--)
     {
          if (nums[i] < nums[i + 1])
          {
               ind = i;
               break;
          }
     }

     if (ind == -1)
     {
          reverse(nums.begin(), nums.end());
          return nums;
     }

     for (int i = n - 1; i > 0; i--)
     {
          if (nums[i] > nums[ind])
          {
               swap(nums[i], nums[ind]);
               break;
          }
     }

     reverse(nums.begin() + ind + 1, nums.end());

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

     nextPermutationOptimal(arr);

     for (int i = 0; i < n; i++)
     {
          cout << arr[i] << " ";
     }
     cout << endl;

     return 0;
}