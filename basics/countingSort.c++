#include <iostream>

using namespace std;

int getMax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void countSort(int a[], int n)
{
    int output[n + 1];
    int max = getMax(a, n);
    int accuring[max + 1];

    for (int i = 0; i <= max; ++i)
    {
        accuring[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        accuring[a[i]]++;
    }

    for (int i = 1; i <= max; i++)
        accuring[i] += accuring[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[accuring[a[i]] - 1] = a[i];
        accuring[a[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}

void printArr(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main()
{
    int a[] = {37, 1, 7, 7, 37, 1};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Before sorting array elements are - \n";
    printArr(a, n);
    countSort(a, n);
    cout << "\nAfter sorting array elements are - \n";
    printArr(a, n);
    return 0;
}