#include <iostream>
using namespace std;
int main()
{
    int a, b, c, la;
    cin >> a >> b >> c;
    la = a;
    if (la < b)
    {
        la = b;
    }
    if (la < c)
    {
        la = c;
    }
    cout << la;
}