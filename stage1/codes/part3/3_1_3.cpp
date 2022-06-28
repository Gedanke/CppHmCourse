#include <iostream>

using namespace std;

int main()
{
    // 递增

    // 后置递增
    int a = 10;
    a++;               // 等价于 a = a + 1
    cout << a << endl; // 11

    // 前置递增
    int b = 10;
    ++b;
    cout << b << endl; // 11

    // 区别

    // 前置递增先对变量进行 ++，再计算表达式
    int a2 = 10;
    int b2 = ++a2 * 10;
    cout << b2 << endl;

    // 后置递增先计算表达式，后对变量进行 ++
    int a3 = 10;
    int b3 = a3++ * 10;
    cout << b3 << endl;

    int num1 = 10;
    int num2 = 10;
    cout << num1++ * ++num2 << endl;
    cout << num1 << " " << num2 << endl;

    /*
        11
        11
        110
        100
        110
        11 11
    */

    return 0;
}