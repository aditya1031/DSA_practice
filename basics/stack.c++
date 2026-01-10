// aditya kumar
// 21bcs9520
#include<iostream>
#include <stdio.h>
using namespace std;
int stack[15], i, j;
int choice = 0, n, top = -1;
void push();
void pop();
void show();

int main()
{

    cout<<"Enter the number of elements in the stack ";
    cin>>n;
    cout<<"*********Stack operations using array*********";

    cout<<"\n----------------------------------------------\n";
    while (choice != 4)
    {
        cout<<"\nChose one from the below options...\n"<<endl;
        cout<<"\n1.Push\n2.Pop\n3.Show\n4.Exit"<<endl;
        cout<<"\n Enter your choice \n"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            show();
            break;
        }
        case 4:
        {
            cout<<"Exiting....\n";
            break;
        }
        default:
        {
            cout<<"Please Enter valid choice \n";
        }
        };
    }
}

void push()
{
    int val;
    if (top == n)
        cout<<"\n Overflow";
    else
    {
        cout<<"Enter the value?\n";
        cin>>val;
        top = top + 1;
        stack[top] = val;
    }
}

void pop()
{
    if (top == -1)
        cout<<"Underflow\n";
    else
        top = top - 1;
}
void show()
{
    for (i = top; i >= 0; i--)
    {
        cout<< stack[i]<<"|";
    }
    if (top == -1)
    {
        cout<<"Stack is empty\n";
    }
}