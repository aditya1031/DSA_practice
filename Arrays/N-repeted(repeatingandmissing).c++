// git - aditya1031
// LeetCode 645 - Set Mismatch

#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Method 1: Brute Force
TC = O(n^2)
SC = O(1)
---------------------------------------------------------
*/
vector<int> findErrorNums1(vector<int> &nums)
{
    int miss = -1, dup = -1;

    for (int i = 1; i <= nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == i)
                count++;
        }

        if (count == 2) dup = i;
        else if (count == 0) miss = i;
    }
    return {dup, miss};
}

/*
---------------------------------------------------------
Method 2: Hashing
TC = O(n)
SC = O(n)
---------------------------------------------------------
*/
vector<int> findErrorNums2(vector<int> &nums)
{
    int miss = -1, dup = -1;
    int n = nums.size();

    vector<int> hash(n + 1, 0);

    for (int i = 0; i < n; i++)
        hash[nums[i]]++;

    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2) dup = i;
        else if (hash[i] == 0) miss = i;
    }
    return {dup, miss};
}

/*
---------------------------------------------------------
Method 3: Mathematical Formula
TC = O(n)
SC = O(1)
---------------------------------------------------------
*/
vector<int> findErrorNums3(vector<int> &nums)
{
    int n = nums.size();

    long long SN = (long long)n * (n + 1) / 2;                 // sum of 1..n
    long long S2N = (long long)n * (n + 1) * (2 * n + 1) / 6;  // sum of squares

    long long S = 0, S2 = 0;

    for (int i = 0; i < n; i++)
    {
        S += nums[i];
        S2 += (long long)nums[i] * nums[i];
    }

    long long val1 = S - SN;        // x - y
    long long val2 = S2 - S2N;      // x^2 - y^2
    val2 = val2 / val1;            // x + y

    long long x = (val1 + val2) / 2; // repeating
    long long y = x - val1;          // missing

    return {(int)x, (int)y};
}

/*
---------------------------------------------------------
Method 4: XOR Method
TC = O(n)
SC = O(1)
---------------------------------------------------------
*/
vector<int> findErrorNums4(vector<int> &nums)
{
    int n = nums.size();
    int xr = 0;

    // XOR of all array elements and 1..n
    for (int i = 0; i < n; i++)
    {
        xr ^= nums[i];
        xr ^= (i + 1);
    }

    // rightmost set bit
    int number = xr & ~(xr - 1);

    int zero = 0, one = 0;

    // divide array elements
    for (int i = 0; i < n; i++)
    {
        if (nums[i] & number) one ^= nums[i];
        else zero ^= nums[i];
    }

    // divide numbers from 1..n
    for (int i = 1; i <= n; i++)
    {
        if (i & number) one ^= i;
        else zero ^= i;
    }

    // check which is duplicate
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (nums[i] == zero) cnt++;

    if (cnt == 2) return {zero, one}; // zero = duplicate
    return {one, zero};              // one = duplicate
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Choose any method
    vector<int> ans = findErrorNums3(arr);

    cout << "Repeating = " << ans[0] << endl;
    cout << "Missing   = " << ans[1] << endl;

    return 0;
}
