#include <iostream>

using namespace std;

int main()
{
    // 1、指针的定义
    int a = 10; // 定义整型变量 a

    // 指针定义语法： 数据类型 * 变量名;
    int *p;

    // 指针变量赋值
    p = &a;             // 指针指向变量 a 的地址
    cout << &a << endl; // 打印数据 a 的地址
    cout << p << endl;  // 打印指针变量 p

    // 2、指针的使用
    // 通过 * 操作指针变量指向的内存
    cout << "*p = " << *p << endl;

    /*
        0x7ffeff66ba3c
        0x7ffeff66ba3c
        *p = 10
    */

    return 0;
}