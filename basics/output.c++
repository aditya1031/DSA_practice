//aditya kumar
//21bcs9520

#include <iostream>
using namespace std;
int main()
{

for (int i = 0; i <=15; i+=2)
{

   // cout<<i<<" ";

    if (i&1)
    {
      cout<<(i&1);
continue;
    }
    
    i++;
}
//0 2 4
return 0;
}