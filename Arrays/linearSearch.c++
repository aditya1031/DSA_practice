// aditya kumar
// 21bcs9520

#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int no)
{

    for (int i = 0; i < n; i++)
    {
        if(arr[i]==no)
        {
            return i;
            break;
        }
    }
    return -1;

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

    int no;

    cout << "Enter the no you want to search :" << endl;
    cin >> no;

    int ans;
    ans=search(arr,n,no);

    if(ans==-1)
    {
        cout<<" given number is not present in the array"<<endl;
    }
    else{
        cout<<"given number is  present in the array at "<< ans<<" index" <<endl;
    }

    return 0;
}
