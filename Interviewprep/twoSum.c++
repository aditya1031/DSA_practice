#include <bits/stdc++.h>

using namespace std;

vector<int> twoSumBrute(vector<int> &arr, int k)
{
     int n = arr.size();

     for (int i = 0; i < n; i++)
     {

          for (int j = i + 1; j < n; j++)
          {
               int sum = arr[i] + arr[j];
               if (sum == k)
               {
                    return {i, j};
               }
          }
     }
     return {-1, -1};
}

vector<int> twoSumBetter(vector<int> &arr, int k)
{
     int n = arr.size();
     unordered_map<int, int> mp;
     for (int i = 0; i < n; i++)
     {
          int rem = k - arr[i];
          if (mp.find(rem) != mp.end())
          {
               return {mp[rem], i};
          }
          mp[arr[i]] = i;
     }

     return {-1, -1};
}

int main()
{

     return;
}