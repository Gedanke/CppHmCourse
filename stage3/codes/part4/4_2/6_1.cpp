#include <iostream>

using namespace std;

class Person
{
private:
    int m_A;
    int m_B;
    int m_C;

public:
    // 传统方式初始化
    // Person(int a, int b, int c) {
    // 	m_A = a;
    // 	m_B = b;
    // 	m_C = c;
    // }

    // 初始化列表方式初始化
    Person(int a, int b, int c) : m_A(a), m_B(b), m_C(c) {}
    void PrintPerson()
    {
        cout << "mA:" << m_A << endl;
        cout << "mB:" << m_B << endl;
        cout << "mC:" << m_C << endl;
    }
};

int main()
{
    Person p(1, 2, 3);
    p.PrintPerson();

    /*
        mA:1
        mB:2
        mC:3
    */

    return 0;
}