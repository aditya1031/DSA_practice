// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
-----------------------------------------
Function: printNth_elementBasic
Purpose : Returns the value of nCr (nth row, rth column)
Approach: Optimized nCr using iterative multiplication
Time    : O(r)
Space   : O(1)
-----------------------------------------
*/
int printNth_elementBasic(int n, int r)
{
     int res = 1;

     // Optimization: use smaller of r and (n-r)
     r = min(r, n - r);

     for (int i = 0; i < r; i++)
     {
          res *= (n - i);
          res /= (i + 1);
     }
     return res;
}

/*
-----------------------------------------
Function: printRow_brute
Purpose : Prints the nth row of Pascal’s Triangle (brute force)
Approach: Compute nCr for every column
Time    : O(n^2)
Space   : O(1) extra (excluding output)
-----------------------------------------
*/
vector<int> printRow_brute(int n)
{
     vector<int> ans;
     for (int c = 0; c <= n; c++)
     {
          ans.push_back(printNth_elementBasic(n, c));
     }
     return ans;
}

/*
-----------------------------------------
Function: printRow_Optimal
Purpose : Prints the nth row of Pascal’s Triangle (optimal)
Approach: Use relation between consecutive elements
          nCk = nC(k-1) * (n-k+1) / k
Time    : O(n)
Space   : O(1) extra (excluding output)
-----------------------------------------
*/
vector<int> printRow_Optimal(int n)
{
     int prev = 1;
     vector<int> ans;
     ans.push_back(prev); // nC0 = 1

     for (int c = 1; c <= n; c++)
     {
          prev = prev * (n - c + 1) / c;
          ans.push_back(prev);
     }
     return ans;
}

/*
-----------------------------------------
Function: PascalTriangleBrute
Purpose : Prints first n rows of Pascal’s Triangle
Approach: Build each row optimally
Time    : O(n^2)
Space   : O(n^2) (for storing triangle)
-----------------------------------------
*/
vector<vector<int>> PascalTriangleOptimal(int n)
{
     vector<vector<int>> Ans;
     for (int i = 0; i < n; i++)
     {
          Ans.push_back(printRow_Optimal(i));
     }
     return Ans;
}

int main()
{
     // Print 5th row of Pascal’s Triangle
     vector<int> arr = printRow_Optimal(5);
     for (auto x : arr)
     {
          cout << x << " ";
     }
     cout << endl;
     vector<vector<int>> triArr = PascalTriangleOptimal(5);
     for (auto row : triArr)
     {
          for (auto x : row)
          {
               cout << x << " ";
          }
          cout << endl;
     }

     return 0;
}
