// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int rotatedNo(vector<int> &nums)
{
     int n = nums.size();
     int low = 0;
     int high = n - 1;
     int ans = -1;
     while (low <= high)
     {
          int mid = low + (high - low) / 2;
          if (nums[low] <= nums[high])
          {
               ans = low;
               break;
          }

          if (nums[low] <= nums[mid])
          {
               low = mid + 1;
          }
          else
          {
               ans = mid;
               high = mid - 1;
          }
     }
     return ans;
}

int main()
{
     
     // vector<int> arr= {4,5,6,7,0,1,2,3};
         vector<int> arr= {3,4,5,1,2};
     cout<<"the array has been rotated: "<<rotatedNo(arr)<<" times.";

     return 0;
}