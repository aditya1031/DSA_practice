// git - aditya1031
// LeetCode 493: Reverse Pairs

#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Reverse Pair Count
Condition:
i < j AND nums[i] > 2 * nums[j]

Time Complexity: O(n^2)
Space Complexity: O(1)
*/
long long reverseBrute(vector<int> &nums)
{
     int n = nums.size();
     long long ans = 0;

     for (int i = 0; i < n; i++)
     {
          for (int j = i + 1; j < n; j++)
          {
               if ((long long)nums[i] > 2LL * nums[j])
                    ans++;
          }
     }
     return ans;
}

/*
Merge two sorted halves
Time Complexity: O(n)
Space Complexity: O(n)
*/
void merge(vector<int> &arr, int low, int mid, int high)
{
     vector<int> temp;
     int left = low, right = mid + 1;

     while (left <= mid && right <= high)
     {
          if (arr[left] <= arr[right])
               temp.push_back(arr[left++]);
          else
               temp.push_back(arr[right++]);
     }

     while (left <= mid) temp.push_back(arr[left++]);
     while (right <= high) temp.push_back(arr[right++]);

     for (int i = low; i <= high; i++)
          arr[i] = temp[i - low];
}

/*
Counts reverse pairs across left and right halves
(left part and right part are already sorted)

Time Complexity: O(n)
Space Complexity: O(1)
*/
long long reversecount(vector<int> &arr, int low, int mid, int high)
{
     long long cnt = 0;
     int right = mid + 1;

     for (int i = low; i <= mid; i++)
     {
          while (right <= high && (long long)arr[i] > 2LL * arr[right])
               right++;

          cnt += (right - (mid + 1));
     }
     return cnt;
}

/*
Merge Sort + Reverse Pair Counting
Time Complexity: O(n log n)
Space Complexity: O(n)
*/
long long mergeSort(vector<int> &arr, int low, int high)
{
     if (low >= high) return 0;

     int mid = low + (high - low) / 2;
     long long ans = 0;

     ans += mergeSort(arr, low, mid);
     ans += mergeSort(arr, mid + 1, high);
     ans += reversecount(arr, low, mid, high);
     merge(arr, low, mid, high);

     return ans;
}

/*
Optimal Reverse Pair Wrapper
Time Complexity: O(n log n)
Space Complexity: O(n)
*/
long long reverseOptimal(vector<int> &nums)
{
     if (nums.empty()) return 0;
     return mergeSort(nums, 0, nums.size() - 1);
}

int main()
{
     int n;
     cin >> n;

     vector<int> arr(n);
     for (int i = 0; i < n; i++)
          cin >> arr[i];

     long long ans = reverseOptimal(arr);
     cout << "Reverse Pair Count = " << ans << endl;

     return 0;
}
