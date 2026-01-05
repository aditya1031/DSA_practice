#include <bits/stdc++.h>
using namespace std;

//O(n^2) best ,worst,avg

void selectionsort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i +1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
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

    arr = {54, 23, 1, 33, 44, 5};

    cout << "unsorted array :" << endl;
    printArray(arr);
    
    selectionsort(arr);

    cout << "Sorted array: "<<endl;
    printArray(arr);
}