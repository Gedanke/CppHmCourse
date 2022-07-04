#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int &b = a;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    b = 100;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    a = 1000;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    /*
        a = 10
        b = 10
        a = 100
        b = 100
        a = 1000
        b = 1000
    */

    return 0;
}