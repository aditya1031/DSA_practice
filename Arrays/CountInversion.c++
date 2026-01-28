// git - aditya1031
// Inversion Count using Brute Force and Merge Sort (Optimal)

#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Inversion Count
Condition: i < j AND nums[i] > nums[j]
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
int inversionBrute(vector<int> &nums)
{
     int n = nums.size();
     int ans = 0;

     for (int i = 0; i < n; i++)
     {
          for (int j = i + 1; j < n; j++)
          {
               if (nums[i] > nums[j])
                    ans++;
          }
     }
     return ans;
}

/*
Merge two sorted halves and count inversions
Time Complexity: O(n)
*/
int merge(vector<int> &arr, int low, int mid, int high)
{
     int cnt = 0;
     vector<int> temp;
     int left = low, right = mid + 1;

     // Merge while counting inversions
     while (left <= mid && right <= high)
     {
          if (arr[left] <= arr[right])
               temp.push_back(arr[left++]);
          else
          {
               temp.push_back(arr[right++]);
               cnt += (mid - left + 1); // all remaining left elements form inversions
          }
     }

     // Copy remaining elements
     while (left <= mid)
          temp.push_back(arr[left++]);
     while (right <= high)
          temp.push_back(arr[right++]);

     // Copy back to original array
     for (int i = low; i <= high; i++)
          arr[i] = temp[i - low];

     return cnt;
}

/*
Merge Sort based inversion count
Time Complexity: O(n log n)
Space Complexity: O(n)
*/
int mergeSort(vector<int> &arr, int low, int high)
{
     if (low >= high)
          return 0;

     int mid = low + (high - low) / 2;
     int ans = 0;

     ans += mergeSort(arr, low, mid);
     ans += mergeSort(arr, mid + 1, high);
     ans += merge(arr, low, mid, high);

     return ans;
}

/*
Optimal inversion count wrapper
*/
int inversionOptimal(vector<int> &nums)
{
     if (nums.empty())
          return 0;
     return mergeSort(nums, 0, nums.size() - 1);
}

int main()
{
     int n;
     cin >> n;

     vector<int> arr(n);
     for (int i = 0; i < n; i++)
          cin >> arr[i];

     int ans = inversionOptimal(arr);
     cout << "Inversion Count = " << ans << endl;

     return 0;
}
