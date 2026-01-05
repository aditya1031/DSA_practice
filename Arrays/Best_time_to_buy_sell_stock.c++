// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int profit(vector<int> &nums)
{

     int mini = nums[0];

     int profit = 0;

     for (int i = 1; i < nums.size(); i++)
     {
          int cost = nums[i] - mini;
          profit = max(profit, cost);
          mini = min(mini, nums[i]);
     }
     return profit;
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

     cout  << profit (arr);

     return 0;
}