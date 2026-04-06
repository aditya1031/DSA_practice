#include <bits/stdc++.h>

using namespace std;

bool isPalindromeBrute(string s)
{

     string og = s;
     reverse(s.begin(), s.end());
     if (og == s)
     {
          return true;
     }
     return false;
}

bool isPalindromeOptimal(string s)
{

     int l = 0;
     int r = s.size() - 1;
     while (l < r)
     {
          if (s[l] != s[r])
          {
               return false;
          }
          l++;
          r--; 
     }
     return true;
}

int main()
{
     string s = "asdfdsa";
     cout << isPalindromeOptimal(s);
     return 0;
}