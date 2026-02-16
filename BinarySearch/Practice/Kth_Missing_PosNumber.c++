// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int findKthPositiveBrute(vector<int> &arr, int k)
{
     int n = arr.size();
     for (int i = 0; i < n; i++)
     {
          if (arr[i] <= k)
          {
               k++;
          }
          else
          {
               break;
          }
     }
     return k;
}

int findKthPositiveOptimal(vector<int> &arr, int k)
{
     int n = arr.size();
     int low = 0;
     int high = n - 1;
     while (low <= high)
     {
          int mid = (low + high) / 2;
          int missing = arr[mid] - (mid + 1);
          if (missing < k)
          {
               low = mid + 1;
          }
          else
          {
               high = mid - 1;
          }
     }
     return low + k; // or high + 1 + k
}

int main()
{
     vector<int> arr = {1, 2, 3, 4};
     int k = 2;

     cout << findKthPositiveBrute(arr, k);

     return 0;
}