// aditya kumar
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
     vector<int> temp;
     int left = low;
     int right = mid + 1;

     while (left <= mid && right <= high)
     {
          if (arr[left] <= arr[right])

          {
               temp.push_back(arr[left]);
               left++;
          }

          else

          {
               temp.push_back(arr[right]);
               right++;
          }
     }
     while (left <= mid)
     {
          temp.push_back(arr[left]);
          left++;
     }

     while (right <= high)
     {
          temp.push_back(arr[right]);
          right++;
     }

     for (int i = low; i <= high; i++)
     {
          arr[i] = temp[i - low];
     }
}

void merge_sort(vector<int> &arr, int min, int max)
{
     if (min >= max)
     {
          return;
     }

     int mid = (min + max) / 2;

     merge_sort(arr, min, mid);
     merge_sort(arr, mid + 1, max);

     merge(arr, min, mid, max);
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

     merge_sort(num, 0, n-1);

     cout << "\nsorted array is:" << endl;
     for (int i = 0; i < n; i++)
     {
          cout << num[i] << " ";
     }

     return 0;
}