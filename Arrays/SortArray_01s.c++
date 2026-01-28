// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Approach 1: Using STL sort
TC: O(n log n)
SC: O(1) (in-place, ignoring internal stack space)
-------------------------------------------------------
*/
void sortcolorsLib(vector<int> &nums)
{
     sort(nums.begin(), nums.end());
}

/*
-------------------------------------------------------
Approach 2: Counting method
TC: O(n)
SC: O(1)

Idea:
- Count number of 0s, 1s, and 2s
- Overwrite the array in sorted order
-------------------------------------------------------
*/
void sortcolorsLoop(vector<int> &nums)
{
     int n = nums.size();
     int cnt0 = 0, cnt1 = 0, cnt2 = 0;

     // Count occurrences of 0, 1, and 2
     for (int i = 0; i < n; i++)
     {
          if (nums[i] == 0)
          {
               cnt0++;
          }
          else if (nums[i] == 1)
          {
               cnt1++;
          }
          else
          {
               cnt2++;
          }
     }

     // Place all 0s
     for (int i = 0; i < cnt0; i++)
     {
          nums[i] = 0;
     }

     // Place all 1s
     for (int i = cnt0; i < cnt0 + cnt1; i++)
     {
          nums[i] = 1;
     }

     // Place all 2s
     for (int i = cnt0 + cnt1; i < n; i++)
     {
          nums[i] = 2;
     }
}

/*
-------------------------------------------------------
Approach 3: Dutch National Flag Algorithm (Optimal)

TC: O(n)  -> single pass
SC: O(1)  -> in-place

Basic Intuition:
- Maintain three pointers:
     low  -> boundary of 0s
     mid  -> current element
     high -> boundary of 2s

Array regions:
[0 ... low-1]   -> all 0s
[low ... mid-1] -> all 1s
[mid ... high]  -> unknown
[high+1 ... n-1]-> all 2s
-------------------------------------------------------
*/
void sortcolors(vector<int> &nums)
{
     int n = nums.size();

     int low = 0;        // position to place next 0
     int high = n - 1;   // position to place next 2
     int mid = 0;        // current element index

     // Process elements until mid crosses high
     while (mid <= high)
     {
          // If current element is 0
          if (nums[mid] == 0)
          {
               // Move 0 to left region
               swap(nums[mid], nums[low]);
               mid++;
               low++;
          }
          // If current element is 2
          else if (nums[mid] == 2)
          {
               // Move 2 to right region
               swap(nums[mid], nums[high]);

               // mid is NOT incremented here
               // because the element swapped from 'high'
               // is not yet processed
               high--;
          }
          // If current element is 1
          else
          {
               // 1 is already in correct middle region
               mid++;
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

     // Using Dutch National Flag approach
     sortcolors(arr);

     for (int i = 0; i < n; i++)
     {
          cout << arr[i] << " ";
     }

     return 0;
}
