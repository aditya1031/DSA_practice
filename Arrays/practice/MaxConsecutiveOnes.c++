// Aditya1031
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Function to find maximum consecutive 1s
// Time Complexity (TC): O(n)  -> single traversal of the array
// Space Complexity (SC): O(1) -> uses constant extra space
int MaxConsecutiveOnes(vector<int> &nums)
{
     int maxi = 0;
     int cnt = 0;
     for (int i = 0; i < nums.size(); i++)
     {
          if (nums[i] == 1)
          {
               cnt++;
               maxi = max(maxi, cnt);
          }
          else
               cnt = 0;
     }

     return maxi;
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

     cout << MaxConsecutiveOnes(arr);

     return 0;
}
