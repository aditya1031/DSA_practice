// git - aditya1031
// Count number of subarrays with XOR = k

#include <bits/stdc++.h>
using namespace std;

/*
 Brute Force Approach
 --------------------
 Idea:
 - Fix starting index i
 - Compute XOR for all subarrays starting at i
 - If XOR == k, increase count

 Time Complexity: O(n^2)
 Space Complexity: O(1)
*/
int XOR_Brute(vector<int> nums, int k)
{
     int n = nums.size();
     int ans = 0;

     for (int i = 0; i < n; i++)
     {
          int XOR = 0;                 // reset XOR for each start index
          for (int j = i; j < n; j++)
          {
               XOR = XOR ^ nums[j];    // cumulative XOR
               if (XOR == k)
               {
                    ans++;
               }
          }
     }
     return ans;
}

/*
 Optimal Approach (Prefix XOR + Hashing)
 -------------------------------------
 Idea:
 - Maintain prefix XOR till index i
 - If (prefixXOR ^ k) appeared before,
   then a subarray with XOR = k exists
 - Use hashmap to store frequency of prefix XORs

 Time Complexity: O(n)
 Space Complexity: O(n)
*/
int XOR_Optimal(vector<int> nums, int k)
{
     int n = nums.size();
     int ans = 0;
     int XOR = 0;

     unordered_map<int, int> mpp;
     mpp[0] = 1;   // handles subarrays starting from index 0

     for (int i = 0; i < n; i++)
     {
          XOR = XOR ^ nums[i];        // prefix XOR
          int req = XOR ^ k;          // required previous XOR
          ans += mpp[req];            // add count if exists
          mpp[XOR]++;                 // store current XOR
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
     cout << "enter the target K: ";
     cin >> k;

     // cout << XOR_Brute(arr, k);
     cout << XOR_Optimal(arr, k);

     return 0;
}
