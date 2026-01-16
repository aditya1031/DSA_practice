// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
 MISSING NUMBER – BRUTE FORCE
 Idea:
 - For every number from 0 to n
 - Check if it exists in the array
 - If not found, that number is missing

 Time Complexity: O(n²)
 Space Complexity: O(1)
*/
int MissingNumber(vector<int> &nums)
{
     for (int i = 0; i <= nums.size(); i++)
     {
          bool flg = false;

          for (int j = 0; j < nums.size(); j++)
          {
               if (nums[j] == i)
               {
                    flg = true;
                    break;
               }
          }

          if (!flg)
          {
               return i;
          }
     }
     return -1;
}

/*
 MISSING NUMBER – SUM FORMULA (OPTIMAL)
 Idea:
 - Sum of numbers from 0 to n = n*(n+1)/2
 - Subtract sum of array elements
 - Remaining value is the missing number

 Time Complexity: O(n)
 Space Complexity: O(1)
*/
int MissingNumberSUM(vector<int> &nums)
{
     int n = nums.size();
     int Sn = (n * (n + 1)) / 2;
     int S = 0;

     for (int i = 0; i < n; i++)
     {
          S += nums[i];
     }

     return Sn - S;
}

/*
 MISSING NUMBER – XOR METHOD (OPTIMAL & SAFE)
Idea
 - We need XOR of all numbers from 0 to n
 - And XOR of all elements present in the array
 - When we XOR both results, all common numbers cancel
 - The remaining value is the missing number

 Time Complexity: O(n)
 Space Complexity: O(1)
*/
int MissingNumberXOR(vector<int> &nums)
{
     int n = nums.size();
     int x1 = 0; // XOR of array elements
     int x2 = 0; // XOR of numbers 0..n

     for (int i = 0; i < n; i++)
     {
          x1 ^= nums[i];
          x2 ^= i;
     }

     x2 ^= n; // include last number

     return x1 ^ x2;
}

/*
 MISSING NUMBER – HASHING
 Idea:
 - Create a hash array of size n+1
 - Mark present numbers
 - The index with value 0 is missing

 Time Complexity: O(n)
 Space Complexity: O(n)
*/
int MissingNumberHashing(vector<int> &nums)
{
     int n = nums.size();
     vector<int> hash(n + 1, 0);

     for (int i = 0; i < n; i++)
     {
          hash[nums[i]]++;
     }

     for (int i = 0; i <= n; i++)
     {
          if (hash[i] == 0)
          {
               return i;
          }
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

     // choose any method
     cout << MissingNumber(arr);
     // cout << MissingNumberSUM(arr);
     // cout << MissingNumberXOR(arr);
     // cout << MissingNumberHashing(arr);

     return 0;
}
