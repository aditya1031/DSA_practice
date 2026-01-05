// aditya kumar
// 21bcs9520

#include <bits/stdc++.h>
using namespace std;

void inssort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];

        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void brutemethod(int arr[], int n)
{

    inssort(arr, n);

    cout << "largest element is :" << arr[n - 1] << endl;
    int seclargest = arr[n - 2];
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] != arr[n - 1])
        {
            seclargest = arr[i];
            break;
        }
    }

    cout << "second largest" << seclargest << endl;
}

void better(int arr[], int n)  //O(2n)
{
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    cout << "largest element is :" << largest << endl;

    int sec = -1; // only do this for all positve no.

              for (int i = 0; i < n; i++)
    {
        if (arr[i] > sec && arr[i] != largest)
        {
            sec = arr[i];
        }
    }
    cout << " second largest element is :" << sec << endl;
}


void best(int arr[],int n)    //O(n)
{

int largest=arr[0];
int sec=INT_MIN;

for (int i = 1; i < n; i++)
{
    if(arr[i]>largest)
    {
        sec=largest;
        largest=arr[i];
    }
    else if(arr[i]<largest && arr[i]>sec)
    {
        sec=arr[i];
    }
   
    
}
 cout<<"largest element is :"<<largest<<endl;
    cout<<"second largest element is :"<<sec<<endl;


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

    // brutemethod(arr, n);

    better(arr, n);
    return 0;
}