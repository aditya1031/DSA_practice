#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cout << "enter the string" << endl;
  cin >> s;

  
  // map<char, int> mpp; stored in sorted order  avg time more

  unordered_map<char, int> mpp;

  for (int i = 0; i < s.length(); i++)
  {
    mpp[s[i]]++;
  }

  cout << "enter the number of test cases" << endl;
  int q;
  cin >> q;
  while (q--)
  {
    char ch;
    cin >> ch;
    cout << "char: " << mpp[ch] << endl;
  }
}