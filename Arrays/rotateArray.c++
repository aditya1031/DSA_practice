// aditya kumar
// 21bcs9520

#include <bits/stdc++.h>
using namespace std;

void rotateop(int arr[], int n, int d) // left rotate  O(2n) but space is O(1)
{

    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
}

// right rotate in vector
/*
reverse(nums.begin(), nums.end());             // Step 1: reverse the whole array
reverse(nums.begin(), nums.begin() + k);       // Step 2: reverse first k elements
reverse(nums.begin() + k, nums.end());         // Step 3: reverse the remaining

*/

void rotate(int arr[], int n, int d) // brute
{
    d = d % n;
    vector<int> temp;

    for (int i = 0; i < d; i++)
    {
        temp.push_back(arr[i]);
    }

    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }

    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[i - (n - d)];
    }
}

int main()
{
    int n, d;
    cin >> n >> d;
    d++;
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

    rotateop(arr, n, d);

    cout << endl
         << "rotated array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
