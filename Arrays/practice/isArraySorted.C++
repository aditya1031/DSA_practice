// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
Function: IsSorted
Checks if the array is sorted in non-decreasing order.

Time Complexity: O(n)
Space Complexity: O(1)
*/
bool IsSorted(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 1; i < n; i++)
    {
        if (nums[i] < nums[i - 1])
            return false;   // Not sorted
    }
    return true;            // Sorted
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Print result
    if (IsSorted(arr))
        cout << "Sorted";
    else
        cout << "Not Sorted";

    return 0;
}
