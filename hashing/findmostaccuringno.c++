// aditya kumar
// 21bcs9520

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    // fetch
    int maxfrq = 0;
    int ans = 0;
    for (auto it : hash)
    {

        if (it.second > maxfrq)

        {
            maxfrq = it.second;
            ans = it.first;
        }
    }

    cout << ans;
    return 0;
}