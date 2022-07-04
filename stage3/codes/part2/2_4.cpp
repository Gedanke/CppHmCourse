#include <iostream>

using namespace std;

// 返回局部变量引用
// int &test01()
// {
//     // 局部变量，栈区
//     int a = 10;
//     return a;
// }

// 返回静态变量引用
int &test02()
{
    static int a = 20;
    return a;
}

int main()
{
    // 不能返回局部变量的引用
    // int &ref = test01();
    // cout << "ref = " << ref << endl;

    /*
        main.cpp: In function ‘int& test01()’:
        main.cpp:10:12: warning: reference to local variable ‘a’ returned [-Wreturn-local-addr]
            10 |     return a;
               |            ^
        main.cpp:9:9: note: declared here
             9 |     int a = 10;
               |         ^
        Segmentation fault
    */

    // 静态变量存放在全局区
    // 如果函数做左值，那么必须返回引用
    int &ref2 = test02();
    cout << "ref2 = " << ref2 << endl;

    test02() = 1000;

    cout << "ref2 = " << ref2 << endl;

    /*
        ref2 = 20
        ref2 = 1000
    */

    return 0;
}