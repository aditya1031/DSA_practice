// git - aditya1031

#include <bits/stdc++.h>
using namespace std;
// TC= O(m*N)
int rootBrute(int N, int M)
{
     for (int i = 1; i <= M; i++)
     {
          long long val = 1;
          for (int j = 1; j <= N; j++)
          {
               val *= i;
               if (val > M)
               {
                    break;
               }
          }

          if (val == M)
          {
               return i;
          }
     }

     return -1;
}

// TC= O(n)
//  int rootBrute(int N, int M)
//  {
//       for (int i = 1; i <= M; i++)
//       {
//            long long val=pow(i,N);

//           if (val == M)
//           {
//                return i;
//           }

//      }

//      return -1;
// }

// TC = O(log N )
int rootOptimal(int N, int M)
{
     int low = 1;
     int high = M;
     while (low <= high)
     {
          int mid = low + (high - low) / 2;
          long long val = 1;
          for (int i = 1; i <= N; i++)
          {
               val *= mid;
               if (val > M)
                    break;
          }

          if (val == M)
          {
               return mid;
          }
          else if (val < M)
          {
               low = mid + 1;
          }
          else
          {
               high = mid - 1;
          }
     }
     return -1;
}

int main()
{

     // cout << rootBrute(4, 625);
     cout << rootOptimal(4, 625);
     return 0;
}