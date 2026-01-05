// aditya kumar
// 21bcs9520

#include <bits/stdc++.h>
using namespace std;

void removezero(int arr[], int n) // brute O(2n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            temp.push_back(arr[i]);
    }
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    }
    int nonZero = temp.size();

    for (int i = nonZero; i < n; i++)
    {
        arr[i] = 0;
    }
}

void removezeroOP(int arr[], int n)   //optimized O(n)and O(1)
{
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1) return;

    for (int i = j + 1; i < n; i++)
    {

        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
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
    removezeroOP(arr, n);

    cout << endl
         << " corected array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}