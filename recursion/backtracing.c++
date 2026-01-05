#include <bits/stdc++.h>
using namespace std;

void leniar(int i, int n)
{

    // O(n)

    if (i == 0)
        return;

    leniar(i-1, n);
    cout << i << endl;
    
}

void lenia(int i, int n)
{

    // O(n)

    if (i == n)
        return;

    lenia(i+1, n);
    cout << i << endl;
    
}

int main()
{
    int n;
    cout << "enter how many time name should be printed: ";
    cin >> n;
    lenia(0, n);
}