#include <bits/stdc++.h>
using namespace std;

/*
==================== 1. BRUTE FORCE ====================

Intuition:
We traverse the string from the back and pick one word at a time.
We skip spaces, find the word boundary, and append the word to the result.

Approach:
1. Start from the end of string.
2. Skip spaces.
3. Mark end of word.
4. Move left until space to find start of word.
5. Extract word using substr and add to answer.
6. Repeat until string start.

Time Complexity: O(n)
Space Complexity: O(n)
*/

string reverseWordsBrute(string s)
{
    string ans = "";
    int n = s.size();
    int i = n - 1;

    while (i >= 0)
    {
        while (i >= 0 && s[i] == ' ')
            i--;

        if (i < 0)
            break;

        int j = i;
        while (j >= 0 && s[j] != ' ')
            j--;

        ans += s.substr(j + 1, i - j);
        ans += " ";
        i = j - 1;
    }

    if (!ans.empty())
        ans.pop_back();

    return ans;
}

/*
==================== 2. BETTER SOLUTION ====================

Intuition:
If we reverse the whole string, the word order gets reversed
but each word becomes reversed. So we reverse each word again
to correct them.

Approach:
1. Reverse the entire string.
2. Traverse the string and build each word.
3. Reverse each word and add to result.
4. Remove extra spaces.

Time Complexity: O(n)
Space Complexity: O(n)
*/

string reverseWordsBetter(string s)
{
    reverse(s.begin(), s.end());

    string ans = "";
    string word = "";
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
        {
            word += s[i];
        }
        else
        {
            if (!word.empty())
            {
                reverse(word.begin(), word.end());
                ans += word + " ";
                word = "";
            }
        }
    }

    if (!word.empty())
    {
        reverse(word.begin(), word.end());
        ans += word;
    }
    else if (!ans.empty())
    {
        ans.pop_back();
    }

    return ans;
}

/*
==================== 3. OPTIMAL (IN-PLACE) ====================

Intuition:
We reverse the entire string first.
Then we copy each word to the front of the string and reverse
each word in place. This removes extra spaces and uses O(1) space.

Approach:
1. Reverse entire string.
2. Use two pointers:
   i = read pointer
   l = write pointer
3. Copy each word forward.
4. Reverse each copied word.
5. Resize string at the end.

Time Complexity: O(n)
Space Complexity: O(1)
*/

string reverseWordsOptimal(string s)
{
    reverse(s.begin(), s.end());
    int n = s.size();
    int i = 0, l = 0, r = 0;

    while (i < n)
    {
        while (i < n && s[i] == ' ')
            i++;

        if (i >= n)
            break;

        if (l != 0)
            s[l++] = ' ';

        r = l;

        while (i < n && s[i] != ' ')
        {
            s[l++] = s[i++];
        }

        reverse(s.begin() + r, s.begin() + l);
    }

    s.resize(l);
    return s;
}

int main()
{
    string s = "the sky is blue";

    cout << "Brute: " << reverseWordsBrute(s) << endl;
    cout << "Better: " << reverseWordsBetter(s) << endl;
    cout << "Optimal: " << reverseWordsOptimal(s) << endl;

    return 0;
}