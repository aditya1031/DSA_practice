// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

// O(k*n) + O(n)
// O(n-1)
long double minimizeMaxDistanceBrute(vector<int> &arr, int k)
{
     int n = arr.size();
     vector<int> howMany(n - 1, 0);

     for (int gasStation = 1; gasStation <= k; gasStation++)
     {
          long double maxSection = -1;
          int maxInd = -1;
          for (int i = 0; i < n - 1; i++)
          {
               long double diff = arr[i + 1] - arr[i];
               long double sectionLength = diff / (long double)(howMany[i] + 1);
               if (sectionLength > maxSection)
               {
                    maxSection = sectionLength;
                    maxInd = i;
               }
          }
          howMany[maxInd]++;
     }

     long double maxAns = -1;
     for (int i = 0; i < n - 1; i++)
     {
          long double diff = arr[i + 1] - arr[i];
          long double sectionLength = diff / (long double)(howMany[i] + 1);
          maxAns = max(maxAns, sectionLength);
     }
     return maxAns;
}

// O(nlogn + klogn)
// O(n-1)
long double minimizeMaxDistanceBetter(vector<int> &arr, int k)
{
     int n = arr.size();
     vector<int> howMany(n - 1, 0);
     priority_queue<pair<long double, int>> pq;
     for (int i = 0; i < n - 1; i++)
     {
          pq.push({arr[i + 1] - arr[i], i});
     }

     for (int gasStation = 1; gasStation <= k; gasStation++)
     {
          auto tp = pq.top();
          pq.pop();
          int secInd = tp.second;
          howMany[secInd]++;
          long double iniDiff = arr[secInd + 1] - arr[secInd];
          long double newSecLen = iniDiff / (long double)(howMany[secInd] + 1);
          pq.push({newSecLen, secInd});
     }

     return pq.top().first;
}

int numberOfGasStationRequired(long double dist, vector<int> &arr)
{
     int cnt = 0;
     for (int i = 1; i < arr.size(); i++)
     {
          long double gap = arr[i] - arr[i - 1];
          int numberInBetween = ceil(gap / dist) - 1;
          cnt += numberInBetween;
     }
     return cnt;
}

long double minimizeMaxDistanceOptimal(vector<int> &arr, int k)
{
     int n = arr.size();
     vector<int> howMany(n - 1, 0);

     long double low = 0;
     long double high = 0;
     
     for (int i = 0; i < n - 1; i++)
     {
          high = max(high, (long double)(arr[i + 1] - arr[i]));
     }

     long double diff = 1e-6;

     while (high - low > diff)
     {
          long double mid = (low + high) / 2.0;
          int cnt = numberOfGasStationRequired(mid, arr);
          if (cnt > k)
          {
               low = mid;
          }
          else
          {
               high = mid;
          }
     }
     return high;
}

int main()
{

     return 0;
}