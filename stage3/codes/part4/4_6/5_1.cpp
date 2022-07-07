#include <iostream>

using namespace std;

class Base
{
public:
    int m_A;

public:
    Base()
    {
        this->m_A = 100;
    }

    void func()
    {
        cout << "Base - func() 调用" << endl;
    }

    void func(int a)
    {
        cout << "Base - func(int a) 调用" << endl;
    }
};

class Son : public Base
{
public:
    int m_A;

public:
    Son()
    {
        this->m_A = 200;
    }

    // 当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
    // 如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
    void func()
    {
        cout << "Son - func() 调用" << endl;
    }

    void func(int a)
    {
        cout << "Son - func(int a) 调用" << endl;
    }
};

void test1()
{
    Son s;

    cout << "Son 下的 m_A = " << s.m_A << endl;
    cout << "Base 下的 m_A = " << s.Base::m_A << endl;

    s.func();
    s.func(10);
    s.Base::func();
    s.Base::func(10);
}
int main()
{
    test1();

    /*
        Son 下的 m_A = 200
        Base 下的 m_A = 100
        Son - func() 调用
        Son - func(int a) 调用
        Base - func() 调用
        Base - func(int a) 调用
    */

    return EXIT_SUCCESS;
}