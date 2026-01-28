// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeBrute(vector<vector<int>> &intervals)
{
     int n = intervals.size();
     vector<vector<int>> ans;

     sort(intervals.begin(), intervals.end());
     
     for (int i = 0; i < n; i++)
     {
          int start = intervals[i][0];
          int end = intervals[i][1];

          if (!ans.empty() && end <= ans.back()[1])
          {
               continue;
          }
          for (int j = i + 1; j < n; j++)
          {
               if (intervals[j][0] <= end)
               {
                    end = max(end, intervals[j][1]);
               }
               else
               {
                    break;
               }
          }
          ans.push_back({start, end});
     }

     return ans;
}




vector<vector<int>> mergeOptimal(vector<vector<int>> &intervals)
{
     int n = intervals.size();
     vector<vector<int>> ans;

     sort(intervals.begin(), intervals.end());
     
     for (int i = 0; i < n; i++)
     {          
          if (ans.empty() || intervals[i][0] >ans.back()[1])
          {
               ans.push_back(intervals[i]);
          }
          else{
               ans.back()[1]=max(ans.back()[1],intervals[i][1]);
          }
    
     }

     return ans;
}

int main()
{
     int n = 0;
     cin >> n;
     vector<vector<int>> intervals(n, vector<int>(2, 0));

     for (auto &interval : intervals)
     {
          for (auto &x : interval)
          {
               cin >> x;
          }
     }

     intervals = mergeBrute(intervals);
     for (auto interval : intervals)
     {
          for (auto x : interval)
          {
               cout << x;
          }
     }
     return 0;
}