// Aditya1031
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 LEFT ROTATION (BRUTE FORCE)
 Idea:
 1. Store first D elements in temp
 2. Shift remaining elements to the left
 3. Copy temp elements to the end
 Time Complexity: O(n)
 Space Complexity: O(D)
*/
vector<int> LeftRotateD_Brute(vector<int> &nums, int D)
{
     int count = nums.size();
     vector<int> temp;

     D = D % count; // handle D >= n

     // store first D elements
     for (int i = 0; i < D; i++)
     {
          temp.push_back(nums[i]);
     }

     // shift remaining elements left
     for (int i = D; i < count; i++)
     {
          nums[i - D] = nums[i];
     }

     // copy stored elements to end
     for (int i = 0; i < D; i++)
     {
          nums[count - D + i] = temp[i];
     }

     return nums;
}

/*
 LEFT ROTATION (OPTIMAL - REVERSE METHOD)
 Steps:
 1. Reverse first D elements
 2. Reverse remaining n-D elements
 3. Reverse entire array
 Time Complexity: O(n)
 Space Complexity: O(1)
*/
vector<int> LeftRotateD_Optimal(vector<int> &nums, int D)
{
     int n = nums.size();
     if (n == 0) return nums;

     D = D % n;

     reverse(nums.begin(), nums.begin() + D);
     reverse(nums.begin() + D, nums.end());
     reverse(nums.begin(), nums.end());

     return nums;
}

/*
 RIGHT ROTATION (BRUTE FORCE)
 Idea:
 1. Store last D elements in temp
 2. Shift remaining elements right
 3. Copy temp elements to front
 Time Complexity: O(n)
 Space Complexity: O(D)
*/
vector<int> RightRotateD_Brute(vector<int> &nums, int D)
{
     int count = nums.size();
     vector<int> temp;

     D = D % count; // handle D >= n

     // store last D elements
     for (int i = count - D; i < count; i++)
     {
          temp.push_back(nums[i]);
     }

     // shift elements right (backwards to avoid overwrite)
     for (int i = count - 1; i >= D; i--)
     {
          nums[i] = nums[i - D];
     }

     // copy stored elements to front
     for (int i = 0; i < D; i++)
     {
          nums[i] = temp[i];
     }

     return nums;
}

/*
 RIGHT ROTATION (OPTIMAL - REVERSE METHOD)
 Steps:
 1. Reverse whole array
 2. Reverse first D elements
 3. Reverse remaining n-D elements
 Time Complexity: O(n)
 Space Complexity: O(1)
*/
vector<int> RightRotateD_Optimal(vector<int> &nums, int D)
{
     int n = nums.size();
     if (n == 0) return nums;

     D = D % n;

     reverse(nums.begin(), nums.end());
     reverse(nums.begin(), nums.begin() + D);
     reverse(nums.begin() + D, nums.end());

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

     int D;
     cout << "enter the place you want to rotate : ";
     cin >> D;

     // change function call as needed
     arr = LeftRotateD_Optimal(arr, D);

     cout << "updated array is : ";
     for (int i = 0; i < n; i++)
     {
          cout << arr[i] << " ";
     }
}
