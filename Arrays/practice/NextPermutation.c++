// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
STL Based Next Permutation
-------------------------------------------------------

Idea:
- Uses C++ STL `next_permutation`
- Rearranges the array into the next lexicographically
  greater permutation
- If no next permutation exists, it returns the smallest one

Time Complexity: O(n)
Space Complexity: O(1)
-------------------------------------------------------
*/
void nextPermutation(vector<int> &nums)
{
     next_permutation(nums.begin(), nums.end());
}

/*
-------------------------------------------------------
Brute Force Approach (Learning Only)
-------------------------------------------------------

Idea:
- Store the original permutation
- Generate all permutations in sorted order
- Find the original permutation
- Return the next one (or first if original was last)

Important:
- Extremely slow for large n (n! permutations)
- NOT suitable for interviews or submissions

Time Complexity: O(n! * n)
Space Complexity: O(n! * n)
-------------------------------------------------------
*/
void nextPermutationBrute(vector<int> &nums)
{
     int n = nums.size();          // size of array (not strictly required)
     vector<int> OG = nums;        // store original permutation
     vector<vector<int>> perAll;   // store all permutations

     // Generate all permutations in sorted order
     sort(nums.begin(), nums.end());
     do
     {
          perAll.push_back(nums);
     } while (next_permutation(nums.begin(), nums.end()));

     // Find original permutation and set next
     for (int i = 0; i < perAll.size(); i++)
     {
          if (perAll[i] == OG)
          {
               if (i == perAll.size() - 1)
               {
                    nums = perAll[0];   // last permutation → first
               }
               else
               {
                    nums = perAll[i + 1];
                    break;
               }
          }
     }
}

/*
-------------------------------------------------------
Optimal Approach (Interview Standard)
-------------------------------------------------------

Intuition:
- Find the first decreasing element from the right (pivot)
- Swap it with the smallest element greater than it on the right
- Reverse the suffix to get the smallest next permutation

Steps:
1. Find pivot index
2. Handle descending case (no pivot)
3. Swap pivot with next greater element
4. Reverse the right half

Time Complexity: O(n)
Space Complexity: O(1)
-------------------------------------------------------
*/
void nextPermutationOptimal(vector<int> &nums)
{
     int n = nums.size();
     int pivot = -1;

     // Step 1: Find pivot
     for (int i = n - 2; i >= 0; i--)
     {
          if (nums[i] < nums[i + 1])
          {
               pivot = i;
               break;
          }
     }

     // Step 2: If no pivot, reverse entire array
     if (pivot == -1)
     {
          reverse(nums.begin(), nums.end());
          return;
     }

     // Step 3: Find just greater element and swap
     for (int i = n - 1; i > pivot; i--)
     {
          if (nums[i] > nums[pivot])
          {
               swap(nums[pivot], nums[i]);
               break;
          }
     }

     // Step 4: Reverse suffix
     reverse(nums.begin() + pivot + 1, nums.end());
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

     // Example usage:
     // nextPermutationOptimal(arr);

     for (int i = 0; i < n; i++)
     {
          cout << arr[i] << " ";
     }

     return 0;
}
