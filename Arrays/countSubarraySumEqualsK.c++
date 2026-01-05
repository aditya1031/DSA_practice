// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int NoSubarrayBrute(vector<int> &nums, int num)
{
     int count = 0;
     for (int i = 0; i < nums.size(); i++)
     {
          for (int j = i; j < nums.size(); j++)
          {
               int sum = 0;
               for (int k = i; k <= j; k++)
               {
                    sum = sum + nums[k];
               }
               if (sum == num)
               {
                    count++;
               }
          }
     }
     return count;
}

int NoSubarrayBetter(vector<int> &nums, int num)
{
     int count = 0;
     for (int i = 0; i < nums.size(); i++)
     {
          int sum = 0;
          for (int j = i; j < nums.size(); j++)
          {
               sum = sum + nums[j];
               if (sum == num)
               {
                    count++;
               }
          }
     }
     return count;
}

int NoSubarrayOptimal(vector<int> &nums, int num) /* Time Complexity:O(N) 
unordered_map average insert/find = O(1)
Worst-case TC: O(N²) (hash collisions, rare)*/
// SC: O(N)

{

     int presum = 0;
     int count = 0;
     unordered_map<int, int> mpp;
     mpp[0] = 1;
     for (int i = 0; i < nums.size(); i++)
     {
          presum += nums[i];
          int rem = presum - num;
          count += mpp[rem];
          mpp[presum]++;
     }
     return count;
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

     cout << " number is " << NoSubarrayBetter(arr, k);
     return 0;
}