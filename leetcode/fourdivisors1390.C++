
#include <bits/stdc++.h>
using namespace std;

int sumFourDivisors(vector<int> &nums)
{
     int n = nums.size();
     int res = 0;
     for (int i = 0; i < n; i++)
     {
          vector<int> temp(0);
          for (int j = 1; j <= nums[i]; j++)
          {
               if (nums[i] % j == 0)
               {
                    temp.push_back(j);
               }
               if (temp.size() > 4)
               {
                    break;
               }
          }
          if (temp.size() == 4)
          {
               for (int k = 0; k < temp.size(); k++)
               {
                    res = res + temp[k];
               }
          }
     }
     return res;
}

int main()
{
     return 0;
}