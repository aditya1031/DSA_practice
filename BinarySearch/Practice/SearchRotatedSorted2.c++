// Aditya1031
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool linearSearch(vector<int> &nums, int k)
{
     int n = nums.size();

     for (int i = 0; i < n; i++)
     {
          if (nums[i] == k)
          {
               return true;

          }
     }

     return false;
}

// TC = O(log N) average, O(N) worst (duplicates)

bool BinarySearch(vector<int> &nums, int k)
{
     int n = nums.size();

     int low = 0;
     int high = n - 1;

     while (low <= high)
     {
          int mid = low + (high - low) / 2;
          if (nums[mid] == k)
          {
               return true;
          }
          
          if (nums[low] == nums[mid] && nums[mid] == nums[high])
          {
               low++;
               high--;
               continue;
          }

          if (nums[low] <= nums[mid])
          {
               if (nums[low] <= k && k < nums[mid])
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
               if (nums[mid] < k && k <= nums[high])
               {
                    low = mid + 1;
               }
               else
               {
                    high = mid - 1;
               }
          }
     }

     return false;
}

int main()
{
     vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};

     int k = 3;

     cout << BinarySearch(arr, k);
}