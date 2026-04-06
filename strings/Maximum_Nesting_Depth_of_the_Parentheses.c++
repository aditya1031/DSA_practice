#include <bits/stdc++.h>
using namespace std;

/*
Problem: Maximum Nesting Depth of Parentheses

Intuition:
Whenever we see '(' → depth increases
Whenever we see ')' → depth decreases
We track the maximum depth reached at any point.

Algorithm:
1. Initialize cnt = 0 and ans = 0
2. Traverse the string:
   - If '(' → cnt++
   - If ')' → cnt--
   - Update ans = max(ans, cnt)
3. Return ans

Example:
s = "(1+(2*3)+((8)/4))+1"

Step-by-step depth:
( → 1
( → 2
( → 3   ← maximum depth
) → 2
) → 1
) → 0

Output = 3

Time Complexity (TC): O(n)
Space Complexity (SC): O(1)
*/

int maxDepth(string s)
{
    int cnt = 0;
    int ans = 0;

    for (char ch : s)
    {
        if (ch == '(')
        {
            cnt++;              // Increase depth
        }
        else if (ch == ')')
        {
            cnt--;              // Decrease depth
        }

        ans = max(ans, cnt);    // Track maximum depth
    }

    return ans;
}

int main()
{
    string s = "(1+(2*3)+((8)/4))+1";
    cout << maxDepth(s);
    return 0;
}