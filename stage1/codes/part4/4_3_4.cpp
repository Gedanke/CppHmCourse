#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }
        cout << i << endl;
    }

    /*
        1
        3
        5
        7
        9
    */

    return 0;
}