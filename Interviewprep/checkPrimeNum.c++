#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    bool isprime = true;

    if (n <= 1)
    {
        isprime = false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if ((n % i) == 0)
        {
            isprime = false; /* code */
            break;
        }
    }

    if (isprime)
    {
        cout << " prime";
    }
    else
    {
        cout << "not prime";
    }
}