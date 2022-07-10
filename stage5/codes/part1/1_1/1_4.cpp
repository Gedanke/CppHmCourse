#include <iostream>

using namespace std;

// 普通函数
int myAdd1(int a, int b)
{
    return a + b;
}

// 函数模板
template <class T>
T myAdd2(T a, T b)
{
    return a + b;
}

// 使用函数模板时，如果用自动类型推导，不会发生自动类型转换，即隐式类型转换
void test1()
{
    int a = 10;
    int b = 20;
    char c = 'c';

    cout << myAdd1(a, c) << endl; // 正确，将 char 类型的 'c' 隐式转换为 int 类型 'c' 对应 ASCII 码 99
    // myAdd2(a, c); // 报错，使用自动类型推导时，不会发生隐式类型转换
    cout << myAdd2<int>(a, c) << endl; // 正确，如果用显示指定类型，可以发生隐式类型转换
}

int main()
{
    test1();

    /*
        109
        109
    */

    return 0;
}