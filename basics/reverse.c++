// aditya kumar
// 21bcs9520

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size = 2;
    int arr[size];
   //
    cin >> size;
    for (int i = 0; i < size; ++i)
    {
     //   cout << "enter the array ";
        cin >> arr[i];
    }
    //cout << "the reverse  array ";

    for (int i = size-1; i >= 0; --i)
    {

        cout << " "<<arr[i];
    }
}