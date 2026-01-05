#include <iostream>
using namespace std;

int main()
{

    string s;
    cout<<"enter the string";
    cin >> s;
    // precompute

    int hash[256] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        hash[(unsigned char)s[i]] += 1;
    }

    cout << "enter the number of test case" << endl;

    int q;
    cin >> q;

    while (q--)
    {
        char ch;
        cin >> ch;

        // fetch
        cout << "the number in arr accured by:";
        cout << hash(unsigned char)[ch] << endl;
    }
}