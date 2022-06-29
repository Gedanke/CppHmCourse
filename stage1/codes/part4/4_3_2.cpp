#include <iostream>

using namespace std;

int main()
{
    // 2、在循环语句中用 break
    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            break; // 跳出循环语句
        }
        cout << i << endl;
    }

    /*
        0
        1
        2
        3
        4
    */

    return 0;
}