// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int majorityBrute(vector<int> &nums)

{
     int n = nums.size();
     for (int i = 0; i < n; i++)
     {
          int count = 0;
          for (int j = 0; j < n; j++)
          {
               if (nums[i] == nums[j])
               {
                    count++;
               }
          }
          if (count > (n / 2))
          {
               return nums[i];
          }
     }
     return -1;
}

int majorityBetter(vector<int> &nums)
{
     int n = nums.size();
     unordered_map<int, int> mpp;
     for (int i = 0; i < n; i++)
     {
          mpp[nums[i]]++;
     }
     for (auto it : mpp)
     {
          if (it.second > n / 2)
          {
               return it.first;
          }
     }
     return -1;
}

int majorityOptimal(vector<int> &nums)
{
     int n = nums.size();
     int count = 0;
     int element;
     for (int i = 0; i < n; i++)
     {
          if (count == 0)
          {
               count++;
               element = nums[i];
          }
          else if (nums[i] == element)
          {
               count++;
          }
          else
          {
               count--;
          }
     }

     int check = 0;
     for (int i = 0; i < n; i++)
     {
          if (element == nums[i])
          {
               check++;
          }
     }
     if (check > (n / 2))
     {
          return element;
     }

     return -1;
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

     cout << majorityBrute(arr);

     return 0;
}