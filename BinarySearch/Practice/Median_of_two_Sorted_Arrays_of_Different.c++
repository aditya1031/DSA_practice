// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArraysBrute(vector<int> &nums1, vector<int> &nums2)
{
     int n = nums1.size();
     int m = nums2.size();
     vector<int> arr;
     int left = 0;
     int right = 0;
     while (left < n && right < m)
     {
          if (nums1[left] <= nums2[right])
          {
               arr.push_back(nums1[left++]);
          }
          else
          {
               arr.push_back(nums2[right++]);
          }
     }

     while (left < n)
     {
          arr.push_back(nums1[left++]);
     }
     while (right < m)
     {
          arr.push_back(nums2[right++]);
     }

     int N = arr.size();
     if ((N % 2) == 0)
     {
          return (double)((double)arr[N / 2] + (double)arr[(N / 2) - 1]) / 2.0;
     }
     else
     {
          return (double)arr[N / 2];
     }
}

double findMedianSortedArraysBetter(vector<int> &nums1, vector<int> &nums2)
{
     int n = nums1.size();
     int m = nums2.size();
     int N = m + n;

     int left = 0;
     int right = 0;

     int el1 = NULL, el2 = NULL;
     int mid2 = N / 2;
     int mid1 = (N - 1) / 2;
     int count = 0;

     while (left < n && right < m)
     {
          int val = 0;

          if (nums1[left] <= nums2[right])
               val = nums1[left++];
          else
               val = nums2[right++];

          if (count == mid1)
               el1 = val;
          if (count == mid2)
               el2 = val;

          count++;
     }

     while (left < n)
     {
          int val = nums1[left++];
          if (count == mid1)
               el1 = val;
          if (count == mid2)
               el2 = val;

          count++;
     }
     while (right < m)
     {
          int val = nums2[right++];
          if (count == mid1)
               el1 = val;
          if (count == mid2)
               el2 = val;

          count++;
     }

     if ((N % 2) == 0)
     {
          return (double)((double)el1 + (double)el2) / 2.0;
     }
     else
     {
          return (double)el2;
     }

     return -1;
}

double findMedianSortedArraysOptimal(vector<int> &nums1, vector<int> &nums2)
{
     int n1 = nums1.size();
     int n2 = nums2.size();
     int n = n1 + n2;
     if (n1 > n2)
     {
          return findMedianSortedArraysOptimal(nums2, nums1);
     }

     int low = 0;
     int high = n1;
     int left = (n1 + n2 + 1) / 2;

     while (low <= high)
     {
          int mid1 = (low + high) / 2;
          int mid2 = left - mid1;
          int l1 = INT_MIN, l2 = INT_MIN;
          int r1 = INT_MAX, r2 = INT_MAX;
          if (mid1 < n1)
          {
               r1 = nums1[mid1];
          }
          if (mid2 < n2)
          {
               r2 = nums2[mid2];
          }

          if (mid1 - 1 >= 0)
          {
               l1 = nums1[mid1 - 1];
          }
          if (mid2 - 1 >= 0)
          {
               l2 = nums2[mid2 - 1];
          }
          if (l1 <= r2 && l2 <= r1)
          {
               if (n % 2 == 1)
               {
                    return max(l1, l2);
               }
               return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
          }
          else if (l1 > r2)
          {
               high = mid1 - 1;
          }
          else
          {
               low = mid1 + 1;
          }
     }
     return -1;
}

int main()
{

     return 0;
}