#include <bits/stdc++.h>
using namespace std;

/*
==================== INTUITION ====================

We need to find the "beauty" of ALL substrings.

Beauty of a substring =
(max frequency of any character) - (min frequency of any character)

Key idea:
- Instead of generating substring separately (costly),
  we FIX a starting point (i) and EXPAND the substring using j.
- While expanding, we keep updating frequency array.

Why this works:
- Every substring is uniquely represented by (i, j)
- We reuse previous computation by updating freq incrementally

--------------------------------------------------

STEP WALKTHROUGH (example: s = "aba")

i = 0
   j = 0 → "a"
      freq: a=1 → max=1, min=1 → beauty=0

   j = 1 → "ab"
      freq: a=1, b=1 → max=1, min=1 → beauty=0

   j = 2 → "aba"
      freq: a=2, b=1 → max=2, min=1 → beauty=1

i = 1
   j = 1 → "b"
      beauty = 0

   j = 2 → "ba"
      beauty = 0

i = 2
   j = 2 → "a"
      beauty = 0

Total beauty = 1

--------------------------------------------------

POINTERS:
- i → starting index of substring
- j → ending index of substring
- freq[] → tracks character frequencies dynamically

==================================================
*/

int beautySum(string s)
{
     int n = s.size();
     int total = 0;

     // i = start pointer
     for (int i = 0; i < n; i++)
     {
          vector<int> freq(26, 0); // reset for each new start

          // j = end pointer
          for (int j = i; j < n; j++)
          {
               // expand substring by including s[j]
               freq[s[j] - 'a']++;

               int maxi = 0, mini = INT_MAX;

               // check frequencies
               for (int k = 0; k < 26; k++)
               {
                    if (freq[k] > 0)
                    {
                         maxi = max(maxi, freq[k]);
                         mini = min(mini, freq[k]);
                    }
               }

               total += (maxi - mini);
          }
     }

     return total;
}

/*
==================== COMPLEXITY ====================

Time Complexity:
- i loop → O(n)
- j loop → O(n)
- freq scan → O(26) ≈ constant

👉 TC = O(n²)

Space Complexity:
- freq array of size 26

👉 SC = O(1)

===================================================
*/

int main()
{
     return 0;
}