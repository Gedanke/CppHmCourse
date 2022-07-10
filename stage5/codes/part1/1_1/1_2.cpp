#include <iostream>

using namespace std;

// 利用模板提供通用的交换函数
template <class T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 自动类型推导，必须推导出一致的数据类型 T，才可以使用
void test1()
{
    int a = 10;
    int b = 20;
    char c = 'c';

    mySwap(a, b); // 正确，可以推导出一致的 T 类型
    // mySwap(a, c); // 错误，推导不出一致的 T 类型
    mySwap<int>(a, b);
}

// 模板必须要确定出 T 的数据类型，才可以使用
template <class T>
void func()
{
    cout << "func 调用" << endl;
}

void test2()
{
    // func(); // 错误，模板不能独立使用，必须确定出 T 的类型
    // func(1); // 没有与参数列表匹配的函数模板 "func" 实例
    func<int>(); // 利用显示指定类型的方式，给 T 一个类型，才可以使用该模板
}

int main()
{
    test1();
    test2();

    // func 调用

    return 0;
}