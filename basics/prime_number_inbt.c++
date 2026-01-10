#include <iostream>
using namespace std;
int main()
{
    int num;
    bool is_prime = 1;
    cout << "enter the limit to find prime number";
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        for (int j = 2; j < i; j++)
        {
            if ((i % j) == 0)
            {
                is_prime = 0;
                break;
            }
        }
        if (is_prime == 1)
        {
            cout << i << endl;
        }

        is_prime = 1;
    }
}

/*
#include<iostream>
using namespace std;
int main()
{
    int i, chk=0, j,num;

    cout<<"Prime Numbers Between 1to num\n";
    cin>>num;
    for(i=1; i<=num; i++)
    {
        for(j=2; j<i; j++)
        {
           if(i%j==0)
           {
               chk++;
               break;
           }
        }
        if(chk==0 && i!=1)
            cout<<i<<endl;
        chk = 0;
    }
    cout<<endl;
    return 0;
}*/