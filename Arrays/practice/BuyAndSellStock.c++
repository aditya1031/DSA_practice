// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Best Time to Buy and Sell Stock (LeetCode 121)
-------------------------------------------------------

Intuition:
- We want to buy at the lowest price seen so far
- On each day, assume we sell today and calculate profit
- Keep track of the maximum profit obtained

Thought Process:
1. Maintain `mini` = minimum price seen so far
2. For each day:
   - Compute profit if sold today → prices[i] - mini
   - Update maximum profit
   - Update minimum price if current price is smaller

Time Complexity: O(n)
Space Complexity: O(1)
-------------------------------------------------------
*/
int maxProfit(vector<int> &prices)
{
     int n = prices.size();
     int mini = prices[0];   // minimum price so far
     int profit = 0;         // maximum profit

     for (int i = 1; i < n; i++)
     {
          int cost = prices[i] - mini; // profit if sold today
          profit = max(profit, cost);  // update best profit
          mini = min(mini, prices[i]); // update minimum price
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

     // To get result:
      cout << maxProfit(arr);

     return 0;
}
