// git - aditya1031
// Problem: Set Mismatch (Find duplicate and missing number)

#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Brute Force Approach
-------------------------------------------------------
Idea:
- For each number from 1 to n, count its frequency in the array.
- If frequency == 0 → missing number
- If frequency == 2 → duplicate number

Time Complexity:  O(n^2)
Space Complexity: O(1)
-------------------------------------------------------
*/
vector<int> findMissMatchBrute(vector<int> &nums)
{
    int n = nums.size();
    int miss = 0, dup = 0;

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == i)
                cnt++;
        }
        if (cnt == 0)
            miss = i;
        else if (cnt == 2)
            dup = i;
    }

    return {dup, miss};
}

/*
-------------------------------------------------------
Better Approach (Hash Map)
-------------------------------------------------------
Idea:
- Use unordered_map to store frequency of each element.
- Traverse from 1 to n to find missing and duplicate.

Time Complexity:  O(n)
Space Complexity: O(n)
-------------------------------------------------------
*/
vector<int> findMissMatchBetter(vector<int> &nums)
{
    int n = nums.size();
    int miss = -1, dup = -1;
    unordered_map<int, int> freq;

    // count frequency of each number
    for (int x : nums)
        freq[x]++;

    // check numbers from 1 to n
    for (int i = 1; i <= n; i++)
    {
        if (freq[i] == 0)
            miss = i;
        else if (freq[i] == 2)
            dup = i;
    }

    return {dup, miss};
}

/*
-------------------------------------------------------
Optimal Approach using Math (Sum & Sum of Squares)
-------------------------------------------------------
Idea:
Let:
x = duplicate, y = missing

S  = sum(nums) - sum(1..n)       = x - y
S2 = sum(nums^2) - sumSquares    = x^2 - y^2 = (x-y)(x+y)

Solve equations to get x and y.

Time Complexity:  O(n)
Space Complexity: O(1)
Note: Risk of overflow, harder to explain in interviews.
-------------------------------------------------------
*/
vector<int> findMissMatchOptimalSum(vector<int> &nums)
{
    int n = nums.size();

    long long SN  = 1LL * n * (n + 1) / 2;
    long long S2N = 1LL * n * (n + 1) * (2 * n + 1) / 6;

    long long S = 0, S2 = 0;
    for (int x : nums)
    {
        S  += x;
        S2 += 1LL * x * x;
    }

    long long val1 = S - SN;        // x - y
    long long val2 = (S2 - S2N) / val1; // x + y

    long long dup = (val1 + val2) / 2;
    long long miss = dup - val1;

    return {(int)dup, (int)miss};
}

/*
-------------------------------------------------------
Optimal Approach (Sign Marking) ⭐ BEST
-------------------------------------------------------
Idea:
- Values are from 1 to n.
- Use value as index (value - 1).
- Mark visited index as negative.
- If already negative → duplicate.
- Positive index at end → missing.

Time Complexity:  O(n)
Space Complexity: O(1)
-------------------------------------------------------
*/
vector<int> findMissMatchOptimal(vector<int> &nums)
{
    int n = nums.size();
    int miss = -1, dup = -1;

    // first pass: find duplicate
    for (int i = 0; i < n; i++)
    {
        int idx = abs(nums[i]) - 1;

        if (nums[idx] < 0)
            dup = abs(nums[i]);
        else
            nums[idx] = -nums[idx];
    }

    // second pass: find missing
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
            miss = i + 1;
    }

    return {dup, miss};
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Change function here to test different approaches
    vector<int> ans = findMissMatchOptimal(arr);

    for (int x : ans)
        cout << x << " ";

    return 0;
}
