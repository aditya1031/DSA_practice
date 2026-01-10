// aditya kumar
// 21bcs9520

#include <iostream>
using namespace std;

void swapalternate(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
}

int main()
{
    int arr[100], size;
    cout << "Enter the array size" << endl;
    cin >> size;
    cout << "enter array elementes" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "original array is:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    swapalternate(arr, size);
    cout << "original array is:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}