// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<int> &arr, int left, int mid, int right)
{
     int low = left;
     int high = mid + 1;
     vector<int> temp;
     while (low <= mid && high <= right)
     {
          if (arr[low] <= arr[high])
          {
               temp.push_back(arr[low]);
               low++;
          }
          else
          {
               temp.push_back(arr[high]);
               high++;
          }
     }
     while (low <= mid)
     {

          temp.push_back(arr[low]);
          low++;
     }
     while (high <= right)
     {
          temp.push_back(arr[high]);
          high++;
     }

     for (int i = left; i <= right; i++)
     {
          arr[i] = temp[i - left];
     }
}

void mergeS(vector<int> &nums, int left, int right)
{
     int mid = (left + right) / 2;
     if (left >= right)
     {
          return;
     }

     mergeS(nums, left, mid);
     mergeS(nums, mid + 1, right);

     mergeSort(nums, left, mid, right);
}

void sorted(vector<int> &nums)
{
     int n = nums.size();

     mergeS(nums, 0, n - 1);
}

int sort2(vector<int> &nums)  //TC- O(2n) //SC - O(1)

{
     int n = nums.size();
     int count = 0;
     int count1 = 0;
     int count2 = 0;

     for (int i = 0; i < n; i++)
     {
          if (nums[i] == 0)
          {
               count++;
          }
          else if (nums[i] == 1)
          {
               count1++;
          }
          else if (nums[i] == 2)
          {
               count2++;
          }
     }

     for (int i = 0; i < count; i++)
     {
          nums[i] = 0;
     }

     for (int i = count; i < (count + count1); i++)
     {
          nums[i] = 1;
     }

     for (int i = (count + count1); i < n; i++)
     {
          nums[i] = 2;
     }

     return 0;
}

int sort3(vector<int> &nums)  //TC - O(n) SC - O(1) 
{
     int n=nums.size();
     int low=0,mid=0,high=n-1;
     while (mid<=high)
     {
          if (nums[mid]==0)
          {
               swap(nums[mid],nums[low]);
               low++;
               mid++;
          }
          else if (nums[mid]==1)
          {
               mid++;
          }
          else if (nums[mid]==2)
          {
               swap(nums[mid],nums[high]);
               high--;
          }
          
          
     }
     
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

     sort2(arr);

     for (int x : arr)
          cout << x << " ";

     return 0;
}