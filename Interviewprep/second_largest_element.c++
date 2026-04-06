#include <bits/stdc++.h>

using namespace std;

int secondLargestBrute(vector<int> &arr)
{
     int n = arr.size();
     sort(arr.begin(), arr.end());
     return arr[n - 2];
}

int secondLargestBetter(vector<int> &arr)
{
     int n = arr.size();
     int largest = arr[0];
     int sec = 0;
     for (int i = 1; i < n; i++)
     {
          if (arr[i] > largest)
          {

               sec = largest;
               largest = arr[i];
          }
          else if (arr[i] < largest && arr[i] > sec)
          {
               sec = arr[i];
          }
     }
     return sec;
}

int main()
{
     vector<int> arr = {12, 35, 1, 10, 34, 1};
     cout << secondLargestBetter(arr);
     return 0;
}