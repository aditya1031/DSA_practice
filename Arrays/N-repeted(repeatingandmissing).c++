// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

vector<int> findErrorNums1(vector<int> &nums)
{
    int miss = -1, dup = -1;
    for (int i = 1; i <= nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == i)
            {
                count++;
            }
        }
        if (count == 2)
        {
            dup = i;
        }
        else if (count == 0)
        {
            miss = i;
        }
    }
    return {dup, miss};
}

vector<int> findErrorNums2(vector<int> &nums)
{
    int miss = -1, dup = -1;
    int n = nums.size();
    vector<int> hash(n + 1, 0);
    for (int i = 1; i <= nums.size(); i++)
    {
        hash[nums[i]]++;
    }

    for (int i = 1; i <= nums.size(); i++)
    {
        if (hash[i] == 2)
        {
            dup = i;
        }
        else if (hash[i] == 0)
        {
            miss = i;
        }
    }

    return {dup, miss};
}

vector<int> findErrorNums3(vector<int> &nums)
{
    int n = nums.size();

    // sum-sumofN naturel =(x-y)
    long long SN = (n * (n + 1)) / 2;
    // s^2 - S^2N = (x-y)^2
    long long S2N = (long long)(n * (n + 1) * (2 * n + 1)) / 6;
    long long S = 0;
    long long S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += nums[i];
        S2 += ((long long)nums[i] * (long long)nums[i]);
    }
    int val1 = S - SN; // x-y
    int val2 = S2 - S2N;
    val2 = val2 / val1; // x+y

    int x = (val1 + val2) / 2;
    int y = x - val1;

    return {(int)x, (int)y};
}



vector<int> findErrorNums4(vector<int> &nums)
{
     
        // size of the array
        int n = nums.size(); 

        int xr = 0;

        for (int i = 0; i < n; i++) {
            // XOR of all elements in nums
            xr = xr ^ nums[i]; 
            
            // XOR of numbers from 1 to n
            xr = xr ^ (i + 1);  
        }

        // Get the rightmost set bit in xr
        int number = (xr & ~(xr - 1));

        //Group the numbers based on the differentiating bit
        // Number that falls into the 0 group
        int zero = 0; 
        
        // Number that falls into the 1 group
        int one = 0;  

        for (int i = 0; i < n; i++) {
            
            /* Check if nums[i] belongs to the 1 group
            based on the differentiating bit*/
            if ((nums[i] & number) != 0) {
                
                // XOR operation to find numbers in the 1 group
                one = one ^ nums[i];
                
            } else {
                // XOR operation to find numbers in the 0 group
                zero = zero ^ nums[i]; 
            }
        }

        // Group numbers from 1 to n based on differentiating bit
        for (int i = 1; i <= n; i++) {
            
            /* Check if i belongs to the 1 group 
            based on the differentiating bit*/
            if ((i & number) != 0) {
                
                // XOR operation to find numbers in the 1 group
                one = one ^ i; 
                
            } else {
                // XOR operation to find numbers in the 0 group
                zero = zero ^ i; 
            }
        }

        // Count occurrences of zero in nums
        int cnt = 0; 

        for (int i = 0; i < n; i++) {
            if (nums[i] == zero) {
                cnt++;
            }
        }

        if (cnt == 2) {
            /*zero is the repeating number,
            one is the missing number*/
            return {zero, one}; 
        }
        
        /* one is the repeating number, 
        zero is the missing number*/
        return {one, zero}; 
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

    int k = 0;
    cin >> k;

    findErrorNums2(arr);

    return 0;
}