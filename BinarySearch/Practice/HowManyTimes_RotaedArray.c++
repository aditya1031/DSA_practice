// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int rotatedBrute(vector<int> &nums)
{
     int n = nums.size();
     int minVal = nums[0];
     int minIndx = 0;
     for (int i = 1; i < n; i++)
     {
          if (minVal > nums[i])
          {
               minVal = nums[i];
               minIndx = i;
          }
     }

     return minIndx;
}

int rotatedBetter(vector<int> &nums)
{
     int n = nums.size();
     for (int i = 0; i < n - 1; i++)
     {
          if (nums[i] > nums[i + 1])
          {
               return i + 1;
          }
     }
     return 0;
}

int rotatedOptimal(vector<int> &nums)
{
     int n = nums.size();
     int low = 0;
     int high = n - 1;
     int ans = 0;
     while (low <= high)
     {
          int mid = low + (high - low) / 2;

          // to handel duplicates
          // if (nums[low] == nums[mid] && nums[mid] == nums[high])
          // {
          //      low++;
          //      high--;
          //      continue;
          // }

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
               high = mid ;
          }
     }
     return ans;
}

int main()
{

     // vector<int> arr= {4,5,6,7,0,1,2,3};
     vector<int> arr = {3, 4, 5, 1, 2};
     cout << "the array has been rotated: " << rotatedOptimal(arr) << " times.";

     return 0;
}