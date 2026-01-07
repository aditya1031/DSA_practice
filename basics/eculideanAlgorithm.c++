#include <bits/stdc++.h>
using namespace std;
/* Euclidean algorithm to find the GCD (Greatest Common Divisor) of two numbers*/
/*

TC O(log^phai(min(a,b)))

*/
void eculidean(int n1, int n2)
{

    while (n1 > 0 && n2 > 0)
    {
        if (n1 > n2)
            n1 = n1 % n2;
        else
            n2 = n2 % n1;
    }

    if (n1 == 0)
        cout << n2;
    else
        cout << n1;
}

int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    eculidean(num1, num2);
}