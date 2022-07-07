#include <iostream>

using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base 构造函数!" << endl;
    }
    ~Base()
    {
        cout << "Base 析构函数!" << endl;
    }
};

class Son : public Base
{
public:
    Son()
    {
        cout << "Son 构造函数!" << endl;
    }
    ~Son()
    {
        cout << "Son 析构函数!" << endl;
    }
};

void test1()
{
    // 继承中，先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
    Son s;
}

int main()
{
    test1();

    /*
        Base 构造函数!
        Son 构造函数!
        Son 析构函数!
        Base 析构函数!
    */

    return 0;
}