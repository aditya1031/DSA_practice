#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 MOVE ZEROES (BRUTE FORCE)
 Idea:
 1. Store all non-zero elements in a temporary array
 2. Copy them back to the original array
 3. Fill remaining positions with 0

 Time Complexity: O(n)
 Space Complexity: O(n)
*/
vector<int> MoveZeroBrute(vector<int> &nums)
{
     int n = nums.size();
     vector<int> temp;

     // store non-zero elements
     for (int i = 0; i < n; i++)
     {
          if (nums[i] != 0)
          {
               temp.push_back(nums[i]);
          }
     }

     // copy non-zero elements back
     for (int i = 0; i < temp.size(); i++)
     {
          nums[i] = temp[i];
     }

     // fill remaining positions with 0
     for (int i = temp.size(); i < n; i++)
     {
          nums[i] = 0; 
     }

     return nums;
}

/*
 MOVE ZEROES (OPTIMAL - TWO POINTER)
 Idea:
 1. Pointer j tracks index of next non-zero position
 2. Traverse array with i
 3. When non-zero found, swap with j

 Time Complexity: O(n)
 Space Complexity: O(1)
*/
vector<int> MoveZeroOptimal(vector<int> &nums)
{
     int n = nums.size();
     int j = 0; // index for next non-zero element

     for (int i = 0; i < n; i++)
     {
          if (nums[i] != 0)
          {
               swap(nums[i], nums[j]);
               j++;
          }
     }

     return nums;
}

int main()
{
     int n;
     cout << "enter the size of the array : ";
     cin >> n;

     vector<int> arr(n);
     cout << "enter the array elements :\n";
     for (int i = 0; i < n; i++)
     {
          cin >> arr[i];
     }

     // choose brute or optimal
     arr = MoveZeroBrute(arr);
     // arr = MoveZeroOptimal(arr);

     cout << "updated array is : ";
     for (int i = 0; i < n; i++)
     {
          cout << arr[i] << " ";
     }
}
