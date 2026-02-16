// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

int cntStudent(vector<int> &nums, int pages)
{
     int student = 1;
     int pagesStudent = 0;
     for (int i = 0; i < nums.size(); i++)
     {
          if (pagesStudent + nums[i] <= pages)
          {
               pagesStudent += nums[i];
          }
          else
          {
               student++;
               pagesStudent = nums[i];
          }
     }

     return student;
}

int bookAllocBrute(vector<int> &nums, int m)
{
     int low = *max_element(nums.begin(), nums.end());
     int high = 0;
     for (auto x : nums)
     {
          high += x;
     }

     for (int i = low; i <= high; i++)
     {
          int cntStu = cntStudent(nums, i);
          if (cntStu <= m)
          {
               return i;
          }
     }
     return -1;
}

int bookAllocOptimal(vector<int> &nums, int m)
{
     if (m > nums.size()) return -1;

     int low = *max_element(nums.begin(), nums.end());
     int high = 0;
     for (auto x : nums)
     {
          high += x;
     }

     while (low <= high)
     {
          int mid=(low+high)/2;
          int cntStu = cntStudent(nums, mid);
          if(cntStu>m)
          {
              low=mid+1;
          }
          else
          {
               high=mid-1;
          }
         
     }
     return low;
}

int main()
{

     return 0;
}