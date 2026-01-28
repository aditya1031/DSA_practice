// aditya kumar
// 21bcs9520

#include <bits/stdc++.h>
using namespace std;

void unionN(int arr[], int arr2[], int n, int n2) // brute O(n1logn+n2logn + O(n1+n2))
{

    set<int> st;

    for (int i = 0; i < n; i++) //(n1 log n)
    {
        st.insert(arr[i]);
    }

    for (int i = 0; i < n2; i++) //(n1 log n)
    {
        st.insert(arr2[i]);
    }

    cout << "the union array is :" << endl;

    int n3 = 0;
    n3 = st.size();
    int uni[n3];
    int i = 0;
    for (auto it : st)
    {
        uni[i++] = it;
    }

    for (int i = 0; i < n3; i++) //(n1 +n2)
    {
        cout << uni[i] << " ";
    }
}

void unionOP(int arr[], int arr2[], int n, int n2)   //O(n1+n2)  space O(n1+n2)to return not in algo
{
    int i, j;
    i = j = 0;
    vector<int> uniarry;
    while (i < n && j < n2)
    {
        if (arr[i] <= arr2[j])
        {
            if (uniarry.size() == 0 || uniarry.back() != arr[i])
            {
                uniarry.push_back(arr[i]);
            }
            i++;
        }
        else if (arr[i] == arr2[j])
        {
            if (uniarry.empty() || uniarry.back() != arr[i])
            {
                uniarry.push_back(arr[i]);
            }
            i++;
            j++;
        }
        else
        {

            if (uniarry.size() == 0 || uniarry.back() != arr2[j])
            {
                uniarry.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (j < n2)
    {
        if (uniarry.size() == 0 || uniarry.back() != arr2[j])
        {
            uniarry.push_back(arr2[j]);
        }
        j++;
    }

    while (i < n)
    {
        if (uniarry.size() == 0 || uniarry.back() != arr[i])
        {
            uniarry.push_back(arr[i]);
        }
        i++;
    }

    cout << "union array is: " << endl;
    for (auto it : uniarry)
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
    unionOP(arr, arr2, n, n2);

    return 0;
}