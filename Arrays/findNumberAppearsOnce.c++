// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int AppearsOnce(int arr[], int n) // tc=O(n*n)
{

     for (int i = 0; i < n; i++)
     {
          int count = 0;
          for (int j = 0; j < n; j++)
          {
               if (arr[j] == arr[i])
               {
                    count++;
               }
          }
          if (count == 1)
          {
               return arr[i];
          }
     }

     return -1;
}

int AppearOnceBetter(int arr[], int n) // tc O(3n)// SC-- O(max)
{
     int maxi = arr[0];
     for (int i = 0; i < n; i++)
     {
          maxi = max(maxi, arr[i]);
     }

     int hasharr[maxi + 1] = {0};

     for (int i = 0; i < n; i++)
     {
          hasharr[arr[i]]++;
     }
     for (int i = 0; i < n; i++)
     {
          if (hasharr[arr[i]] == 1)
          {
               return arr[i];
          }
     }
     return -1;
}

int AppearOnceBetterMAp(int arr[], int n) // tc O(2n) // SC-- O(n)
{

     unordered_map<int, int> mp;

     for (int i = 0; i < n; i++)
     {
          mp[arr[i]]++;
     }

     for (int i = 0; i < n; i++)
     {
          if (mp[arr[i]] == 1)
          {
               return arr[i];
          }
     }

     return -1;
}

int AppearOnceOptimal(int arr[], int n){
     int Xor=0;
     for (int i = 0; i < n; i++)
     {
          Xor=Xor^arr[i];
     }
     
     return Xor;
}

int main()
{

     int n;
     cin >> n;
     int arr[n];
     for (int i = 0; i < n; i++)
     {
          cin >> arr[i];
     }

     sort(arr, arr + n);

     cout << " number is " << AppearOnceOptimal(arr, n);
     return 0;
}