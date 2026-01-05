#include <iostream>
using namespace std;

bool pali(int i, string s)
{

//O(n/2)
    if (i >= s.size() / 2)
    {
        return true;
    }

    if (s[i] != s[s.size() - i - 1])
    {
        return false;
    }

    return pali(i + 1, s);
}

int main()
{

    string s;

    cin >> s;

    if (pali(0, s))
        cout << "true";
    else
        cout << "false";

    return 0;
}