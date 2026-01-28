// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

vector<int> leaderBrute(vector<int> &nums) // TC - O(n*n)
                                           // SC - O(~n)
{
     bool led;
     vector<int> temp;
     for (int i = 0; i < nums.size(); i++)
     {
          led = true;
          for (int j = i + 1; j < nums.size(); j++)
          {
               if (nums[i] < nums[j])
               {
                    led = false;
                    break;
               }
          }
          if (led == true)
          {
               temp.push_back(nums[i]);
          }
     }
     return temp;
}

vector<int> leaderOPtimal(vector<int> &nums) // TC - O(n)
                                             // SC - O(~n)
{

     int maxi = INT_MIN;
     int n = nums.size();
     vector<int> temp;
     for (int i = n - 1; i >= 0; i--)
     {
          if (nums[i] > maxi)
          {
               temp.push_back(nums[i]);
          }
          maxi = max(maxi, nums[i]);
     }
     reverse(temp.begin(), temp.end());

     return temp;
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

     leaderOPtimal(arr);

     for (int i = 0; i < n; i++)
     {
          cout << arr[i] << " ";
     }
     cout << endl;

     return 0;
}