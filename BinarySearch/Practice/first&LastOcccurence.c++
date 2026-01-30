// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

// TC = O( N)
// SC = O(1)
vector<int> searchRangeBrute(vector<int> &nums, int target)
{

     int n = nums.size();

     int first = -1;
     int last = -1;

     for (int i = 0; i < n; i++)
     {
          if (nums[i] == target)
          {
               if (first == -1)
               {
                    first = i;
               }
               last = i;
          }
     }

     return {first, last};
}

int UpperBound(vector<int> &nums, int k)
{
     int n = nums.size();

     int low = 0;
     int high = n - 1;
     int ans = n;
     while (low <= high)
     {
          int mid = (low + high) / 2;

          if (nums[mid] > k)
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

int LowerBound(vector<int> &nums, int k)
{
     int n = nums.size();

     int low = 0;
     int high = n - 1;
     int ans = n;
     while (low <= high)
     {
          int mid = (low + high) / 2;

          if (nums[mid] >= k)
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

// TC = O(log N)
// SC = O(1)
vector<int> searchRangeOptimal(vector<int> &nums, int target)
{
     int n = nums.size();
     int lb = LowerBound(nums, target);
     if (lb == n || nums[lb] != target)
     {
          return {-1, -1};
     }
     return {lb, UpperBound(nums, target) - 1};
}










int first(vector<int> &nums, int x)
{
     int n = nums.size();
     int low = 0;
     int high = n - 1;
     int first = -1;

     while (low <= high)
     {
          int mid = (low + high) / 2;
          if (nums[mid] == x)
          {
               first=mid;
               high = mid - 1;
          }
          else if (nums[mid] < x)
          {
               low=mid+1;
          }
          else{
               high=mid-1;
          }
     }
     return first;
}


int last(vector<int> &nums, int x)
{
     int n = nums.size();
     int low = 0;
     int high = n - 1;
     int last = -1;

     while (low <= high)
     {
          int mid = (low + high) / 2;
          if (nums[mid] == x)
          {
               last=mid;
             low=mid+1;
          }
          else if (nums[mid] < x)
          {
               low=mid+1;
          }
          else{
               high=mid-1;
          }
     }
     return last;
}

vector<int> searchRangeBS(vector<int> &nums, int x)
{
     int n = nums.size();
    return {first(nums,x),last(nums,x)};
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

     return 0;
}