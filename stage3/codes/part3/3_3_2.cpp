#include <iostream>

using namespace std;

// 函数重载注意事项
// 引用作为重载条件
void func(int &a)
{
    cout << "func(int &a) 调用 " << endl;
}

void func(const int &a)
{
    cout << "func(const int &a) 调用 " << endl;
}

void fun(const int &a)
{
    cout << "fun(const int &a) 调用 " << endl;
}

// 函数重载碰到函数默认参数
void func2(int a, int b = 10)
{
    cout << "func2(int a, int b = 10) 调用" << endl;
}

void func2(int a)
{
    cout << "func2(int a) 调用" << endl;
}

int main()
{
    int a = 10;
    func(a);  // 调用无 const。int& a = a，合法，可以修改 a；const int &a = a，合法，但是无法修改 a
    fun(a);   // 原则上既可以调用有 const 的，也可以调用无 const 的。如果存在有 const 与无 const 的函数重载时，a 只会调用无 const 的
    func(10); // 调用有 const。int& a = 10，不合法；const int &a = 10，合法，不可同时也不打算修改 a

    // func2(10); // func2，还有 2 个重载，有多个重载函数 "func2" 实例与参数列表匹配。碰到默认参数产生歧义，需要避免

    /*
        func(int &a) 调用
        fun(const int &a) 调用
        func(const int &a) 调用
    */

    return 0;
}