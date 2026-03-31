#include <bits/stdc++.h>

using namespace std;

int atMaxBrute(string s, int k)
{
     int cnt = 0;
     for (int i = 0; i < s.size(); i++)
     {
          unordered_map<char, int> mp;
          int dist = 0;
          for (int j = i; j < s.size(); j++)
          {
               if (mp[s[j]] == 0)
               {
                    dist++;
               }
               mp[s[j]]++;
               if (dist == k)
               {
                    cnt++;
               }
               if (dist > k)
               {
                    break;
               }
          }
     }
     return cnt;
}

int atMax(string s, int k)
{
     int ans = 0;
     int left = 0;

     unordered_map<char, int> mp;

     for (int right = 0; right < s.size(); right++)
     {
          mp[s[right]]++;
          while (mp.size() > k)
          {
               mp[s[left]]--;
               if (mp[s[left]] == 0)
               {
                    mp.erase(s[left]);
               }
               left++;
          }
          ans += (right - left + 1);
     }
     return ans;
}

int main()
{
     string s="";
     cin>>s;
     int k=0;
     cin>>k;
     cout<<atMax(s,k);
return 0;
}