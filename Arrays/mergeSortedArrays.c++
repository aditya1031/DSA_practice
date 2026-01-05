#include <bits/stdc++.h>
using namespace std;

vector<int> mergeBrute(vector<int> &nums1, int m, vector<int> &nums2, int n) // TC: O(m + n)
{                                                                            // SC: O(m + n)  (extra temp array)

     int index = 0;
     vector<int> temp(m + n);
     int left = 0;
     int right = 0;
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

     while (left < m)
     {
          temp[index] = nums1[left];
          left++;
          index++;
     }

     while (right < n)
     {
          temp[index] = nums2[right];
          right++;
          index++;
     }

     for (int i = 0; i < m + n; i++)
     {
          nums1[i] = temp[i];
     }

     return nums1;
}

// Time Complexity (TC):
// O(m log m + n log n)
//  - swapping loop: O(min(m, n))
//  - sort first m elements of nums1: O(m log m)
//  - sort nums2: O(n log n)
//  - copy loop: O(n)

// Space Complexity (SC):
// O(1)
//  - no extra array used (ignoring recursion stack of sort)
vector<int> mergeOptimal1(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
     int left = m - 1; // first arr last element
     int right = 0;    // second arr first element
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
     sort(nums1.begin(), nums1.end() + m);

     sort(nums2.begin(), nums2.end());

     for (int i = m; i < m + n; i++)
     {
          nums1[i] = nums2[i - m];
     }

     return nums1;
}

// Gap method  - from shell sort

vector<int> mergeOptimal2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

     int left = m - 1;    // last index for array1
     int right = n - 1;   // last index for array2
     int arr = m + n - 1; // last index for array1 including zero placeholder ex:{1,2,3,0,0,0,0}

     while (left >= 0 && right >= 0)
     {
          if (nums1[left] > nums2[right])
          {
               nums1[arr] = nums1[left];
               arr--;
               left--;
          }
          else{
               nums1[arr]=nums2[right];
               arr--;
               right--;
          }
     }

     while (right>=0)
     {
          nums1[arr]=nums2[right];
          arr--;
          right--;
     }
     
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