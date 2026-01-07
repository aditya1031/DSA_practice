// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int productBrute(vector<int> &nums)
{
     int n = nums.size();

     long long ans = LLONG_MIN;
     for (int i = 0; i < n; i++)
     {
          for (int j = i; j < n; j++)
          {
               long long product = 1;
               for (int k = i; k <= j; k++)
               {
                    product *= (long long)nums[k];
               }
               ans = max(ans, product);
          }
     }
     return ans;
}

int productBetter(vector<int> &nums)
{
     int n = nums.size();

     long long ans = LONG_MIN;
     for (int i = 0; i < n; i++)
     {
          long long product = 1;
          for (int j = i; j < n; j++)
          {

               product *= nums[j];

               ans = max(ans, product);
          }
     }
     return ans;
}

int productOptimal(vector<int> &nums)
{
     int n = nums.size();
     long long prefix = 1, suffix = 1;
     long long maxi = LLONG_MIN;

     for (int i = 0; i < n; i++)
     {
          if (prefix == 0)
               prefix = 1;
          if (suffix == 0)
               suffix = 1;

          prefix *= nums[i];
          suffix *= nums[n - i - 1];

          maxi = max(maxi, max(prefix, suffix));
     }
     return maxi;
}

int main()
{
     int n;
     cin >> n;
     vector<int> arr(n);
     for (int i = 0; i < n; i++)
     {
          cin >> arr[i];
     }

     cout << productBrute(arr);

     return 0;
}
