// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

// BRUTE
void twosum(vector<int> &nums, int k) // O(n2)
{
     int n = nums.size();

     for (int i = 0; i < n; i++)
     {
          for (int j = i + 1; j < n; j++)
          {

               if ((nums[i] + nums[j]) == k)
               {
                    cout << "yes two sum exits at " << i << " : " << j;
               }
          }
     }
}


// BETTER
void twosum2(vector<int> &nums, int k) // ---------------------------------------------------
// BETTER — USING HASHMAP
// TC: O(n), SC: O(n)
// ---------------------------------------------------
{
     int n = nums.size();
     unordered_map<int, int> mpp;
     for (int i = 0; i < n; i++)
     {
          int S = k - nums[i];

          if (mpp.find(S) != mpp.end())
          {
               cout << "yes two sum exits at " << i << " " << mpp[S];
               // return {mpp[S], i};
          }
          mpp[nums[i]] = i;
     }
}


// OPTIMAL
void twosum3(vector<int> &nums, int k) // ---------------------------------------------------
// OPTIMAL (YES/NO check ONLY)
// TWO POINTER after sorting
// TC: O(n log n), SC: O(1)
// ---------------------------------------------------
{
     int n = nums.size();
     int j = n - 1;
     int i = 0;

     sort(nums.begin(), nums.end());
     while (i < j)
     {
          int sum = nums[i] + nums[j];
          if (sum == k)
          {
               cout << "yes two sum exits";
               break;
          }
          if (sum > k)
          {
               j--;
          }
          else
          {
               i++;
          }
     }
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

     twosum3(arr, k);
     return 0;
}