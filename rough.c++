// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int solution(string s, int k)
{
     int left = 0;
     int cnt = 0;
     unordered_map<char, int> mp;
     for (int right = 0; right < s.size(); right++)
     {
          mp[s[right]]++;
          while(mp.size()>k)
          {
               mp[s[left]]--;
               if(mp[s[left]]==0)
               {
                    mp.erase(s[left]);
               }
               left++;
          }
          cnt+=(right-left+1);
     }
     return cnt;
}

int main()
{
     int n;
     // cin >> n;
     vector<int> arr = {1, 2, 4, 7, 7, 5};

     // for (int i = 0; i < n; i++)
     // {
     //      cin >> arr[i];
     // }

     vector<int> ans = solution(arr);
     cout << "the values arr : ";
     for (int x : ans)
     {
          cout << x << "  ";
     }

     return 0;
}