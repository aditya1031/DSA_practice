// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int calSum(vector<int> &nums, int subSize)
{
     int subarr = 1;
     int subarraysize = 0;
     for (int i = 0; i < nums.size(); i++)
     {
          if (subarraysize + nums[i] <= subSize)
          {
               subarraysize += nums[i];
          }
          else
          {
               subarr++;
               subarraysize = nums[i];
          }
     }
     return subarr;
}

int splitArrayBrute(vector<int> &nums, int k)
{
     if (k > nums.size())
          return -1;

     int low = *max_element(nums.begin(), nums.end());
     int high = 0;
     for (auto x : nums)
     {
          high += x;
     }

     if (k == 1)
          return high;

     for (int i = low; i < high; i++)
     {
          int sub = calSum(nums, i);
          if (sub <= k)
          {
               return i;
          }
     }
     return -1;
}

int splitArrayOptimal(vector<int> &nums, int k)
{
     if (k > nums.size())
          return -1;

     int low = *max_element(nums.begin(), nums.end());
     int high = 0;
     for (auto x : nums)
     {
          high += x;
     }

     if (k == 1)
          return high;

     while (low <= high)
     {
          int mid = (low + high) / 2;
          int sub = calSum(nums, mid);
          if (sub <= k)
          {
               high = mid - 1;
          }
          else
          {
               low = mid + 1;
          }
     }
     return low;
}

int main()
{

     return 0;
}