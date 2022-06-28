#include <iostream>

using namespace std;

int main()
{
    // 取模
    int a1 = 10;
    int b1 = 3;

    cout << 10 % 3 << endl;

    int a2 = 10;
    int b2 = 20;

    cout << a2 % b2 << endl;

    int a3 = 10;
    int b3 = 0;

    // cout << a3 % b3 << endl; // 取模运算时，除数也不能为 0

    // 两个小数不可以取模
    double d1 = 3.14;
    double d2 = 1.1;

    // cout << d1 % d2 << endl;

    /*
        1
        10
    */

    return 0;
}