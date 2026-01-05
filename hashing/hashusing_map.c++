#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout << "Enter the size of array: " << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the array elements : " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // precompute

    map<int, int> mpp; // it stores in linear form meaning asending order which can lead to more time so unorder_map is preferred
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // for (auto it : mpp)
    // {
    //     cout << it.first << "-> " << it.second << endl;
    // }

    cout << "enter the number of test case" << endl;

    int q;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;

        // fetch
        cout << "the number in arr accured by:";
        cout << mpp[number] << endl;
    }
}