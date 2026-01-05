#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "Enter the size of array: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the array elements : " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // precompute

    int hash[20] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    cout << "enter the number of test case" << endl;

    int q;
    cin >> q;

    while (q--)
    {
        int number;
        cin >> number;

        // fetch
        cout << "the number in arr accured by:";
        cout << hash[number] << endl;
    }
}