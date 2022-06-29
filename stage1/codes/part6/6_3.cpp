#include <iostream>

using namespace std;

// 函数定义
int add(int num1, int num2) // 定义中的 num1，num2 称为形式参数，简称形参
{
    int sum = num1 + num2;
    return sum;
}

int main()
{
    int a = 10;
    int b = 10;
    // 调用 add 函数
    int sum = add(a, b); // 调用时的 a，b 称为实际参数，简称实参
    cout << "sum = " << sum << endl;

    a = 100;
    b = 100;

    sum = add(a, b);
    cout << "sum = " << sum << endl;

    /*
        sum = 20
        sum = 200
    */

    return 0;
}