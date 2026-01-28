#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Brute Force Merge of Two Sorted Arrays
Uses extra temporary array
TC = O(m + n)
SC = O(m + n)
---------------------------------------------------------
*/
vector<int> mergeBrute(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
     int index = 0;
     vector<int> temp(m + n);   // temporary array to store merged result
     int left = 0;
     int right = 0;

     // Merge two sorted arrays
     while (left < m && right < n)
     {
          if (nums1[left] <= nums2[right])
          {
               temp[index] = nums1[left];
               left++;
               index++;
          }
          else
          {
               temp[index] = nums2[right];
               right++;
               index++;
          }
     }

     // Copy remaining elements of nums1
     while (left < m)
     {
          temp[index] = nums1[left];
          left++;
          index++;
     }

     // Copy remaining elements of nums2
     while (right < n)
     {
          temp[index] = nums2[right];
          right++;
          index++;
     }

     // Copy merged result back to nums1
     for (int i = 0; i < m + n; i++)
     {
          nums1[i] = temp[i];
     }

     return nums1;
}

/*
---------------------------------------------------------
Better In-place Method (Swap + Sort)
TC = O(m log m + n log n)
SC = O(1)  (ignoring recursion stack of sort)
---------------------------------------------------------
*/
vector<int> mergeOptimal1(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
     int left = m - 1; // last valid element of nums1
     int right = 0;   // first element of nums2

     // Swap larger elements of nums1 with smaller elements of nums2
     while (left >= 0 && right < n)
     {
          if (nums1[left] > nums2[right])
          {
               swap(nums1[left], nums2[right]);
               left--;
               right++;
          }
          else
          {
               break;
          }
     }

     // Sort both arrays again
     sort(nums1.begin(), nums1.end() + m);
     sort(nums2.begin(), nums2.end());

     // Copy nums2 elements to nums1
     for (int i = m; i < m + n; i++)
     {
          nums1[i] = nums2[i - m];
     }

     return nums1;
}

/*
---------------------------------------------------------
Optimal In-place Merge (Two Pointers from End)
TC = O(m + n)
SC = O(1)
---------------------------------------------------------
*/
vector<int> mergeOptimal2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
     int left = m - 1;          // last index of nums1
     int right = n - 1;        // last index of nums2
     int arr = m + n - 1;      // last index of nums1 including extra space

     // Merge from the end
     while (left >= 0 && right >= 0)
     {
          if (nums1[left] > nums2[right])
          {
               nums1[arr] = nums1[left];
               arr--;
               left--;
          }
          else
          {
               nums1[arr] = nums2[right];
               arr--;
               right--;
          }
     }

     // Copy remaining elements of nums2 (if any)
     while (right >= 0)
     {
          nums1[arr] = nums2[right];
          arr--;
          right--;
     }

     return nums1;
}

int main()
{
     vector<int> nums1 = {1, 3, 5, 0, 0, 0};
     vector<int> nums2 = {2, 4, 6};
     int m = 3, n = 3;

     mergeBrute(nums1, m, nums2, n);

     // Print merged array
     for (int num : nums1)
          cout << num << " ";

     return 0;
}
