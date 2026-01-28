#include <bits/stdc++.h>

using namespace std;

int subarrayBrute(vector<int> &nums, int k) // Time Complexity: O(n³) → three nested loops
// Space Complexity: O(1) → no extra space used
{
     int n = nums.size();
     int cnt = 0;
     for (int i = 0; i < n; i++)
     {
          for (int j = i; j < n; j++)
          {
               int XOR = 0;
               for (int p = i; p <= j; p++)
               {
                    XOR = XOR ^ nums[p];
               }
               if (XOR == k)
               {
                    cnt++;
               }
          }
     }

     return cnt;
}

int subarrayBetter(vector<int> &nums, int k)
// Time Complexity: O(n²) → two nested loops
// Space Complexity: O(1) → only variables used, no extra data structures
{
     int n = nums.size();
     int cnt = 0;
     for (int i = 0; i < n; i++)
     {
          int XOR = 0;
          for (int j = i; j < n; j++)
          {

               XOR = XOR ^ nums[j];

               if (XOR ==  k)
               {
                    cnt++;
               }
          }
     }

     return cnt;
}

int subarrayOptimal(vector<int> &nums, int k)   //tc = O(n)   ,sc O(n)
{
     int n = nums.size();
     int cnt = 0;
     unordered_map <int ,int> mpp;
     int xr=0;
     mpp[xr]++;

     for (int i = 0; i < n; i++)
     {
          xr=xr^nums[i];
          int x=xr^k;
          cnt+=mpp[x];
          mpp[xr]++;
     }
     return cnt;
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
     subarrayBrute(arr, k);

     return 0;
}