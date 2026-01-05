// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int largest_BruteFrocer(vector<int> &arr, int n)
{
     int largest = arr[0];
     for (int i = 0; i < n; i++)
     {
          if (largest < arr[i])
          {
               largest = arr[i];
          }
     }
     return largest;
}

int second_LargestBrute(vector<int> &arr, int n)
{

     int sec_large = -1;
     int largest = largest_BruteFrocer(arr, n);

     for (int i = 0; i < n; i++)
     {
          if (arr[i] != largest && sec_large < arr[i])
          {
               sec_large = arr[i];
          }
     }

     return sec_large;
}

void largest_Better(vector<int> &arr, int n)  //O(n)
{
     int largest = INT_MIN;
     int sec_large = INT_MIN;
     for (int i = 0; i < n; i++)
     {
          if (largest < arr[i])
          {
               sec_large = largest;
               largest = arr[i];
          }
          else if(arr[i]<largest &&arr[i]>sec_large){
sec_large=arr[i];
          }
     }

     cout << "\nThe largest number is given array is: " << largest << endl;

     cout << "\n The second largest is given array is :" << sec_large << endl;
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

     // cout << "\nThe largest number is given array is: " << largest_BruteFrocer(arr, n) << endl;

     // cout << "\n The second largest is given array is :" << second_LargestBrute(arr, n) << endl;


     largest_Better(arr,n);

     return 0;
}