// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int inversionBrute(vector<int> &nums) // TC = O(n*n)
{                                     // SC = O(1)
     int n = nums.size();
     int ans = 0;

     for (int i = 0; i < n; i++)
     {

          for (int j = i + 1; j < n; j++)
          {
               if (nums[i] > nums[j])
               {
                    ans++;
               }
          }
     }

     return ans;
}

int merge(vector<int> &arr, int low, int mid, int high)
{
     int cnt = 0;
     // merge time coplexcity n
     vector<int> temp;
     int left = low;
     int right = mid + 1;
     while (left <= mid && right <= high)
     {
          if (arr[left] <= arr[right])
          {
               temp.push_back(arr[left]);
               left++;
          }
          // right is smaller
          else
          {
               temp.push_back(arr[right]);
               cnt += (mid - left + 1);   //counter for pairs
               right++;
          }
     }
     while (left <= mid)
     {
          temp.push_back(arr[left]);
          left++;
     }

     while (right <= high)
     {
          temp.push_back(arr[right]);
          right++;
     }

     for (int i = low; i <= high; i++)
     {
          arr[i] = temp[i - low];
     }
     return cnt;
}
int mergesort(vector<int> &arr, int low, int high)
{
     int ans = 0;
     // time complexcity is log (base 2) n
     if (low >= high)
     {
          return ans;
     }
     int mid = ((low + high) / 2);

     ans += mergesort(arr, low, mid);

     ans += mergesort(arr, mid + 1, high);

     ans += merge(arr, low, mid, high);
     return ans;
}

int inversionBetter(vector<int> &nums) // TC = O(nlog n)
{                                      // SV = O(n)
     int n = nums.size();

     return mergesort(nums, 0, n - 1);
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

     cout << inversionBetter(arr);

     return 0;
}