#include <iostream>
using namespace std;

int reversenum(int n)
{
    int revnum = 0;
    while (n > 0)
    {
        int lastdigit = n % 10;
        revnum = (revnum * 10) + lastdigit;
        n = n / 10;
    }

    return revnum;
}

int main()
{

    int n;
    cin >> n;
    cout << reversenum(n);
}