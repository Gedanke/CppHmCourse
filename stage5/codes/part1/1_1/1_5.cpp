#include <iostream>

using namespace std;

// 普通函数与函数模板调用规则
void myPrint(int a, int b)
{
    cout << "调用的普通函数" << endl;
}

template <typename T>
void myPrint(T a, T b)
{
    cout << "调用的模板" << endl;
}

template <typename T>
void myPrint(T a, T b, T c)
{
    cout << "调用重载的模板" << endl;
}

void test1()
{
    // 如果函数模板和普通函数都可以实现，优先调用普通函数
    // 注意，如果告诉编译器普通函数是存在的，但只是声明没有实现，或者不在当前文件内实现，就会报错找不到

    /*
        /usr/bin/ld: /tmp/ccycDidk.o: in function `test1()':
        main.cpp:(.text+0x25): undefined reference to `myPrint(int, int)'
        collect2: error: ld returned 1 exit status
    */

    int a = 10;
    int b = 20;
    // 调用普通函数
    myPrint(a, b);

    // 可以通过空模板参数列表来强制调用函数模板
    // 调用函数模板
    myPrint<>(a, b);
    myPrint<int>(a, b);

    // 函数模板也可以发生重载
    int c = 30;
    // 调用重载的函数模板
    myPrint(a, b, c);

    // 如果函数模板可以产生更好的匹配，优先调用函数模板
    char c1 = 'a';
    char c2 = 'b';
    // 调用函数模板
    myPrint(c1, c2);
}

int main()
{
    test1();

    /*
        调用的普通函数
        调用的模板
        调用的模板
        调用重载的模板
        调用的模板
    */

    return 0;
}