  #include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void printdev(int x)
{
    for (int i = 1; i <= x; i++)
    {
        if ((x % i) == 0)
        {
            cout << i << " ";
        }
    }
}

void optimum(int x)
{
    vector<int> ls;
   for (int i = 1; i*i <= x; i++)

    {
        if (x % i == 0)
        {
            ls.push_back(i);
            if (i!=(x / i) )
            {
                ls.push_back(x / i);
            }
        }
    }

    sort(ls.begin(),ls.end());
    for(int it:ls) 
    {
        cout<<it<<" ";
    }
}

int main()
{

    int num;
    cin >> num;
    //printdev(num);
    optimum(num);
}