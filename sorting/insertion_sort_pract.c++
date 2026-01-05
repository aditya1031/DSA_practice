// aditya kumar
#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr, int n)
{
     for (int i = 0 ; i <n; i++)
     {
          int j=i;
         while (j>0 && arr[j-1]>arr[j])
         {
          swap(arr[j-1],arr[j]);
          j--;
         }
         
          

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

     insertion_sort(num, n);

     cout << "\nsorted array is:" << endl;
     for (int i = 0; i < n; i++)
     {
          cout << num[i] << " ";
     }

     return 0;
}