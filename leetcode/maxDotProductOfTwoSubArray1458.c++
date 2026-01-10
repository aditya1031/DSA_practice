//git - aditya1031

#include <bits/stdc++.h>
using namespace std;


    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        const int min = INT_MIN;

        // dp[i][j] = max dot product using nums1[0..i] and nums2[0..j]
        vector<vector<int>> dp(n, vector<int>(m, min));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int product = nums1[i] * nums2[j];

                int best = product; // start new subsequence

                if (i > 0 && j > 0)
                    best = max(best, dp[i-1][j-1] + product);

                if (i > 0)
                    best = max(best, dp[i-1][j]);

                if (j > 0)
                    best = max(best, dp[i][j-1]);

                dp[i][j] = best;
            }
        }

        return dp[n-1][m-1]; 
    }





int main()
{


return 0;
}