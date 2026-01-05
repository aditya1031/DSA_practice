#include<iostream>
using namespace std;

int main(){

int n=12345678;
int rev=0;

while (n>0)
{
    rev=rev*10+n%10;
    n=n/10;
}
cout<<rev;


}
