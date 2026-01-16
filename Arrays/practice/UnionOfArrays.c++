// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

/*
 UNION USING MAP
 Idea:
 - Store frequency of all elements from both arrays in a map
 - Map keys are unique and sorted
 - Copy keys to answer

 Time Complexity: O((n1 + n2) log(n1 + n2))
 Space Complexity: O(n1 + n2)
*/
vector<int> Union_Using_Map(vector<int> &arr1, vector<int> &arr2)
{
     int n1 = arr1.size();
     int n2 = arr2.size();

     map<int, int> mpp;
     vector<int> ans;

     // insert elements of arr1
     for (int i = 0; i < n1; i++)
     {
          mpp[arr1[i]]++;
     }

     // insert elements of arr2
     for (int i = 0; i < n2; i++)
     {
          mpp[arr2[i]]++;
     }

     // extract unique elements
     for (auto it : mpp)
     {
          ans.push_back(it.first);
     }

     return ans;
}

/*
 UNION USING SET
 Idea:
 - Insert all elements of both arrays into a set
 - Set automatically removes duplicates and keeps sorted order

 Time Complexity: O((n1 + n2) log(n1 + n2))
 Space Complexity: O(n1 + n2)
*/
vector<int> Union_Using_Set(vector<int> &arr1, vector<int> &arr2)
{
     int n1 = arr1.size();
     int n2 = arr2.size();

     set<int> temp;
     vector<int> ans;

     for (int i = 0; i < n1; i++)
     {
          temp.insert(arr1[i]);
     }

     for (int i = 0; i < n2; i++)
     {
          temp.insert(arr2[i]);
     }

     for (auto s : temp)
     {
          ans.push_back(s);
     }

     return ans;
}

/*
 UNION USING TWO POINTERS (OPTIMAL)
 Condition:
 - Both arrays must be sorted

 Idea:
 - Compare elements using two pointers
 - Add smaller or equal element
 - Avoid duplicates using ans.back()

 Time Complexity: O(n1 + n2)
 Space Complexity: O(n1 + n2)  (output array)
*/
vector<int> Union_Using_TwoPointer(vector<int> &arr1, vector<int> &arr2)
{
     int n1 = arr1.size();
     int n2 = arr2.size();

     vector<int> ans;
     int left = 0, right = 0;

     while (left < n1 && right < n2)
     {
          if (arr1[left] < arr2[right])
          {
               if (ans.empty() || ans.back() != arr1[left])
                    ans.push_back(arr1[left]);
               left++;
          }
          else if (arr1[left] == arr2[right])
          {
               if (ans.empty() || ans.back() != arr1[left])
                    ans.push_back(arr1[left]);
               left++;
               right++;
          }
          else
          {
               if (ans.empty() || ans.back() != arr2[right])
                    ans.push_back(arr2[right]);
               right++;
          }
     }

     // remaining elements of arr1
     while (left < n1)
     {
          if (ans.empty() || ans.back() != arr1[left])
               ans.push_back(arr1[left]);
          left++;
     }

     // remaining elements of arr2
     while (right < n2)
     {
          if (ans.empty() || ans.back() != arr2[right])
               ans.push_back(arr2[right]);
          right++;
     }

     return ans;
}

int main()
{
     // hardcoded input
     int n = 5, m = 5;

     vector<int> arr1 = {1, 2, 3, 4, 5};
     vector<int> arr2 = {2, 3, 4, 4, 5};

     // choose any method
     vector<int> ans = Union_Using_TwoPointer(arr1, arr2);
     // vector<int> ans = Union_Using_Set(arr1, arr2);
     // vector<int> ans = Union_Using_Map(arr1, arr2);

     for (int x : ans)
     {
          cout << x << " ";
     }

     return 0;
}
