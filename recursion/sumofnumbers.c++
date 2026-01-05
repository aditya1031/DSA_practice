     #include <bits/stdc++.h>
using namespace std;

void sum_para_resus(int i, int sums)
{

    if (i == 1)
    {
        cout << sums;
        return;
    }

    sums = sums + i;
    sum_para_resus(i - 1, sums);
}

int sum_fun_recus(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return (n + sum_fun_recus(n - 1));
}

int fact(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return (n * fact(n - 1));
}

int main()
{
    int n;
    cout << "enter how many n: ";
    cin >> n;
    cout << fact(n);
}