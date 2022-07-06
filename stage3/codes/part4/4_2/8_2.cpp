#include <iostream>

using namespace std;

class Person
{
public:
    static int m_A; // 静态成员变量
    int m_B;        // 非静态成员变量

public:
    // 静态成员函数特点：
    // 程序共享一个函数
    // 静态成员函数只能访问静态成员变量

    static void func()
    {
        cout << "func 调用" << endl;
        m_A = 100;
        // m_B = 100; // 错误，不可以访问非静态成员变量，无法区分
    }

private:
    // 静态成员函数也是有访问权限的
    static void func2()
    {
        cout << "func2 调用" << endl;
    }
};

int Person::m_A = 10;

void test01()
{
    // 静态成员变量两种访问方式

    // 通过对象
    Person p1;
    p1.func();

    // 通过类名
    Person::func();

    // Person::func2(); // 私有权限访问不到
}

int main()
{
    test01();

    /*
        func 调用
        func 调用
    */

    return 0;
}