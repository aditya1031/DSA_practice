#include <bits/stdc++.h>

using namespace std;

bool isArmstrong(int num)
{
     int og=num;
     long long res = 0;
     while (num)
     {
          int digit = num % 10;
          res += digit*digit*digit;
          num = num / 10;
     }
     if (res == og)
     {
          return true;
     }
     return false;
}

int main()
{
     int num = 153;
     cout << isArmstrong(num);

     return 0;
}