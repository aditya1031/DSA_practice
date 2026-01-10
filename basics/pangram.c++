#include <bits/stdc++.h>

using namespace std;

string pangrams(string s)
{

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    for (char c = 'a'; c <= 'z'; c++)
    {

        if (s.find(c) == string::npos)
        {
            return "not pangram";
        }
    }

    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    cout << "enter";
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
