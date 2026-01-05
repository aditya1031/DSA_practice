#include<iostream>
using namespace std;

bool checkarmstrong(int x )
{

    int arm=0,t=0;
    t=x;
while (x!=0)
{
    int lasdigit=x%10;
    arm=arm+(lasdigit*lasdigit*lasdigit);
    x=x/10;
}

return arm==t;

}

int main(){
int num ;
cin >> num;
    if (checkarmstrong(num)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }


}