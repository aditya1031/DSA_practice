#include <bits/stdc++.h>

using namespace std;


//best time complexity id O(n )
//worst and avg case is O(n^2)

void insertionsort(vector<int> &arr)
{

    int n=arr.size();

    for (int i = 0; i < n; i++)
    {
        int key=arr[i];
        int j=i-1;
        while (j>=0&&arr[j]>key)

        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        
    }
    

    
}

void printArray(vector<int> &arr)
{

    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr;
    arr = {1,4,2,66,1,0,23};

    cout << "unsorted array :" << endl;
    printArray(arr);

    insertionsort(arr);

    cout << "Sorted array: " << endl;
    printArray(arr);
}