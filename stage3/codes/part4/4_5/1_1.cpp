#include <iostream>

using namespace std;

class Person
{
public:
    int m_A;
    int m_B;

public:
    Person(){};

    Person(int a, int b)
    {
        this->m_A = a;
        this->m_B = b;
    }

    // 成员函数实现 + 号运算符重载
    Person operator+(const Person &p)
    {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }
};

// 全局函数实现 + 号运算符重载
Person operator+(const Person &p1, const Person &p2)
{
    Person temp(0, 0);
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}

// 运算符重载也可以发生函数重载
Person operator+(const Person &p, int val)
{
    Person temp;
    temp.m_A = p.m_A + val;
    temp.m_B = p.m_B + val;
    return temp;
}

void test()
{
    Person p1(10, 10);
    Person p2(20, 20);

    // 成员函数方式
    Person p3 = p1.operator+(p2); // p1.operaor+(p2)
    cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;

    Person p4 = p1 + p2; // operator+(p1, p2)
    cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;

    Person p5 = p1 + 10; // operator+(p1, 10)
    cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;
}

int main()
{
    test();

    /*
        mA:30 mB:30
        mA:30 mB:30
        mA:30 mB:30
    */

    return 0;
}