#include <bits/stdc++.h>

using namespace std;


//best time complexity id O(n)
//worst is O(n^2)

void bubblesort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n - 1; i >= 0; i--)
    {
        int didswap = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didswap = 1;
            }
        }

        if (didswap == 0)
        {
            cout << "alredy sorted" << endl;
            break;
        }
    }
}

void printArray(vector<int> &arr)
{

    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr;
    arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "unsorted array :" << endl;
    printArray(arr);

    bubblesort(arr);
    cout << "Sorted array: " << endl;
    printArray(arr);
}