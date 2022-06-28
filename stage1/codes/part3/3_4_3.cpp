#include <iostream>

using namespace std;

int main()
{
    // 逻辑运算符  --- 或

    int a = 10;
    int b = 10;
    cout << (a || b) << endl; // 1

    a = 10;
    b = 0;
    cout << (a || b) << endl; // 1

    a = 0;
    b = 0;
    cout << (a || b) << endl; // 0

    return 0;
}