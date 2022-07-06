#include <iostream>

using namespace std;

class Person
{
private:
    int m_A;
    int m_B;

    // 声明友元函数
    friend ostream &operator<<(ostream &out, const Person &p);
    friend istream &operator>>(istream &in, Person &p);

public:
    Person()
    {
    }

    Person(int a, int b)
    {
        this->m_A = a;
        this->m_B = b;
    }

    // 成员函数 实现不了 p << cout，不是我们想要的效果
    // void operator<<(Person& p){
    // }
};

// 全局函数实现左移重载
// ostream 对象只能有一个
ostream &operator<<(ostream &out, const Person &p)
{
    out << "a:" << p.m_A << " b:" << p.m_B;
    return out;
}

// istream 对象只能有一个
istream &operator>>(istream &in, Person &p)
{
    in >> p.m_A >> p.m_B;
    return in;
}

void test()
{
    Person p;
    cout << "input person: " << endl;
    cin >> p;
    cout << p << endl; // 链式编程
}

int main()
{
    test();

    /*
        input person:
        12 12
        a:12 b:12
    */

    return 0;
}