// aditya kumar
// 21bcs9520

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void selection_sort(int arr[], int n)
{
    int min;

    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

void buble_sort(int arr[], int n)
{

    for (int i = n - 1; i >= 0; i--)
    {
        int didswap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didswap++;
            }
        }
        if (didswap == 0)
        {
            cout << "\nalready sorted \n";
            break;
        }
    }
}

void insertion_sort(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {

        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;

    vector<int> temp;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }
    while (right <= high)
    {
        temp.push_back(arr[right++]);
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
void msort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid;
    mid = (low + high) / 2;
    msort(arr, low, mid);
    msort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
void merge_sort(int arr[], int n)
{

    msort(arr, 0, n - 1);
}

int parti(int arr[], int low, int high)
{

    int pivot = arr[low];

    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        while (arr[j] >= pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = parti(arr, low, high);

        quick_sort(arr, low, pi - 1);

        quick_sort(arr, pi + 1, high);
    }
}

int main()
{
    int n = 0;
    cout << "enter the array size" << endl;
    cin >> n;
    int arr[n];
    cout << "enter the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "unsorted array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // selection_sort(arr, n);
    // buble_sort(arr, n);
    // insertion_sort(arr, n);
    // merge_sort(arr,n);
    quick_sort(arr, 0, n - 1);
    cout << "\nsorted array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}