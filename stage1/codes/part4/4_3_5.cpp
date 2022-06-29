#include <iostream>

using namespace std;

int main()
{

    cout << "1" << endl;

    goto FLAG;

    cout << "2" << endl;
    cout << "3" << endl;
    cout << "4" << endl;

FLAG:
{
    cout << "5" << endl;
    cout << "6" << endl;
}

    /*
        1
        5
        6
    */

    return 0;
}