// aditya kumar
// 21bcs9520

#include <iostream>
using namespace std;

double power(double base, int pow)
{

    if (pow == 0)
        return 1;

    double halfPower = power(base, pow / 2);

    if (pow % 2 == 0)
        return halfPower * halfPower;

    else if (pow < 0)
        return (1 / base) * halfPower * halfPower;

    else
        return base * halfPower * halfPower;
}

int main()
{
    double base;
    int pow;
    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the ebaseponent: ";
    cin >> pow;

    cout << base << " raised to the power " << pow << " is: " << power(base, pow) << endl;
    return 0;
}
