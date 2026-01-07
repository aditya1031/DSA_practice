#include<bits/stdc++.h>
using namespace std;

void gcd(int num1,int num2){

    int gcd=1;
    for (int i = min(num1,num2); i >=1; i--)
    {
        if(num1%i==0&&num2%i==0
        )
        {
            cout<<i;
            break;
        }
    }
    

}

int main(){
int num1 ,num2;
 cin>>num1>>num2;
gcd(num1,num2);
}