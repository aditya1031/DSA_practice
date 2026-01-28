// aditya kumar
// 21bcs9520

#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[(i + 1) % n])
        {
            count++;
        }
    }
    return count <= 1;
}

bool sortCheck(int arr[],int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i]<arr[i-1])
        {
            return false;
        }          
    }
    return true;
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
cout<<sortCheck(arr,n);
    return 0;
}