// aditya kumar
// 21bcs9520

#include <iostream>
#include <math.h>
using namespace std;
int main()
{

    int num, ans = 0, i = 0;
    cout << "Enter the number ";
    cin >> num;
    while (num != 0)
    {
        int bit = num %10;
        if (bit == 1)
        {
            ans = ans + (bit * pow(2, i));
        }
        num=num/10;
        i++;
    }
    cout << "the decimal of binary is :" << ans;
    return 0;
}