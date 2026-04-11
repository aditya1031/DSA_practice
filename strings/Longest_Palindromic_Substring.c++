#include <bits/stdc++.h>
using namespace std;

/*
🔴 BRUTE FORCE APPROACH

INTUITION:
- Generate all substrings
- Check if each substring is palindrome
- Keep track of longest one

TIME: O(n^3)
  - O(n^2) substrings
  - O(n) to reverse/compare

SPACE: O(n)
*/

string LongestPalindromeBrute(string s)
{
     string ans = "";

     // generate all substrings
     for (int i = 0; i < s.size(); i++)
     {
          for (int j = i; j < s.size(); j++) 
          {
               int len = j - i + 1;

               // extract substring
               string sub = s.substr(i, len);

               // reverse and compare
               string ogSub = sub;
               reverse(sub.begin(), sub.end());

               // check palindrome
               if (sub == ogSub)
               {
                    if (sub.size() > ans.size())
                    {
                         ans = sub;
                    }
               }
          }
     }
     return ans;
}


/*
🟢 EXPAND AROUND CENTER (OPTIMAL)

INTUITION:
- Every palindrome expands from a center
- Two cases:
   1. Odd length → (i, i)
   2. Even length → (i, i+1)

TIME: O(n^2)
SPACE: O(1)
*/

string expand(string &s, int left, int right)
{
     /*
     Expand while:
     - within bounds
     - characters match
     */
     while (left >= 0 && right < s.size() && s[left] == s[right])
     {
          left--;
          right++;
     }

     /*
     Loop stops after mismatch,
     so actual palindrome is:
     [left+1 ... right-1]
     */
     return s.substr(left + 1, right - left - 1);
}

string LongestPalindromeBetter(string s)
{
     string ans = "";

     // try every index as center
     for (int i = 0; i < s.size(); i++)
     {
          // odd length palindrome
          string odd = expand(s, i, i);

          // even length palindrome
          string even = expand(s, i, i + 1);

          // update answer
          if (odd.size() > ans.size())
               ans = odd;

          if (even.size() > ans.size())
               ans = even;
     }

     return ans;
}

int main()
{
     return 0;
}

/*
🔥 FINAL NOTES

Brute:
- Easy but slow → O(n^3)

Better (Expand):
- Best for interviews → O(n^2)
- No extra space

ONE-LINE REVISION:
"Take each index as center and expand outward"
*/