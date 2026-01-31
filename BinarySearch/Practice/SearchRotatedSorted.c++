// Aditya1031
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int linearSearch(vector<int> &nums, int k)
{
     int n = nums.size();

     for (int i = 0; i < n; i++)
     {
          if (nums[i] == k)
          {
               return i;
          }
     }

     return -1;
}

// TC = O(log 2N)
int BinarySearch(vector<int> &nums, int k)
{
     int n = nums.size();

     int low = 0;
     int high = n - 1;

     while (low <= high)
     {
          int mid = (low + high) / 2;
          if (nums[mid] == k)
          {
               return mid;
          }
          if (nums[low] <= nums[mid])
          {
               if (nums[low] <= k && k <= nums[mid])
               {
                    high = mid - 1;
               }
               else
               {
                    low = mid + 1;
               }
          }
          else
          {
               if (nums[mid] <= k && k <= nums[high])
               {
                    low = mid + 1;
               }
               else
               {
                    high = mid - 1;
               }
          }
     }

     return -1;
}

int main()
{
     vector<int> arr = {4, 5, 6, 7, 0, 1, 2};

     int k = 0;

     cout << BinarySearch(arr, k);
}