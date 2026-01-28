// Aditya1031
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Function 1: Find max using manual loop
Time Complexity: O(n)
Space Complexity: O(1)
*/
int maxElement(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return -1;        // Edge case: empty array

    int maxi = arr[0];   // Assume first element is max

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];   // Update if bigger value found
        }
    }
    return maxi;
}

/*
Function 2: Find max using STL
Time Complexity: O(n log n) because of sort
Space Complexity: O(1) extra (sort is in-place)
*/
int maxElement2(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return -1;        // Edge case

    // Sort the array
    sort(arr.begin(), arr.end());

    // max_element returns an iterator, so we dereference using *
    int maxi = *max_element(arr.begin(), arr.end());

    return maxi;
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    vector<int> arr(n);

    // Input elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Print array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print largest element
    cout << "Largest element here is : ";
    cout << maxElement2(arr);

    return 0;
}
