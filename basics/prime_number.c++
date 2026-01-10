#include <iostream>
using namespace std;
int main()
{
    int num;
    cin >> num;
    bool is_prime = 1;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            is_prime = 0;
            break;
        }
    }
    if (is_prime == 0)
    {
        cout << "is not prime";
    }
    else
    {
        cout << "is prime";
    }
}