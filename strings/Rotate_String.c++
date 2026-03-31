#include <bits/stdc++.h>
using namespace std;

/*
INTUITION (Brute):
If we keep rotating string s one by one,
at some rotation it may become equal to goal.
If any rotation matches → return true.
*/

/*
APPROACH (Brute):
1. Check if lengths are equal, else return false.
2. Rotate string one by one (move first char to last).
3. After each rotation, compare with goal.
4. If equal → return true.
5. If no rotation matches → return false.
*/

/*
TIME COMPLEXITY: O(n^2)
- n rotations
- Each rotation comparison takes O(n)

SPACE COMPLEXITY: O(1)
*/

bool rotateStringBrute(string s, string goal)
{
     int n = s.size();

     if (n != goal.size())
          return false;

     for (int i = 0; i < n; i++)
     {
          char ch = s[0];

          // Shift all characters left
          for (int j = 1; j < n; j++)
          {
               s[j - 1] = s[j];
          }

          s[n - 1] = ch; // Put first character at end

          if (s == goal)
          {
               return true;
          }
     }
     return false;
}


/*
INTUITION (Optimal):
If goal is a rotation of s,
then goal must be a substring of (s + s).

Example:
s = "abcde"
s+s = "abcdeabcde"
goal = "cdeab" → present in s+s
*/

/*
APPROACH (Optimal):
1. Check if lengths equal.
2. Concatenate s with itself → s + s.
3. Check if goal is substring of (s + s).
4. If yes → return true, else false.
*/

/*
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)
*/

bool rotateStringOptimal(string s, string goal)
{
     int n = s.size();

     if (n != goal.size())
          return false;

     string S = s + s;

     // Check if goal is substring of s+s
     if (S.find(goal) != string::npos)
     {
          return true;
     }

     return false;
}

int main()
{
     cout << rotateStringOptimal("abcde", "cdeab"); // true
     return 0;
}