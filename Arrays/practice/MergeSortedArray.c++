// git - aditya1031
// Merge Two Sorted Arrays (Brute → Better → Optimal)

#include <bits/stdc++.h>
using namespace std;

/*
 Brute Force Approach
 -------------------
 Idea:
 - Copy valid elements of nums1 and nums2 into a temp array
 - Sort the temp array
 - Copy back to nums1

 Time Complexity: O((m + n) log(m + n))
 Space Complexity: O(m + n)
*/
void mergeBrute(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
     vector<int> temp;

     // copy first m elements of nums1
     for (int i = 0; i < m; i++)
          temp.push_back(nums1[i]);

     // copy all elements of nums2
     for (int i = 0; i < n; i++)
          temp.push_back(nums2[i]);

     // sort merged array
     sort(temp.begin(), temp.end());

     // copy back to nums1
     for (int i = 0; i < m + n; i++)
          nums1[i] = temp[i];
}

/*
 Better Approach (Two Pointers + Extra Space)
 -------------------------------------------
 Idea:
 - Use two pointers on nums1 and nums2
 - Merge them in sorted order into temp
 - Copy result back to nums1

 Time Complexity: O(m + n)
 Space Complexity: O(m + n)
*/
void mergeBetter(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
     vector<int> temp;
     int left = 0, right = 0;

     // merge until one array finishes
     while (left < m && right < n)
     {
          if (nums1[left] < nums2[right])
               temp.push_back(nums1[left++]);
          else
               temp.push_back(nums2[right++]);
     }

     // copy remaining elements
     while (left < m)
          temp.push_back(nums1[left++]);

     while (right < n)
          temp.push_back(nums2[right++]);

     // copy back to nums1
     for (int i = 0; i < m + n; i++)
          nums1[i] = temp[i];
}

/*
 Optimal Approach 1 (Swap Boundary + Sort)
 ----------------------------------------
 Idea:
 - Swap larger elements of nums1 with smaller of nums2
 - Sort both arrays
 - Copy nums2 back to nums1

 Time Complexity: O(m log m + n log n)
 Space Complexity: O(1) extra
*/
void mergeOptimal1(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
     int left = m - 1;
     int right = 0;

     // swap boundary elements
     while (left >= 0 && right < n)
     {
          if (nums1[left] > nums2[right])
               swap(nums1[left--], nums2[right++]);
          else
               break;
     }

     // sort both parts
     sort(nums1.begin(), nums1.begin() + m);
     sort(nums2.begin(), nums2.end());

     // copy nums2 back into nums1
     for (int i = 0; i < n; i++)
          nums1[m + i] = nums2[i];
}

/*
 Optimal Approach 2 (Three Pointers from Back)
 --------------------------------------------
 Idea:
 - Start filling nums1 from the back
 - Compare largest elements of nums1 and nums2
 - Place the larger one at the end

 Time Complexity: O(m + n)
 Space Complexity: O(1)
*/
void mergeOptimal2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
     int left = m - 1;
     int right = n - 1;
     int index = m + n - 1;

     while (left >= 0 && right >= 0)
     {
          if (nums1[left] > nums2[right])
               nums1[index--] = nums1[left--];
          else
               nums1[index--] = nums2[right--];
     }

     // copy remaining nums2 elements (if any)
     while (right >= 0)
          nums1[index--] = nums2[right--];
}
int main()
{
     int m, n;
     cin >> m >> n;

     vector<int> nums1(m + n), nums2(n);

     // input first m elements of nums1
     for (int i = 0; i < m; i++)
          cin >> nums1[i];

     // input nums2
     for (int i = 0; i < n; i++)
          cin >> nums2[i];

     mergeOptimal2(nums1, m, nums2, n);

     // output merged array
     for (int x : nums1)
          cout << x << " ";

     return 0;
}