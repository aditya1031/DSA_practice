#include <bits/stdc++.h>
using namespace std;
/*
    Function to calculate the Maximum Matrix Sum
    Idea:
    - We can change sing of any two adjacent elements' to maximize the sum.
    - Key observation: the parity (even/odd) of negative numbers in the matrix never changes.
    - So, we can make all numbers positive if the count of negative numbers is even.
    - If the count of negative numbers is odd, one number must remain negative.
      To maximize the sum , the last remain negative number should be the smallest in absolute value.
    - Algorithm:
        1. Iterate the matrix and:
            - Count the number of negative numbers (negcnt)
            - Find the minimum absolute value (mini)
            - Sum the absolute values of all elements (sum)
        2. If negcnt is odd, subtract 2 * mini from sum (forced negative)
        3. Return sum
*/

long long maxMatrixSum(vector<vector<int>> &matrix)
{
     int row = matrix.size();
     int col = matrix[0].size();
     int mini = INT_MAX; // Smallest absolute value in the matrix
     long long sum = 0;  // Sum of absolute values of all elements
     int negcnt = 0;     // Count of negative numbers

     for (int i = 0; i < row; i++)
     {
          for (int j = 0; j < col; j++)
          {
               int val = abs(matrix[i][j]); // Take absolute value

               if (matrix[i][j] < 0) // Count negative numbers
               {
                    negcnt++;
               }

               sum += val; // Add absolute value to sum

               mini = min(mini, val); // Update minimum absolute value
          }
     }

     // If count of negatives is odd, one negative must remain
     if (negcnt % 2 == 1)
     {
          sum -= 2LL * mini; // Subtract smallest absolute value twice
     }

     return sum;
}

int main()
{
     // Example: 3x3 matrix
     vector<vector<int>> matrix = {
         {-1, 2, -3},
         {4, -5, 6},
         {7, 8, 9}};

     cout << "Maximum Matrix Sum: " << maxMatrixSum(matrix) << endl;

     return 0;
}
