// aditya kumar
#include <bits/stdc++.h>
using namespace std;

void buble_sort(vector<int> &arr, int n)
{
     for (int i = n - 1; i > 0; i--)
     {
          int didSwap = 0;
          for (int j = 0; j < i; j++)
          {
               if (arr[j] > arr[j + 1])
               {
                    swap(arr[j], arr[j + 1]);
                    didSwap++;
               }
          }
           if(didSwap==0)
           {
               break;
           }
            cout << "\nhi\n";
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

     buble_sort(num, n);

     cout << "\nsorted array is:" << endl;
     for (int i = 0; i < n; i++)
     {
          cout << num[i] << " ";
     }

     return 0;
}