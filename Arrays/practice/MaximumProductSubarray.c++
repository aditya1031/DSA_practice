// git - aditya1031
#include <bits/stdc++.h>
using namespace std;

/*
-----------------------------------------
BRUTE FORCE APPROACH
-----------------------------------------
Idea:
Try every possible subarray and compute its product.

Time Complexity: O(n^3)
- i loop → n
- j loop → n
- k loop → n

Space Complexity: O(1)
*/
int productBrute(vector<int> &nums)
{
    int n = nums.size();
    long long ans = LLONG_MIN;

    // Choose starting index
    for (int i = 0; i < n; i++)
    {
        // Choose ending index
        for (int j = i; j < n; j++)
        {
            long long product = 1;

            // Multiply all elements from i to j
            for (int k = i; k <= j; k++)
            {
                product *= nums[k];
            }

            // Store maximum product
            ans = max(ans, product);
        }
    }
    return ans;
}

/*
-----------------------------------------
BETTER APPROACH
-----------------------------------------
Idea:
Fix the starting index and keep extending the subarray.
Reuse previous product.

Time Complexity: O(n^2)
- i loop → n
- j loop → n

Space Complexity: O(1)
*/
int productBetter(vector<int> &nums)
{
    int n = nums.size();
    long long ans = LONG_MIN;

    for (int i = 0; i < n; i++)
    {
        long long product = 1; // start new subarray

        for (int j = i; j < n; j++)
        {
            product *= nums[j];      // extend subarray
            ans = max(ans, product); // update answer
        }
    }
    return ans;
}

/*
-----------------------------------------
OPTIMAL APPROACH
-----------------------------------------
Idea:
Use prefix and suffix product to handle
- zeros
- negative numbers

Scan from left and right.

Time Complexity: O(n)
Space Complexity: O(1)
*/
int productOptimal(vector<int> &nums)
{
    int n = nums.size();
    long long prefix = 1, suffix = 1;
    long long maxi = LLONG_MIN;

    for (int i = 0; i < n; i++)
    {
        // Reset when product becomes zero
        if (prefix == 0) prefix = 1;
        if (suffix == 0) suffix = 1;

        // Left to right product
        prefix *= nums[i];

        // Right to left product
        suffix *= nums[n - i - 1];

        // Store maximum
        maxi = max(maxi, max(prefix, suffix));
    }
    return maxi;
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

    // Change this to test other methods
    cout << productBrute(arr);

    return 0;
}
