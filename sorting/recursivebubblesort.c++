// aditya kumar
// 21bcs9520

#include <bits/stdc++.h>
using namespace std;

void recursiveBubbleSort(int arr[], int n)
{
    if (n < 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {

        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            
        }
    }
    recursiveBubbleSort(arr, n - 1);
}

void printArray(int arr[], int n)
{

    for (int i = 0; i < n; i++)

    {
        cout << arr[i] << " ";
    }
    cout << endl;
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

    cout << "unsorted array :" << endl;
    printArray(arr, n);

    recursiveBubbleSort(arr, n);
    cout << "sorted array :" << endl;
    printArray(arr, n);

    return 0;
}