// aditya kumar
// 21bcs9520

#include <bits/stdc++.h>
using namespace std;

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n)
{
    int didswap = 0;
    for (int i = 0; i < n - 1; i++)

    {

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didswap++;
            }
        }

        if (didswap == 0)
        {
            cout << "alredy sorted " << endl;
            break;
        }
    }

    cout << "the number of swaps are: " << didswap << endl;
}

void selectionSort(int arr[], int n)
{
    int didswap = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minindex])
                minindex = j;
        }
        swap(arr[minindex], arr[i]);
        didswap++;
    }
    if (didswap == 0)
        cout << "already sorted" << endl;

    cout << "the number of swaps are: " << didswap << endl;
}

void merge(int arr[], int low, int mid, int high)
{
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

    for (int i = 0; i < temp.size(); i++)
    {
        arr[low + i] = temp[i];
    }
}

void MergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}




// int partition(int arr[],int l,int h){

// int pivot=arr[h];
// int i=l;
// int j=h;

// while(i<j){
//     while (i<=h-1 &&arr[i]<=pivot)

//     {
//         i++;
//     }
    
//     while (j>=l +1 &&arr[j]>pivot)
//     {
//         j--;
//     }
//     if(i<j){
//         swap(arr[i],arr[j]);
//     }
//     swap(arr[h],arr[j]);
//     return j;
    
// }


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];  // pivot is the last element
    int i = low - 1;        // smaller element index

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1; // Return the final pivot position
}


void quickSort(int arr[], int low, int n)
{
   if(low>=n)
   {
    return;
   }
   int pivot=partition(arr,0,n);
   quickSort(arr,low,pivot-1);

   quickSort(arr,pivot+1,n);
   


}


int main()
{
    int n;
    cout << "enter the lenght  of array" << endl;
    cin >> n;

    int arr[n];

    cout << "enter the elements of arrays" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "the given array is :" << endl;
    printarray(arr, n);

    // bubbleSort(arr,n);
    // selectionSort(arr, n);
   // MergeSort(arr, 0, n);
    quickSort(arr,0,n);
    cout << "the sorted array is :" << endl;
    printarray(arr, n);

    return 0;
}