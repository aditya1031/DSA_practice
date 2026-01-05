// aditya kumar
// 21bcs9520
#include <bits/stdc++.h>
using namespace std;


// time conplexcity nlog n
int func(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot&&i<=high-1)
        {

            i++;
        }
        while (arr[j] > pivot&&j>=low+1)
        {

            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partion = func(arr, low, high);
        quicksort(arr, low, partion - 1);
        quicksort(arr, partion + 1, high);
    }
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
    int n = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "unsorted array :" << endl;
    printArray(arr, n);

    quicksort(arr,0,n-1);

    cout << "Sorted array: " << endl;
    printArray(arr, n);
}