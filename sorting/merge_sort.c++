// aditya kumar
// 21bcs9520
#include <bits/stdc++.h>
using namespace std;

//timcomplextiy nlog(n)
//space complexty o(n)
void merge(vector<int> &arr, int low, int mid, int high)
{
    //merge time coplexcity n

    vector<int> temp;
    int left = low;
    int right = mid + 1;
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
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <=high; i++)
    {
        arr[i]=temp[i-low];
    }
    


}
void mergesort(vector<int> &arr, int low, int high)
{

    //time complexcity is log (base 2) n

    if (low >= high)
    {
        return;
    }
    int mid = ((low + high )/ 2);

    mergesort(arr, low, mid);

    mergesort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

void printArray(vector<int> &arr, int n)
{

    for (int i = 0; i < n; i++)

    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "unsorted array :" << endl;
    printArray(arr, n);

    mergesort(arr, 0, n-1);

    cout << "Sorted array: " << endl;
    printArray(arr, n);
}