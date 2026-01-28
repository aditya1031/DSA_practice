//aditya kumar
//21bcs9520

#include <bits/stdc++.h>
using namespace std;

int conse(int arr[],int n)
{
    int count=0;
    int max=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==1)
        {
            count++;
            if(max<count)
            {
                max=count;
            }
        }
        else{
            count=0;
        }
        
    }
return max;
    
}

int main()
{

      int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    

    cout << "missing number is " << conse(arr, n);
    return 0;


}