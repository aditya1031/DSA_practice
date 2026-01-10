// aditya kumar
// 21bcs9520

#include <iostream>
#include <algorithm> 
using namespace std;

int main()
{
    int x, y;
    
    cout << "Enter the size of array: ";
    cin >> x;
    
    int arr[x], flag[x] = {0};

    cout << "Enter the elements for the array: \n";
    for (int i = 0; i < x; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + x);

    cout << "\nArray after sorting:\n";
    
    for (int i = 0; i < x;)
    {
        int count = 1; 
        
        int j = i + 1;
        while(j < x && arr[i] == arr[j]) 
        {
            count++;
            j++;
        }

        cout << "no of times the value --> " << arr[i] << " occurred is --> " << count << endl << endl;
        
        i = j; 
    }

    return 0;
}
