#include <bits/stdc++.h>
using namespace std;

bool isAnagramOptimalBrute(string s, string t)
{
     sort(s.begin(), s.end());
     sort(t.begin(), t.end());
     return s == t;
}

/*
INTUITION:
Two strings are anagrams if they contain the same characters
with the same frequency.

So we:
- Add frequency for string s
- Subtract frequency for string t
If all values become 0 → both strings have same frequency → anagram
*/

/*
APPROACH:
1. If lengths are not equal → return false.
2. Create frequency array of size 26 (for lowercase letters).
3. Traverse both strings:
      increment for s[i]
      decrement for t[i]
4. Check if all frequencies are 0.
5. If yes → return true, else false.
*/

/*
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
(Only 26 characters)
*/

bool isAnagramOptimal(string s, string t)
{
     int n = s.size();

     // Step 1: Length check
     if (n != t.size())
          return false;

     vector<int> letter(26, 0);

     // Step 2: Count and cancel
     for (int i = 0; i < n; i++)
     {
          letter[s[i] - 'a']++; // Count s
          letter[t[i] - 'a']--; // Cancel t
     }

     // Step 3: Check all zero
     for (int i = 0; i < 26; i++)
     {
          if (letter[i] != 0)
               return false;
     }

     return true;
}

int main()
{
     cout << isAnagram("anagram", "nagaram"); // true
     return 0;
}