#include <iostream>

using namespace std;

int main()
{

    // 外层循环执行 1 次，内层循环执行 1 轮
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << "*"
                 << " ";
        }
        cout << endl;
    }

    /*
     * * * * * * * * * *
     * * * * * * * * * *
     * * * * * * * * * *
     * * * * * * * * * *
     * * * * * * * * * *
     * * * * * * * * * *
     * * * * * * * * * *
     * * * * * * * * * *
     * * * * * * * * * *
     * * * * * * * * * *
     */

    return 0;
}