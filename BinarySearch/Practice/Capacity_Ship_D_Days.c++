// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int DaysReq(vector<int> &wh, int cap)
{
     int load = 0;
     int days = 1;
     int n = wh.size();
     for (int i = 0; i < n; i++)
     {
          if (load + wh[i] > cap)
          {
               load = wh[i];
               days++;
          }
          else
          {
               load += wh[i];
          }
     }
     return days;
}

int shipWithinDaysBrute(vector<int> &weights, int days)
{
     int maxCapacity = 0;
     for (auto w : weights)
     {
          maxCapacity += w;
     }

     int minCapacity = *max_element(weights.begin(), weights.end());

     for (int i = minCapacity; i <= maxCapacity; i++)
     {
          int daysReq = DaysReq(weights, i);

          if (daysReq <= days)
          {
               return i;
          }
     }

     return -1;
}

int shipWithinDaysOptimal(vector<int> &weights, int days)
{

     int high = 0;
     for (auto w : weights)
     {
          high += w;
     }

     int low = *max_element(weights.begin(), weights.end());
     int ans = -1;
     while (low <= high)
     {
          int mid = (low + high) / 2;
          int daysReq = DaysReq(weights, mid);

          if (daysReq <= days)
          {
               ans = mid;
               high = mid - 1;
          }
          else
          {
               low = mid + 1;
          }
     }
     return ans;
}

int main()
{

     return 0;
}