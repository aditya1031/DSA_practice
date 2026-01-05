#include <iostream>
using namespace std;

void countdigit(int num)
{  
      int count=0;
      while (num > 0)
    {
        int lastdigit = num % 10;
        cout << lastdigit << " ";
        count=count+1;
        num = num / 10;
    }
    cout<<count;
}

int main()
{

    int num;
    cin >> num;
               countdigit(num);
}