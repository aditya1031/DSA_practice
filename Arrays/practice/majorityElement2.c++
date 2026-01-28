// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityBrute(vector<int> &nums) // TC O(n2)
{                                            // SC O(1)
     vector<int> ls;
     int n = nums.size();
     for (int i = 0; i < n; i++)
     {
          if (ls.size() == 0 || ls[0] != nums[i])
          {
               int count = 0;
               for (int j = 0; j < n; j++)
               {
                    if (nums[i] == nums[j])
                    {
                         count++;
                    }
               }
               if (count > n / 3)
               {
                    ls.push_back(nums[i]);
               }
          }
          if (ls.size() == 2)
          {
               break;
          }
     }
     return ls;
}

vector<int> majorityBetter(vector<int> &nums) // hahsing
{                                             // TC = O(N * logN)
                                              // SC = O(n) map data stucture
     unordered_map<int, int> mpp;
     vector<int> ls;
     int min = nums.size() / 3 + 1;
     for (int i = 0; i < nums.size(); i++)
     {
          mpp[nums[i]]++;
          if (mpp[nums[i]] == min)
          {
               ls.push_back(nums[i]);
          }
          if (ls.size() == 2)
          {
               break;
          }
     }
     return ls;
}

vector<int> majorityOptimal(vector<int> &nums) // TC O(2n)
{
     int cnt1 = 0, cnt2 = 0;
     int el1 = INT_MIN;
     int el2 = INT_MIN;
     vector<int> ls;
     for (int i = 0; i < nums.size(); i++)
     {
          if (cnt1 == 0 && el2 != nums[i])
          {
               cnt1++;
               el1 = nums[i];
          }
          else if (cnt2 == 0 && el1 != nums[i])
          {
               cnt2++;
               el2 = nums[i];
          }
          else if (nums[i] == el1)
          {
               cnt1++;
          }
          else if (nums[i] == el2)
          {
               cnt2++;
          }
          else
          {
               cnt1--;
               cnt2--;
          }
     }

     int ck1 = 0, ck2 = 0;
     for (int i = 0; i < nums.size(); i++)
     {
          if (nums[i] == el1)
          {
               ck1++;
          }
          if (nums[i] == el2)
          {
               ck2++;
          }
     }

     if (ck1 > (nums.size() / 3))
     {
          ls.push_back(el1);
     }
     if (ck2 > (nums.size() / 3))
     {
          ls.push_back(el2);
     }

     return ls;
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

     majorityBrute(arr);

     return 0;
     return 0;
}