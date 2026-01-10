// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
Given two integers n and r, find the value of nCr (binomial coefficient),
which represents the number of ways to choose r elements from n elements
without considering the order.

Formula:
nCr = n! / (r! * (n - r)!)

When to use this approach:
- When n and r are moderate in size
- When you need to compute a single nCr value
- Useful in problems like:
  • Pascal’s Triangle
  • Counting combinations
  • Subarray / subsequence counting
  • Combinatorics-based DP problems
*/

int pascal_nCr(int n, int r)
{
     long long res = 1;
     // res stores the intermediate and final value of nCr

     for (int i = 0; i < r; i++)
     {
          // Multiply by (n - i) → numerator part
          res = res * (n - i);

          // Divide by (i + 1) → denominator part
          res = res / (i + 1);
     }

     // Final result = nCr
     return res;
}

/*
Time Complexity (TC):
O(r)

Space Complexity (SC):
O(1)
*/






/*
Function: Print / return nth row of Pascal’s Triangle
Logic:
- nth row has n elements (1-indexed)
- Each element = (n-1)C(c-1)
*/

vector<int> pascalBrute_rowprint(int n)
{
     vector<int> ans;

     for (int c = 1; c <= n; c++)
     {
          // Compute each element using nCr
          ans.push_back(pascal_nCr(n - 1, c - 1));
     }

     return ans;
}

/*
Time Complexity (TC): O(n²)
- n calls to nCr
- each nCr takes O(n)

Space Complexity (SC): O(n)
- to store the row
*/

//Tc: O(n)
//Sc: O(n)
vector<int> pascalBrute_rowprint2(int rowIndex) 
{
     int n = rowIndex;
     vector<int> ans;
     long long temp = 1;
     ans.push_back(temp);
     for (int col = 1; col <= n; col++)
     {
          temp = temp * (n - col + 1);
          temp = temp / (col);
          ans.push_back(temp);
     }
     return ans;
}




vector<int> pascalTriBRute(int rowIndex)  //TC - O(n^3)
//SC-O(n^2)
{
     vector<int> ans;
     for (int i = 0; i < rowIndex; i++)
     {

          for (int c = 0; c <= i; c++)
          {
               // Compute each element using nCr
               ans.push_back(pascal_nCr(i, c));
          }
     }
     return ans;
}



vector<vector<int>> pascalTriOptimal(int rowIndex)
{
     vector<vector<int>> ans;
     for (int i = 0; i < rowIndex; i++)
     {     
     ans.push_back(pascalBrute_rowprint2(i));
     }
     return ans;
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

     int n = 0, r = 0;
     cin >> n >> r;

     cout << " number is " << pascal_nCr(n, r);
     return 0;
}