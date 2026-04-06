#include <bits/stdc++.h>
using namespace std;

string reverseStringBrute(string s)
{
  reverse(s.begin(), s.end());
  return s;
}


string reverseStringBetter(string s)
{
    string rev="";
    for(int i=s.size()-1;i>=0;i--)
    {
      rev+=s[i];
    }
    return rev;
}

string reverseStringOptimal(string s)
{
  int l = 0;
  int r = s.size() - 1;
  while (l < r)
  {
    swap(s[l],s[r]);
    l++;
    r--;
  }
  return s;
}

int main()
{
  string name = "aditya";
  cout << reverseStringOptimal(name);
  return 0;
}