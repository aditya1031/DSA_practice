// git - aditya1031

#include <bits/stdc++.h>
using namespace std;
void unionBrute(int arr[], int arr2[], int n, int n2)
{
     set<int> st;
     for (int i = 0; i < n; i++)
     {
          st.insert(arr[i]);
     }

     for (int i = 0; i < n2; i++)
     {
          st.insert(arr2[i]);
     }

     int n3 = st.size();
     int arr3[n3];
     int i = 0;
     for (auto it : st)
     {
          arr3[i] = it;
          i++;
     }

     for (int i = 0; i < n3; i++)
     {
          cout << " " << arr3[i] << " ";
     }
}

void unionOP(int arr[], int arr2[], int n, int n2)
{
     int i = 0, j = 0;
     vector<int> arr3;
     while (i < n && j < n2)
     {
          if (arr[i] <= arr2[j])
          {
               if (arr3.size() == 0 || arr3.back() != arr[i])
               {
                    arr3.push_back(arr[i]);
               }
               i++;
          }
          else
          {
               if (arr3.size() == 0 || arr3.back() != arr2[j])
               {
                    arr3.push_back(arr2[j]);
               }
               j++;
          }
     }

     while (j < n2)
     {
          if (arr3.size() == 0 || arr3.back() != arr2[j])
          {
               arr3.push_back(arr2[j]);
          }
          j++;
     }

     while (i < n)
     {

          if (arr3.size() == 0 || arr3.back() != arr[i])
          {
               arr3.push_back(arr[i]);
          }
          i++;
     }

     
     for (int i = 0; i < arr3.size(); i++)
     {
          cout << " " << arr3[i] << " ";
     }
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

     int n2;
     cin >> n2;
     int arr2[n2];
     for (int i = 0; i < n2; i++)
     {
          cin >> arr2[i];
     }

     sort(arr, arr + n);
     sort(arr2, arr2 + n2);
     unionBrute(arr, arr2, n, n2);

     return 0;
}