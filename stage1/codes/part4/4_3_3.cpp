#include <iostream>

using namespace std;

int main()
{
    // 3、在嵌套循环语句中使用 break，退出内层循环
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 5)
            {
                break;
            }
            cout << "*"
                 << " ";
        }
        cout << endl;
    }

    /*
     * * * * *
     * * * * *
     * * * * *
     * * * * *
     * * * * *
     * * * * *
     * * * * *
     * * * * *
     * * * * *
     * * * * *
     */

    return 0;
}