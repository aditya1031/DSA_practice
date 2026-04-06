#include <iostream>
using namespace std;

void fibonacciBrute(int n)
{
    int l = 0;
    int r = 1;
    for (int i = 0; i < n; i++)
    {
        cout << l << " -> ";
        r = l + r;
        l = r - l;
    }
}

void fibonacciNth(int n)
{
    if (n <= 1)
    {
        cout << n;
        return;
    }
    int l = 0;
    int r = 1;
    for (int i = 2; i <= n; i++)
    {

        r = l + r;
        l = r - l;
    }
    cout << r;
}

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
    int n = 10;

    // fibonacciBrute(n);
    fibonacciNth(n);
    cout<<fibonacci(n);
}