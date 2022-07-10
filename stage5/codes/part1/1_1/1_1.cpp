#include <iostream>

using namespace std;

// 交换整型函数
void swapInt(int &a, int &b);

// 交换浮点型函数
void swapDouble(double &a, double &b);

// 利用模板提供通用的交换函数
template <typename T>
void mySwap(T &a, T &b);

void test1();

void test2();

int main()
{
    test1();
    cout << "======" << endl;
    test2();

    /*
        a = 20
        b = 10
        a = 10
        b = 20
        a = 20
        b = 10
        ======
        a = 2.2
        b = 1.1
        a = 1.1
        b = 2.2
        a = 2.2
        b = 1.1
    */

    return 0;
}

template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapDouble(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

void test1()
{
    int a = 10;
    int b = 20;

    swapInt(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // 利用模板实现交换
    // 自动类型推导
    mySwap(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // 显示指定类型
    mySwap<int>(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

void test2()
{
    double a = 1.1;
    double b = 2.2;

    swapDouble(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // 利用模板实现交换
    // 自动类型推导
    mySwap(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // 显示指定类型
    mySwap<double>(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}