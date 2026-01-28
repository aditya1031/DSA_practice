#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

/* -------------------------------------------------------
   BRUTE FORCE APPROACH (Using Sorting)
   Time Complexity: O(n log n)
   Space Complexity: O(1)  (in-place sort)
--------------------------------------------------------*/
vector<int> secondMinMax_Brute(vector<int> &arr)
{
    if (arr.size() < 2)
        return {-1, -1};

    // Sort the array
    sort(arr.begin(), arr.end());

    // Second smallest = 2nd element
    // Second largest  = 2nd last element
    return {arr[1], arr[arr.size() - 2]};
}

/* -------------------------------------------------------
   OPTIMAL APPROACH (Single Pass)
   Time Complexity: O(n)
   Space Complexity: O(1)
--------------------------------------------------------*/
vector<int> secondMinMax_Optimal(vector<int> &arr)
{
    int n = arr.size();
    if (n < 2)
        return {-1, -1};

    int smallest = INT_MAX, secondSmallest = INT_MAX;
    int largest = INT_MIN, secondLargest = INT_MIN;

    // Traverse the array once
  for (int i = 0; i < n; i++)
{
    int x = arr[i];

    // Update smallest and second smallest
    if (x < smallest) {
        secondSmallest = smallest;
        smallest = x;
    }
    else if (x > smallest && x < secondSmallest) {
        secondSmallest = x;
    }

    // Update largest and second largest
    if (x > largest) {
        secondLargest = largest;
        largest = x;
    }
    else if (x < largest && x > secondLargest) {
        secondLargest = x;
    }
}

    // If no valid second smallest or largest exists
    if (secondSmallest == INT_MAX || secondLargest == INT_MIN)
        return {-1, -1};

    return {secondSmallest, secondLargest};
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    // Input array elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call optimal solution
    vector<int> ans = secondMinMax_Optimal(arr);

    cout << "Second smallest and second largest are: ";
    cout << ans[0] << " " << ans[1];

    return 0;
}
