// aditya kumar
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
     int pivot = arr[low];
     int i = low;
     int j = high;

     while (i < j)
     {
          while (arr[i] <= pivot && i <= high - 1)
          {
               i++;
          }
          while (arr[j] > pivot && j >= low + 1)
          {
               j--;
          }
          if (i < j)
          {
               swap(arr[i], arr[j]);
          }
          
     }
     swap(arr[low], arr[j]);
          return j;
}

void quick_sort(vector<int> &arr, int min, int max)
{
     if (min < max)
     {
          int part = partition(arr, min, max);

          quick_sort(arr, min, part-1);
          quick_sort(arr, part + 1, max);
     }
}

int main()
{
     cout << "enter the size of array" << endl;
     int n;
     cin >> n;
     vector<int> num(n);
     cout << "enter the the array elemnets" << endl;
     for (int i = 0; i < n; i++)
     {
          cin >> num[i];
     }

     cout << "unsorted array is:" << endl;
     for (int i = 0; i < n; i++)
     {
          cout << num[i] << " ";
     }

     quick_sort(num, 0, n - 1);

     cout << "\nsorted array is:" << endl;
     for (int i = 0; i < n; i++)
     {
          cout << num[i] << " ";
     }

     return 0;
}