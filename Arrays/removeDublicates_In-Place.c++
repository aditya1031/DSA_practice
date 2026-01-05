// git - aditya1031

#include <bits/stdc++.h>
#include <algorithm> 
using namespace std;

int removeDuplicates_BruteFroce(vector<int> &arr, int n)
{
     set<int> temp;
     for (int i = 0; i < n; i++)
     {
          temp.insert(arr[i]);
     }

     int i = 0;
     for (auto it : temp)
     {
          arr[i] = it;
          i++;
     }
     return i;
}


int removeDuplicates_Better(vector<int> &arr, int n)
{
     sort(arr.begin(), arr.end());  
        int i = 0, j = 0;
     for (i = 1; i < n; i++)
     {
          if (arr[i] != arr[j])
          {
               j++;
               arr[j] = arr[i];
          }
     }
     return j + 1;
}

int main()
{
     int n = 0;
     cout << "Enter the size of array :" << endl;
     cin >> n;
     vector<int> arr(n);

     cout << "Enter the elements of array" << endl;
     for (int i = 0; i < n; i++)
     {
          cin >> arr[i];
     }

     cout << "the array is: " << endl;
     for (int i = 0; i < n; i++)
     {
          cout << arr[i] << " ";
     }

     int new_Size = removeDuplicates_Better(arr, n);

     cout << "the array is: " << endl;
     for (int i = 0; i < new_Size; i++)
     {
          cout << arr[i] << " ";
     }

     return 0;
}