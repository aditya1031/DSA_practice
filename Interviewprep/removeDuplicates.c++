#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> &arr)
{
     int n = arr.size();
     int i = 0;
     for (int j = 1; j < n; j++)
     {
          if (arr[j] != arr[i])
          {
               i++;
               arr[i] = arr[j];
          }
     }

     return i + 1;
}

void removeDuplicatesBrute(vector<int> &arr)
{
     int n = arr.size();
     set<int> s(arr.begin(), arr.end());
     arr.assign(s.begin(),s.end());
}

int main()
{
     vector<int> arr = {12, 35, 1, 10, 34, 1, 1, 22, 35, 12};
     sort(arr.begin(), arr.end());
     int size = removeDuplicates(arr);

     for (int i = 0; i < size; i++)
     {
          cout << arr[i] << " ";
     }
     return 0;
}