// aditya kumar
// 21bcs9520

#include <bits/stdc++.h>
using namespace std;

void revesrearry(int arr[], int n)
{
    int start = 0;
    int end = n-1;

    int temp = 0;

   while(start<end){
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
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

    cout << "original array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    revesrearry(arr, n);

    cout << endl
         << "reverse array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}