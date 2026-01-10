// aditya kumar
// 21bcs9520

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size = 2;
    int arr[size];
    cout << "Enter the size";
    cin >> size;
    for (int i = 0; i < size; ++i)
    {
        cout << "enter the array ";
        cin >> arr[i];
    }

    sort(arr, arr + size);

    cout << "\nArray after sorting using :\n";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
