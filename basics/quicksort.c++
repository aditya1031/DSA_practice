/*#include <iostream>
using namespace std;




void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}





int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}




void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        
        quicksort(arr, pi + 1, high);
    }
}





int main()
{
    int arr[10] ;
    int n = 10;
    
    
    cout << "enter array: \n"; 
    for (int i = 0; i < n; i++)
        cin>> arr[i] ;
    cout << endl;
    
    
    
    quicksort(arr, 0, n - 1);
    
   
   

    cout << "Sorted array: \n";
     for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    
    return 0;
}
*/


#include<iostream> 
using namespace std; 
int partition(int *arr,int s,int e){   int pivot = arr[s];   int cnt=0; 
for(int i = s+1; i<=e; i++){     if(arr[i] <=pivot){       cnt++; 
    } 
 } 
int pivotIndex = s+cnt;   swap(arr[pivotIndex],arr[s]); 
int i=s, j=e;   while(i<pivotIndex && j>pivotIndex){ 
while(arr[i] <= pivot){       i++; 
    } 
while(arr[j]>pivot){ 
      j--; 
    } 
    if(i<pivotIndex && j>pivotIndex){ 
      swap(arr[i++],arr[j--]); 
    } 
  } 
  return pivotIndex; 
} 
 
void quickSort(int *arr,int s,int e){ 
  if(s>=e){ 
    return; 
  } 
  int p = partition(arr,s,e); 
 
  quickSort(arr,s,p-1); 
 
  quickSort(arr,p+1,e); 
} 
int main(){ 
  int arr[20]; 
  cout<<"Enter the size of the array"<<endl; 
  int size; 
  cin>>size;   cout<<"Enter the elements"<<endl;   for(int i=0;i<size;i++){ 
    cin>>arr[i]; 
  } 
  cout<<"Elements before sorting"<<endl; 
  for(int i=0;i<size;i++){ 
    cout<<arr[i]<<" "; 






  } 
  quickSort(arr,0,size-1);   cout<<endl; 
  cout<<"Elements after sorting"<<endl; 
  for(int i=0;i<size;i++){ 
    cout<<arr[i]<<" "; 
  } 
  cout<<endl; 
  return 0; 
}  
