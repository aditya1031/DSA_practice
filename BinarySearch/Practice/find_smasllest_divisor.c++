// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int thresholdChecker(vector<int> &nums, int num)
{
     int ans = 0;
     for (auto x : nums)
     {
          ans += (x + num - 1) / num;
     }
     return ans;
}
int smallestDivisorBrute(vector<int> &nums, int threshold)
{
     int maxi = *max_element(nums.begin(), nums.end());

     for (int i = 1; i <= maxi; i++)
     {
          int curr = thresholdChecker(nums, i);
          if (curr <= threshold)
          {
               return i;
          }
     }
     return -1;
}

int smallestDivisorOptimal(vector<int> &nums, int threshold)
{
     int high = *max_element(nums.begin(), nums.end());
     int low = 1;
     int ans=-1;
     while (low <= high)
     {
          int mid = (low + high) / 2;
          int currSum = thresholdChecker(nums, mid);
          if (currSum <= threshold)
          {
               ans = mid;
               high = mid - 1;
          }
          else
          {
               low = mid + 1;
          }
     }

     return ans;
}

int main()
{
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    cout << "Brute Answer: "
         << smallestDivisorBrute(nums, threshold) << endl;

    cout << "Optimal Answer: "
         << smallestDivisorOptimal(nums, threshold) << endl;

    return 0;
}
