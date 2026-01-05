// aditya kumar
// 21bcs9520

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums) // brute  O(nlogn)
{

    set<int> temp;
    for (int i = 0; i < nums.size(); i++)
        temp.insert(nums[i]);

    int i = 0;
    for (auto it : temp)
    {
        nums[i] = it;
        i++;
    }

    return i;
}

int removedublicates(vector<int> &nums)
{
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != nums[j])
        {
            nums[j + 1] = nums[i];
            j++;
        }
    }
    return j + 1;
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
    int newSize = removeDuplicates(arr);
    cout << "Array after removing duplicates:\n";
    for (int i = 0; i < newSize; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}