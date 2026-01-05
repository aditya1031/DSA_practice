#include <iostream>
 using namespace std;

 int main(){
    string name ="aditya";
    string rev;
    for (int i = name.length()-1; i >=0; i--)
    {
        rev=rev+name[i];
    }
  cout<<rev;  

  if (name==rev)

  {
  cout<<"ispalidrome";  /* code */
  }
  else
  {
    cout<<"not";
  }
  
 }