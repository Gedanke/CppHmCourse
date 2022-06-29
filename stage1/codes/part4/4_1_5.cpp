#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a > b)
    {
        if (c > a)
        {
            cout << c << endl;
        }
        else
        {
            cout << a << endl;
        }
    }
    else
    {
        if (c > b)
        {
            cout << c << endl;
        }
        else
        {
            cout << b << endl;
        }
    }

    /*
        2 1 3
        3
    */

    return 0;
}