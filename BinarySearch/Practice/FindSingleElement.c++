// git - aditya1031

#include <bits/stdc++.h>
using namespace std;
// O(N)
int findSingleBrute(vector<int> &nums)
{
     int n = nums.size();
     int ans = -1;
     if (n == 1)
     {
          return nums[0];
     }
     for (int i = 0; i < n; i++)
     {
          if (i == 0)
          {
               if (nums[i] != nums[i + 1])
               {
                    return nums[0];
               }
          }

          else if (i == n - 1)
          {
               if (nums[i] != nums[i - 2])
               {
                    return nums[i];
               }
          }

          else
          {
               if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1])
               {
                    return nums[i];
               }
          }
     }

     return ans;
}

int findSingleBrute2(vector<int> &nums)
{
     int n = nums.size();
     int ans = 0;

     for (auto x : nums)
     {
          ans = ans ^ x;
     }

     return ans;
}

// TC = O(log N)
int findSingleOptimal(vector<int> &nums)
{
     int n = nums.size();

     if (n == 1)
          return nums[0];
     if (nums[0] != nums[1])
          return nums[0];
     if (nums[n - 1] != nums[n - 2])
          return nums[n - 1];

     int low = 1;
     int high = n - 2;

     while (low <= high)
     {
          int mid = (low + high) / 2;

          if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
          {
               return nums[mid];
          }

          if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
              (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
          {
               low = mid + 1;
          }
          else
          {
               high = mid - 1;
          }
     }

     return -1;
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

     for (int i = 0; i < n; i++)
     {
          cout << arr[i] << " ";
     }

     return 0;
}