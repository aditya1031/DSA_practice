// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int minDaysBrute(vector<int> &nums, int m, int k)
{
     int n = nums.size();
     if ((long long)m * k > n)
     {
          return -1;
     }

     int minday = *min_element(nums.begin(), nums.end());
     int maxday = *max_element(nums.begin(), nums.end());
     for (int i = minday; i <= maxday; i++)
     {
          int count = 0;
          int bouquet = 0;

          for (int j = 0; j < n; j++)
          {
               if (nums[j] <= i)
               {
                    count++;
                    if (count == k)
                    {
                         bouquet++;
                         count = 0;
                    }
               }
               else
               {
                    count = 0;
               }
          }
          if (bouquet >= m)
          {
               return i;
          }
     }

     return -1;
}

int mindayCal(vector<int> &nums, int k, int day)
{
     int n = nums.size();
     int count = 0;
     int bouquet = 0;

     for (int j = 0; j < n; j++)
     {
          if (nums[j] <= day)
          {
               count++;
               if (count == k)
               {
                    bouquet++;
                    count = 0;
               }
          }
          else
          {
               count = 0;
          }
     }
     return bouquet;
}

int minDaysOptimal(vector<int> &nums, int m, int k)
{
     int n = nums.size();
     if (m * k > n)
     {
          return -1;
     }
     int ans = -1;
     int low = *min_element(nums.begin(), nums.end());
     int high = *max_element(nums.begin(), nums.end());

     while (low <= high)
     {

          int mid = (low + high) / 2;
          int bouquet = mindayCal(nums, k, mid);
          if (bouquet >= m)
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
}