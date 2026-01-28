#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 LINEAR SEARCH
 Idea:
 1. Traverse the array from start to end
 2. Compare each element with target
 3. If found, return its index
 4. If not found, return -1

 Time Complexity: O(n)
 Space Complexity: O(1)
*/
int LinearSearch(vector<int>& nums, int ele)
{
     for (int i = 0; i < nums.size(); i++)
     {
          if (nums[i] == ele)
          {
               return i; // element found
          }
     }
     return -1; // element not found
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
     cout << "enter the element you want to search : ";
     cin >> D;

     int ans = LinearSearch(arr, D);

     cout << "your element exists at index : " << ans;
}
