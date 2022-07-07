#include <iostream>

using namespace std;

class Base1
{
public:
    int m_A;

public:
    Base1()
    {
        m_A = 100;
    }
};

class Base2
{
public:
    int m_A;

public:
    Base2()
    {
        m_A = 200; // 开始是 m_B 不会出问题，但是改为 m_A 就会出现不明确
    }
};

// 语法：class 子类 : 继承方式 父类 1, 继承方式 父类 2...
class Son : public Base2, public Base1
{
public:
    int m_C;
    int m_D;

public:
    Son()
    {
        m_C = 300;
        m_D = 400;
    }
    void show()
    {
        cout << Base1::m_A << " " << Base2::m_A << " " << this->m_C << " " << this->m_D << endl;
    }
};

// 多继承容易产生成员同名的情况
// 通过使用类名作用域可以区分调用哪一个基类的成员
void test1()
{
    Son s;
    cout << "sizeof Son = " << sizeof(s) << endl;
    cout << s.Base1::m_A << endl;
    cout << s.Base2::m_A << endl;
    cout << s.m_C << endl;
    cout << s.m_D << endl;
    cout << "========" << endl;
    s.show();
}

int main()
{
    test1();

    /*
        sizeof Son = 16
        100
        200
        300
        400
        ========
        100 200 300 400
    */

    return 0;
}