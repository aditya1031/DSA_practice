// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

vector<int> leftRotateBrute(vector<int> &nums)
{
     int n = nums.size();
     vector<int> temp;
     for (int i = 1; i < n; i++)
     {
          temp.push_back(nums[i]);
     }
     temp.push_back(nums[0]);

     for (int i = 0; i < n; i++)
     {
          nums[i] = temp[i];
     }

     return nums;
}


vector<int> leftRotateOPtimal(vector<int> &nums)
{
     int n = nums.size();
    int temp=nums[0];
     for (int i = 1; i < n; i++)
     {
          nums[i-1]=nums[i];
     }
     nums.push_back(temp);

     return nums;
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
     arr = leftRotateOPtimal(arr);
     for (int i = 0; i < n; i++)
     {
          cout << arr[i] << " ";
     }

     return 0;
}