#include <bits/stdc++.h>
using namespace std;
int cnt =0;
void recursion()
{

    if (cnt == 4)
        return;

    cout << cnt << endl;

    cnt++;

    recursion();
}

void nameptin(int i,int n)
{

    //O(n)
    
    if (i == n)
          return;

    cout << "aditya" << endl;
    i++;
    nameptin(i, n);
}
