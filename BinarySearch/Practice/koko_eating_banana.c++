// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

long long maxTime(vector<int> &nums, int k)
{

     int n = nums.size();
     long long time = 0;
     for (auto x : nums)
     {
          time += (x + k - 1) / k;
          // time+=ceil((double)x/k);
     }
     return time;
}

int eatingBrute(vector<int> &nums, int h)
{
     int n = nums.size();
     int maxSpeed = nums[0];
     for (int x : nums)
     {
          maxSpeed = max(maxSpeed, x);
     }

     for (int i = 1; i <= maxSpeed; i++)
     {
          int totalTime = maxTime(nums, i);
          if (totalTime <= h)
          {
               return i;
          }
     }
     return -1;
}

int eatingOptimal(vector<int> &nums, int h)
{
     int n = nums.size();
     int high = nums[0];
     int ans = -1;
     for (int x : nums)
     {
          high = max(high, x);
     }
     int low = 1;
     while (low <= high)
     {
          int mid = (low + high) / 2;
          long long totalTime = maxTime(nums, mid);

          if (totalTime <= h)
          {
               ans = mid;
               high = mid - 1;
          }
          else
          {

               low = mid + 1;
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