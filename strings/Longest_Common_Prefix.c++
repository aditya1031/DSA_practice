#include <bits/stdc++.h>
using namespace std;

/*
INTUITION (Brute - Sorting):
After sorting, the strings that will be most different are the first and last.
So the longest common prefix of the whole array will be the common prefix
of the first and last string.
*/

/*
APPROACH (Brute):
1. Sort the array of strings.
2. Take first and last string.
3. Compare characters one by one.
4. Stop when characters mismatch.
5. Return the common prefix.
*/

/*
TIME COMPLEXITY: O(n log n + m)
n = number of strings
m = length of smallest string

SPACE COMPLEXITY: O(1)
*/

string longestCommonPrefixBrute(vector<string> &strs)
{
    sort(strs.begin(), strs.end()); // Step 1: Sort

    string s1 = strs[0];                     // First string
    string s2 = strs[strs.size() - 1];       // Last string

    int N = min(s1.size(), s2.size());
    string ans = "";

    // Step 2: Compare characters
    for (int i = 0; i < N; i++)
    {
        if (s1[i] == s2[i])
            ans += s1[i];
        else
            break;
    }

    return ans;
}


/*
INTUITION (Optimal - Vertical Scanning):
Take characters from first string and compare that character
with all other strings at the same index.
If mismatch occurs, stop and return prefix.
*/

/*
APPROACH (Optimal):
1. Take first string as reference.
2. Pick character from first string.
3. Compare with all other strings at same index.
4. If mismatch or string ends, return prefix.
5. If loop finishes, return whole first string.
*/

/*
TIME COMPLEXITY: O(n * m)
n = number of strings
m = length of smallest string

SPACE COMPLEXITY: O(1)
*/

string longestCommonPrefixOptimal(vector<string> &strs)
{
    // Traverse characters of first string
    for (int i = 0; i < strs[0].size(); i++)
    {
        char ch = strs[0][i];

        // Compare this character with all strings
        for (int j = 0; j < strs.size(); j++)
        {
            // If index out of bound OR character mismatch
            if (i >= strs[j].size() || strs[j][i] != ch)
            {
                return strs[0].substr(0, i);
            }
        }
    }

    // If all characters matched
    return strs[0];
}


int main()
{
    vector<string> strs = {"flower","flow","flight"};

    cout << longestCommonPrefixOptimal(strs);

    return 0;
}