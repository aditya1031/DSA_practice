// aditya kumar
// 21bcs9520

#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
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
        cout << arr[i];
    }

    rotate(arr, n);


    cout<<endl << "rotated array: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    return 0;
}