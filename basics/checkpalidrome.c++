#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void checkpalidrome(int x)
{
    int num;
    num = x;
    long long rev = 0;
    while (x != 0)
    {
        int lastDigit = x % 10;
        rev = rev * 10 + lastDigit;
        x = x / 10;
    }

    if (num == rev)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}

int main()
{

    int num;
    cin >> num;
    checkpalidrome(num);
}