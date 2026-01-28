// git - aditya1031

#include <bits/stdc++.h>
using namespace std;
void Rearrange(vector<int> &nums) // tc-O(2N) SC O(N)
{
     int n = nums.size();
     vector<int> pos;
     vector<int> neg;

     for (int i = 0; i < n; i++)
     {
          if (nums[i] > 0)
          {
               pos.push_back(nums[i]);
          }
          else
          {
               neg.push_back(nums[i]);
          }
     }
     for (int i = 0; i < n / 2; i++)
     {
          nums[2 * i] = pos[i];
          nums[(2 * i) + 1] = neg[i];
     }
}

void Rearrangeoptimal(vector<int> &nums)
{
       int n = nums.size();
        vector<int> ans(n, 0); 
        int pos = 0; 
        int neg = 1; 
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[pos] = nums[i];
                pos += 2;
            } else {
                ans[neg] = nums[i];
                neg += 2;
            }
        }

}
void Rearrange2Variety(vector<int>& nums) {
    int n = nums.size();
    vector<int> pos, neg;

    for (int x : nums) {
        if (x > 0) pos.push_back(x);
        else neg.push_back(x);
    }

    int i = 0, p = 0, q = 0;

    // Alternate while both arrays have elements
    while (p < pos.size() && q < neg.size()) {
        nums[i++] = pos[p++];
        nums[i++] = neg[q++];
    }

    // Append remaining positives
    while (p < pos.size()) {
        nums[i++] = pos[p++];
    }

    // Append remaining negatives
    while (q < neg.size()) {
        nums[i++] = neg[q++];
    }
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

     Rearrange(arr);

     for (int i = 0; i < n; i++)
     {
          cout << arr[i] << " ";
     }
     cout << endl;

     return 0;
}