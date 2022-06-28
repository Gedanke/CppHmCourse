#include <iostream>

using namespace std;

int main()
{
    cout << "hello\\hello" << endl;
    cout << "hello\thello" << endl;
    cout << "hello\nhello"
         << endl;

    /*
        hello\hello
        hello   hello
        hello
        hello
    */

    return 0;
}