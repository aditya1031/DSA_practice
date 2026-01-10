#include <iostream>
using namespace std;
int main()
{
    int a = 0;
    int b = 1;
    int n = 10, nextTerm = 0;
    cout << "Enter the nu you want to find the fibonachi of:";
    // cin >> n;
cout<<a<<" "<<b<<" ";
    for (int i = 3; i <= n; i++)
    {

        nextTerm = a + b;
        a = b;
        b = nextTerm;

        cout << nextTerm << " ";
    }
}