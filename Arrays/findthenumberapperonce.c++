// aditya kumar
// 21bcs9520

#include <bits/stdc++.h>
using namespace std;

int find(int arr[], int n) // brute  O(n*2)
{
    int num = 0;

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        num = arr[i];
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == num)
                cnt++;
        }

        if (cnt                         == 1)
            return num;
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

    cout << "missing number is " << find(arr, n);
    return 0;
}