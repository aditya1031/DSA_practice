#include <bits/stdc++.h>
using namespace std;

/*
Problem: Roman to Integer

Intuition:
In Roman numbers, sometimes a smaller number comes before a bigger number.
In that case we subtract it.
Example:
IV = 5 - 1 = 4
IX = 10 - 1 = 9
XL = 50 - 10 = 40

So:
If next value > current value → subtract
Else → add

Algorithm:
1. Create hashmap for Roman values.
2. Traverse the string.
3. If next character value is greater than current → subtract current.
4. Else → add current.
5. Return final sum.

Time Complexity (TC): O(n)
Space Complexity (SC): O(1)
*/

int romanToInt(string s)
{
    unordered_map<char, int> mapping = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        // Check if next value is greater → subtract
        if (i + 1 < s.size() && mapping[s[i]] < mapping[s[i + 1]])
        {
            ans -= mapping[s[i]];
        }
        else
        {
            ans += mapping[s[i]];
        }
    }

    return ans;
}

int main()
{
    string s = "MCMIV";
    cout << romanToInt(s);
    return 0;
}