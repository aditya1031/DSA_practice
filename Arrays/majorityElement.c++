// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
==================== BRUTE FORCE APPROACH ====================

Idea:
- For each element, count its frequency by scanning the array
- Avoid duplicate checks using the `ans` vector
- If frequency > n/3, add it to result

Why max 2 elements?
- At most 2 elements can appear more than n/3 times

Time Complexity (TC):
- Outer loop: O(n)
- Inner counting loop: O(n)
- Checking in ans: O(1) (max size 2)
=> TC = O(n^2)

Space Complexity (SC):
- Result vector stores at most 2 elements
=> SC = O(1)
*/
vector<int> majorityElementBrute(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        bool flg = false;

        // check if already processed
        for (auto x : ans)
        {
            if (x == nums[i])
                flg = true;
        }
        if (flg)
            continue;

        // count frequency
        for (int j = 0; j < n; j++)
        {
            if (nums[i] == nums[j])
                curr++;
        }

        if (curr > (n / 3))
            ans.push_back(nums[i]);
    }

    return ans;
}

/*
==================== BETTER APPROACH ====================

Idea:
- Use hashmap to count frequencies
- Add elements with frequency > n/3

Time Complexity (TC):
- Counting: O(n)
- Iterating map: O(n)
=> TC = O(n)

Space Complexity (SC):
- HashMap stores frequencies
=> SC = O(n)
*/
vector<int> majorityElementBetter(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mpp;
    vector<int> ans;

    for (int i = 0; i < n; i++)
        mpp[nums[i]]++;

    for (auto it : mpp)
    {
        if (it.second > n / 3)
            ans.push_back(it.first);
    }

    return ans;
}

/*
==================== OPTIMAL APPROACH ====================
(Boyer-Moore Voting Algorithm – Extended)

Key Idea:
- There can be at most 2 elements with frequency > n/3
- Maintain two candidates and their counters
- First pass finds potential candidates
- Second pass verifies their actual frequency

Time Complexity (TC):
- First pass: O(n)
- Second pass: O(n)
=> TC = O(n)

Space Complexity (SC):
- Only constant variables used
=> SC = O(1)
*/
vector<int> majorityElementOptimal(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;

    int cnt1 = 0, el1 = 0;
    int cnt2 = 0, el2 = 0;

    // Phase 1: Find candidates
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && el2 != nums[i])
        {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if (cnt2 == 0 && el1 != nums[i])
        {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (nums[i] == el1)
            cnt1++;
        else if (nums[i] == el2)
            cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    // Phase 2: Verify candidates
    cnt1 = 0;
    cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == el1)
            cnt1++;
        else if (nums[i] == el2)
            cnt2++;
    }

    if (cnt1 > n / 3)
        ans.push_back(el1);
    if (cnt2 > n / 3)
        ans.push_back(el2);

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Call any one (or all) approaches
    vector<int> ans1 = majorityElementBrute(arr);
    vector<int> ans2 = majorityElementBetter(arr);
    vector<int> ans3 = majorityElementOptimal(arr);

    // Print result (using optimal)
    for (int x : ans3)
        cout << x << " ";

    return 0;
}
