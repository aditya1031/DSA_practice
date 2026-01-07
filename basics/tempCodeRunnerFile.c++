
    int space = 0;
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }

        // spaces
        for (int j = 0; j < space; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        space += 2;
        cout << endl;
    }

     space=8;
    for (int i = 1; i < n; i++)
    {
        // stars
        for (int j = 0; j <  i; j++)
        {
            cout << "*";
        }

        // spaces
        for (int j = 0; j < space; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        space -= 2;
        cout << endl;
    }