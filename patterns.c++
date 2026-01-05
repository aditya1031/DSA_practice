#include <iostream>
using namespace std;

void print1(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for (int j = 0; j < n; j++)
        {
            cout << " * ";
        }
    }
}

void print2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " * ";
        }
        cout << endl;
    }
}

void print3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1;
        }
        cout << endl;
    }
}

void print4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void print5(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

void print6(int n)
{

    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - i - 1; j++)
        {

            cout << " ";
        }

        // starts
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < n - i - 1; j++)
        {

            cout << " ";
        }

        cout << endl;
    }
}

void print7(int n)
{

    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < i; j++)
        {

            cout << " ";
        }

        // starts
        for (int j = 0; j < 2 * n - (2 * i + 1); j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < i; j++)
        {

            cout << " ";
        }

        cout << endl;
    }
}

void print8(int n)
{

    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - i - 1; j++)
        {

            cout << " ";
        }

        // starts
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < n - i - 1; j++)
        {

            cout << " ";
        }

        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < i; j++)
        {

            cout << " ";
        }

        // starts
        for (int j = 0; j < 2 * n - (2 * i + 1); j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < i; j++)
        {

            cout << " ";
        }

        cout << endl;
    }
}

void print9(int n)
{

    for (int i = 0; i < 2 * n; i++)
    {
        int stars = i;
        if (i > n)
        {

            stars = 2 * n - i;
        }

        for (int j = 0; j < stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void print10(int n)
{

    int start = 1;

    for (int i = 0; i < n; i++)
    {

        if (i % 2 == 0)
        {
            start = 1;
        }
        else
        {
            start = 0;
        }
        for (int j = 0; j <= i; j++)
        {

            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}

void print11(int n)
{

    int space = 2 * (n - 1);

    for (int i = 1; i <= n; i++)
    {
        // numbers
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }

        // space
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }

        // numbers
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
        space -= 2;
    }
}

void print12(int n)
{

    int num = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << num << " ";
            num = num + 1;
        }
        cout << endl;
    }
}

void print13(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char j = 'A'; j <= 'A' + (n - i - 1); j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void print14(int n)
{

    for (int i = 0; i < n; i++)
    {

        char ch = 'A' + i;
        for (char j = 0; j <= i; j++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void print15(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Print leading spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  "; // Two spaces for alignment
        }

        // Print ascending characters
        char ch = 'A';
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
            ch++;
        }

        // Print descending characters
        ch -= 2;
        for (int j = 0; j < i; j++)
        {
            cout << ch << " ";
            ch--;
        }

        cout << endl;
    }
}

void print16(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (char ch = 'E' - i; ch <= 'E'; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void print17(int n)
{
int space = 0;

    // Top Half
    for (int i = 0; i < n; i++) {
        // Left stars
        for (int j = 0; j < n - i; j++) {
            cout << "*";
        }

        // Spaces
        for (int j = 0; j < space; j++) {
            cout << " ";
        }

        // Right stars
        for (int j = 0; j < n - i; j++) {
            cout << "*";
        }

        space += 2;
        cout << endl;
    }

    space = 2 * (n - 1); // Reset space for bottom half

    // Bottom Half
    for (int i = 1; i <= n; i++) {
        // Left stars
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        // Spaces
        for (int j = 0; j < space; j++) {
            cout << " ";
        }

        // Right stars
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        space -= 2;
        cout << endl;
    }
    
}

int main()
{

    int n;
    cin >> n;
    print17(n);
}