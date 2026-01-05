#include <iostream>
#include <algorithm>
using namespace std;

void swap_FUN(int i, int n, int arr[])
{
    if (i >= n / 2)
    {
        return;
    }

    swap(arr[i], arr[n - i - 1]);
    swap_FUN(i + 1, n, arr);
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

    cout << "Original array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    swap_FUN(0, n, arr);

    cout << endl << "Reversed array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
