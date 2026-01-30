// git - aditya1031

#include <bits/stdc++.h>
using namespace std;


int first (vector<int>&nums,int x)
{
 int n= nums.size();

 int low=0;
 int high=n-1;
 int first=-1;
 while(low<=high)
 {
     int mid=low + (high - low) / 2;
     if(nums[mid]==x)
     {
          first=mid;
          high=mid-1;
     }
     else if(nums[mid]<x)
     {low=mid+1;
          
          
     }
     else{
           high=mid-1;

     }
 }
return first;

}



int last (vector<int>&nums,int x)
{
 int n= nums.size();

 int low=0;
 int high=n-1;
 int last=-1;
 while(low<=high)
 {
     int mid=low + (high - low) / 2;
     if(nums[mid]==x)
     {
          last=mid;
         low=mid+1;
     }
       else if(nums[mid]<x)
     {low=mid+1;
          
          
     }
     else{
           high=mid-1;

     }
 }
return last;

}



int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cin>>x;
int f = first(arr, x);
if (f == -1) cout << 0;
else cout << last(arr, x) - f + 1;


    return 0;
}