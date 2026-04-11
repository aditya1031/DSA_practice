#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We simulate how integer parsing works manually:
1. Ignore leading spaces
2. Check sign (+ / -)
3. Read digits and build number
4. Handle overflow before it happens
5. Stop when non-digit appears

CORE IDEA:
ans = ans * 10 + digit
But before that → check overflow

STEPS:
1. Skip spaces
2. Detect sign
3. Traverse digits
4. Check overflow
5. Return sign * ans

TIME COMPLEXITY: O(n)
- Single pass through string

SPACE COMPLEXITY: O(1)
- No extra space used
*/

int myAtoi(string s)
{
     int ans = 0;
     int sign = 1;
     int n = s.size();
     int i = 0;

     // Step 1: Skip leading spaces
     while (i < n && s[i] == ' ')
     {
          i++;
     }

     // Step 2: Handle sign
     if (i < n && (s[i] == '+' || s[i] == '-'))
     {
          if (s[i] == '-')
          {
               sign = -1;
          }
          i++;
     }

     // Step 3: Process digits
     while (i < n && isdigit(s[i]))
     {
          int digit = s[i] - '0';

          /*
          Step 4: Overflow check

          We want:
          ans * 10 + digit <= INT_MAX

          So:
          ans <= (INT_MAX - digit) / 10

          If not → overflow
          */
          if (ans > (INT_MAX - digit) / 10)
          {
               return sign == 1 ? INT_MAX : INT_MIN;
          }

          // Build number
          ans = ans * 10 + digit;
          i++;
     }

     // Step 5: Apply sign
     return sign * ans;
}

int main()
{
     string s = "-042";
     cout << myAtoi(s);
     return 0;
}