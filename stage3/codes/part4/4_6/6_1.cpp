#include <iostream>

using namespace std;

class Base
{
public:
    static int m_A;

public:
    static void func()
    {
        cout << "Base - static void func()" << endl;
    }
    static void func(int a)
    {
        cout << "Base - static void func(int a)" << endl;
    }
};

int Base::m_A = 100;

class Son : public Base
{
public:
    static int m_A;

public:
    static void func()
    {
        cout << "Son - static void func()" << endl;
    }
};

int Son::m_A = 200;

// 同名成员属性
void test1()
{
    // 通过对象访问
    cout << "通过对象访问： " << endl;
    Son s;
    cout << "Son  下 m_A = " << s.m_A << endl;
    cout << "Base 下 m_A = " << s.Base::m_A << endl;

    // 通过类名访问
    cout << "通过类名访问： " << endl;
    cout << "Son  下 m_A = " << Son::m_A << endl;
    cout << "Base 下 m_A = " << Son::Base::m_A << endl;
}

// 同名成员函数
void test2()
{
    // 通过对象访问
    cout << "通过对象访问： " << endl;
    Son s;
    s.func();
    s.Base::func();

    // 通过类名访问
    cout << "通过类名访问： " << endl;
    Son::func();
    Son::Base::func();
    // 出现同名，子类会隐藏掉父类中所有同名成员函数，需要加作作用域访问
    Son::Base::func(100);
}
int main()
{
    test1();
    cout << "======" << endl;
    test2();

    /*
        通过对象访问：
        Son  下 m_A = 200
        Base 下 m_A = 100
        通过类名访问：
        Son  下 m_A = 200
        Base 下 m_A = 100
        ======
        通过对象访问：
        Son - static void func()
        Base - static void func()
        通过类名访问：
        Son - static void func()
        Base - static void func()
        Base - static void func(int a)
    */

    return 0;
}