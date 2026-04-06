#include <bits/stdc++.h>

using namespace std;

int linearSearch(vector<int> &arr, int num)
{
     for (int i = 0; i < arr.size(); i++)
     {
          if (arr[i] == num)
          {
               return i;
          }
     }
     return -1;
}

int main()
{

     vector<int> arr = {1, 2, 34, 5, 3, 5, 6, 43, 5, 7, 4, 3};
     cout << linearSearch(arr, 6);
     return 0;
}