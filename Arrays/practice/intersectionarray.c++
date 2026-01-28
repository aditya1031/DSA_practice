// aditya kumar
// 21bcs9520

#include <bits/stdc++.h>
using namespace std;

void inter(int arr[], int arr2[], int n, int n2) // brute  O(n1*n2)
{
    int vis[n2] = {0};
    vector<int> inter;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n2; j++)
        {
            if (arr[i] == arr2[j] && vis[j] == 0)
            {
                inter.push_back(arr2[j]);
                vis[j] = 1;
                break;
            }
            if (arr2[j]>arr[i])
            {
                break;
            }
            
        }
    }
    cout << "inter array is: " << endl;
    for (auto it : inter)
    {
        cout << it << " ";
    }
}

void interOP(int arr[], int arr2[], int n, int n2) // O(n1+n2)  space O(1)
{
    int i, j;
    i = j = 0;
    vector<int> ams;
    while (i < n && j < n2)
    {
        if (arr[i] < arr2[j])
        {
            i++;
        }
        else if (arr[i] > arr2[j])
        {
            j++;
        }
        else
        {  
            ams.push_back(arr[i]);
            i++;
            j++;
        }
    }

    cout << "inter array is: " << endl;
    for (auto it : ams)
    {
        cout << it << " ";
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

    int n2;
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    sort(arr, arr + n);
    sort(arr2, arr2 + n2);
    interOP(arr, arr2, n, n2);

    return 0;
}