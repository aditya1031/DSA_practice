#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We cannot directly count substrings with exactly K distinct chars easily.
So we use a trick:

Exactly(K) = AtMost(K) - AtMost(K-1)

AtMost(K): count substrings having at most K distinct characters
*/

int atMostKDistinct(string s, int k)
{
     int n = s.size();
     int cnt = 0;              // stores total valid substrings
     int left = 0;             // left pointer of window
     unordered_map<char, int> mpp; // frequency map

     // expand window using right pointer
     for (int right = 0; right < n; right++)
     {
          mpp[s[right]]++; // include current char

          /*
          If distinct characters > k,
          shrink window from left
          */
          while (mpp.size() > k)
          {
               mpp[s[left]]--;   // remove left char
               if (mpp[s[left]] == 0)
               {
                    mpp.erase(s[left]); // remove from map if freq = 0
               }
               left++;
          }

          /*
          Count substrings ending at 'right'

          All valid substrings:
          [left...right], [left+1...right], ... [right...right]

          Count = (right - left + 1)
          */
          cnt += (right - left + 1);
     }

     return cnt;
}

/*
FINAL FUNCTION:
Exactly K distinct = AtMost(K) - AtMost(K-1)
*/
int countSubstrings(string s, int k)
{
     return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

int main()
{
     string s = "pqpqs";
     int k = 2;

     cout << "Count: " << countSubstrings(s, k) << endl;
     return 0;
}

/*
TIME COMPLEXITY: O(n)
- Each element is visited at most twice (left & right)

SPACE COMPLEXITY: O(k)
- Map stores at most k distinct characters
*/