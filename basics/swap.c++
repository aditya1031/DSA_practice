#include<iostream>
using namespace std;
int main()
{
    int x,y,temp;
    cout<<"enter the first number";
    cin>>x;
    cout<<"enter the second number";
    cin>>y;
    temp=x;
    x=y;
    y=temp;
    cout<<"first number  :"<<x<<endl;
    cout<<"second number :"<<y<<endl;

}