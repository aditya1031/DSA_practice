#include <iostream>
using namespace std;

int factorial(int num)
{
    if (num <= 1)
    {
        return 1;
    }
    return num * factorial(num - 1);
}

int factorialBetter(int num)
{
    int ans = 1;
    for (int i = 1; i <= num; i++)
    {
        ans *= i;
    }
    return ans;
}

int main()
{
    int n = 5;
    cout << factorialBetter(n);
}