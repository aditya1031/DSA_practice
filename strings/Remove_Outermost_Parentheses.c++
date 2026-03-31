#include <bits/stdc++.h>
using namespace std;

/*
Intuition:
The outermost parentheses are the first '(' and last ')' of every primitive string.
We need to remove only those outer brackets and keep the inner ones.

Approach:
We use a variable "depth" to track the nesting level.
- When we see '(', we increase depth.
- When we see ')', we decrease depth.
- We only add parentheses to the answer when depth > 0.
This ensures we skip the outermost parentheses.

Time Complexity: O(n)
Space Complexity: O(n)
*/

string removeOuterParentheses(string s)
{
    string ans = "";   // stores final result
    int depth = 0;     // tracks current nesting level

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            if (depth > 0)      // not outermost
                ans += s[i];
            depth++;            // increase depth
        }
        else if (s[i] == ')')
        {
            depth--;            // decrease depth first
            if (depth > 0)      // not outermost
                ans += s[i];
        }
    }
    return ans;
}

int main()
{
    string s = "(()())(())";
    cout << removeOuterParentheses(s);
    return 0;
}