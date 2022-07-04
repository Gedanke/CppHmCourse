#include <iostream>

using namespace std;

int func(int a, int b = 10, int c = 10)
{
    return a + b + c;
}

// 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
// 如果函数声明有默认值，函数实现的时候就不能有默认参数，声明与实现只能一个有默认参数
int func2(int a = 10, int b = 10);

int main()
{

    cout << "ret = " << func(100) << endl;
    cout << "ret = " << func(20, 20) << endl;
    cout << "ret = " << func(20, 20, 20) << endl;

    cout << "ret = " << func2() << endl;
    cout << "ret = " << func2(1) << endl;
    cout << "ret = " << func2(1, 1) << endl;

    /*
        ret = 120
        ret = 50
        ret = 60
        ret = 20
        ret = 11
        ret = 2
    */

    return 0;
}

int func2(int a, int b)
{
    return a + b;
}