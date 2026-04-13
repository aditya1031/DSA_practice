#include <bits/stdc++.h>
using namespace std;

/*
Problem:
Count substrings with at most K distinct characters

-----------------------------------
BRUTE FORCE APPROACH
-----------------------------------
Intuition:
Try all substrings.
For each substring, count distinct characters using hashmap.
If distinct == k → count it.
If distinct > k → break early.

Time Complexity: O(n^2)
Space Complexity: O(k)
*/

int atMaxBrute(string s, int k)
{
    int cnt = 0;

    for (int i = 0; i < s.size(); i++)
    {
        unordered_map<char, int> mp;
        int dist = 0;

        for (int j = i; j < s.size(); j++)
        {
            // New character found
            if (mp[s[j]] == 0)
            {
                dist++;
            }

            mp[s[j]]++;

            if (dist == k)
            {
                cnt++;
            }

            // If exceeds k, stop this window
            if (dist > k)
            {
                break;
            }
        }
    }

    return cnt;
}

/*
-----------------------------------
OPTIMAL APPROACH (SLIDING WINDOW)
-----------------------------------
Intuition:
Instead of checking all substrings, we use a window [left, right].

Expand right pointer:
- Add characters to map

If distinct characters > k:
- Shrink window from left

At each step:
- Number of valid substrings ending at 'right' = (right - left + 1)

-----------------------------------
IMPORTANT FORMULA:
At most K = used directly
Exactly K = atMost(K) - atMost(K-1)

-----------------------------------
Time Complexity: O(n)
Space Complexity: O(k)
*/

int atMax(string s, int k)
{
    int ans = 0;
    int left = 0;

    unordered_map<char, int> mp;

    for (int right = 0; right < s.size(); right++)
    {
        // Add current character
        mp[s[right]]++;

        // Shrink window if more than k distinct chars
        while (mp.size() > k)
        {
            mp[s[left]]--;

            if (mp[s[left]] == 0)
            {
                mp.erase(s[left]);
            }

            left++;
        }

        // Count valid substrings ending at 'right'
        ans += (right - left + 1);
    }

    return ans;
}

int countSubstrings(string s, int k) {
    // Exactly k = atMax(k) - atMax(k-1)
    return atMax(s, k) - atMax(s, k - 1);
}


int main()
{
    string s = "";
    cin >> s;

    int k = 0;
    cin >> k;

    cout << countSubstrings(s, k);

    return 0;
}