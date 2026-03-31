#include <bits/stdc++.h>

using namespace std;

 /*
     Intuition:
     An odd number always ends with an odd digit (1,3,5,7,9).
     So we just need to find the last odd digit in the string
     and return the substring from start to that index.

     Approach:
     1. Traverse the string from the end.
     2. Check if digit is odd.
     3. If odd, return substring from 0 to i.
     4. If no odd digit found, return empty string.

     Time Complexity: O(n)
     Space Complexity: O(1)
     */


string largestOddNumber(string s)
{
     for (int i = s.size() - 1; i >= 0; i--)
     {
          int num = s[i] - '0';

          if (num % 2 != 0)
          {
               return s.substr(0, i + 1);
          }
     }

     return "";
}

int main()
{
     string num = "52";
     cout << largestOddNumber(num);

     return 0;
}