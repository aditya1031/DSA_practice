// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int sqrtBrute(int x)
{
     int ans = 1;
     for (int i = 1; i <= x; i++)
     {
          int sq = i * i;
          if (sq <= x)
          {
               ans = i;
          }
          else
          {
               break;
          }
     }

     return ans;
}

int sqrtOptimal(int x)
{
     if (x == 0)
          return 0;
          
     int ans = 1;
     int low = 1;
     int high = x;
     while (low <= high)
     {
          long long mid = low + (high - low) / 2;
          if (mid * mid <= x)
          {
               ans = mid;
               low = mid + 1;
          }
          else 
          {
               high = mid - 1;
          }
     }

     return ans;
}

int main()
{
     // cout << sqrtBrute(28);
     cout << sqrtOptimal(28);
     return 0;
}