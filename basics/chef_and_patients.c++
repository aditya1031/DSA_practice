#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        int x;
        cin >> n >> m >> x >> k;
        string s;
        cin >> s;
        int e = 0, o = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'E')
               e++;
            else
                o++;
        }
        int ed = m / 2, od = (m / 2 + m % 2);
        int sum = 0;
        while (ed > 0 && sum < n)
        {
            sum += min(x, e);
            e -= min(x, e);
            ed--;
        }
       
        while (od > 0 && sum < n)
        {
            sum += min(x, o);
            o -= min(x, o);
            od--;
          
        }
        
        if (sum >= n)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
