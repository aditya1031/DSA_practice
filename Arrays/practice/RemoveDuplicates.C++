#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> RemoveDuplicate(vector<int> &nums)
{
     int n = nums.size();
     vector<int> temp;
     for (int i = 0; i < n; i++)
     {
          if (temp.empty() || nums[i] != temp.back())
          {
               temp.push_back(nums[i]);
          }
     }

     for (int i = 0; i < temp.size(); i++)
     {
          nums[i] = temp[i];
     }

     return nums;
}
int removeDuplicates2(vector<int>& nums)
{
    int n = nums.size();
    if (n == 0) return 0;

    int j = 0;   // index of last unique element

    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[j])   // new unique element found
        {
            j++;
            nums[j] = nums[i];   // store it
        }
    }

    return j + 1;   // length of array without duplicates
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

     arr = RemoveDuplicate(arr);
     for (int i = 0; i < n; i++)
     {
          cout << arr[i] << " ";
     }

     return 0;
}