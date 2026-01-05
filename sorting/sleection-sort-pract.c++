#include <bits/stdc++.h>
using namespace std;
int main()
{
     int n;
     cin >> n;
     vector<int> num(n);
     for (int i = 0; i < n; i++)
     {
          cin >> num[i]; 
     }

     for (int i = 0; i < n - 1; i++)
     {
          int min = i;
          for (int j = i; j < n; j++)
          {
               if (num[j] < num[min])
               {
                    min=j;
               } 
          }

          int temp;
          temp = num[min];
          num[min] = num[i];
          num[i] = temp;
     }

     for (int i = 0; i < n; i++)
     {
          cout << num[i]<<" ";
     }

     return 0;
}