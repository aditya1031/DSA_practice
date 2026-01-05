// aditya kumar
// 21bcs9520

#include <bits/stdc++.h>
using namespace std;

int missingNUmberBrute(int arr[], int n) // brute O(n*2)
{

    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] == i)
            {
                flag++;
                break;
            }
        }
        if (flag == 0)
            return i;
    }
    return 0;
}

int missingNUmberBetter(int arr[], int n) // better O(n+n) space O(n)
{

    // int hash[n+1]={0};
    vector<int> hash(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 0)
            return i;
    }

    return -1;
}

int missingNUmberOPsum(int arr[], int n) // OP O(n) space O(1)
{
    int sum = 0;
    sum = (n * (n + 1)) / 2; // sumation  of n natural numbers

    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum2 = sum2 + arr[i];
    }

    return sum - sum2;
} 

int missingNUmberOP(int arr[], int n) // OP O(n)
// space O(1)
{
    int XOR = 0;
    int XOR2 = 0;
    for (int i = 0; i < n ; i++)
    {
        XOR2 = XOR2 ^ arr[i];
        XOR = XOR ^ (i );
    }

    XOR = XOR ^ n;
    return XOR ^ XOR2;
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

    sort(arr, arr + n);

    cout << "missing number is " << missingNUmberOP(arr, n);
    return 0;
}