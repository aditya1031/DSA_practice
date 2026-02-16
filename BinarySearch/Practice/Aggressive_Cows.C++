// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int> &nums, int dist, int cows)
{

    int countCows = 1;
    int last = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] - last >= dist)
        {
            countCows++;
            last = nums[i];
        }

        if (countCows >= cows)
        {
            return true;
        }
    }

    return false;
}

int maxDistanceBrute(vector<int> &nums, int cows)
{
    sort(nums.begin(), nums.end());
    int mini = *min_element(nums.begin(), nums.end());
    int maxi = *max_element(nums.begin(), nums.end());

    for (int i = 1; i <= maxi - mini; i++)
    {
        if (canPlace(nums, i, cows))
        {
            continue;
        }
        else
        {
            return i - 1;
        }
    }
    return -1;
}




int canPlaceBS(vector<int> &nums, int dist)
{

    int countCows = 1;
    int last = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] - last >= dist)
        {
            countCows++;
            last = nums[i];
        }
    }

    return countCows;
}

int maxDistanceOptimal(vector<int> &nums, int cows)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int high = nums.back() - nums.front();

    int low = 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int placedCows = canPlaceBS(nums, mid);
        if (placedCows >= cows)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{

    return 0;
}