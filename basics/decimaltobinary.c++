// aditya kumar
// 21bcs9520

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int num, i=0;
    int ans = 0;
    cout << "Enter the number" << endl;
    cin >> num;
    while (num != 0)
    {
        int bit = num & 1;
        ans = (bit * pow(10, i) ) + ans;
        num = num >> 1;
        cout<<ans;
        i++;
    }
    cout << "binary of given number is --> " << ans;
}