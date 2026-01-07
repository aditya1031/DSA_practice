#include <iostream>
using namespace std;

int main()
{
    cout << "enter you age" << endl;
    int age;
    cin >> age;
    if (age <= 18)
    {
        cout << "you are a minor" << endl;
    }
    else if (age > 18 && age <= 65)
    {
        cout << "you are an adult" << endl;
    }
    else if (age >65)
        {
            cout << "you are an sinior citizen" << endl;
        }

    return 0;
}