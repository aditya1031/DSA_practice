#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
     int n = digits.size();
     int num = 0;
     for (int i = 0; i < n; i++)
     {
          num = num * 10 + digits[i];
     }

     num = num + 1;
     cout << num;
     for (int i = 0; i < n; i++)
     {

          digits[n - i - 1] = num % 10;
          num /= 10;
     }
     return digits;
}

vector<int> plusOne(vector<int> &digits)
{
     int n = digits.size();
     int num = 0;
     for (int i = n - 1; i >= 0; i--)
     {
          if (digits[i] < 9)
          {
               digits[i]++;
               return digits;
          }
          else
          {
               digits[i] = 0;
          }
     }
     digits.insert(digits.begin(),1);
     return digits;
}

int main()
{
     vector<int> arr;
     int count = 0, x = 0;
     cin >> count;
     for (int i = 0; i < count; i++)
     {
          cin >> x;
          arr.push_back(x);
     }

     plusOne(arr);

     for (int i = 0; i < count; i++)
     {
          cout << " " << arr[i] << " ";
     }
}