#include <iostream>

using namespace std;

class Person
{
public:
    // 构造函数
    Person()
    {
        cout << "Person 的构造函数调用" << endl;
    }
    // 析构函数
    ~Person()
    {
        cout << "Person 的析构函数调用" << endl;
    }
};

void test01()
{
    Person p;
}

int main()
{
    test01();

    Person p;

    /*
        Person 的构造函数调用
        Person 的析构函数调用
        Person 的构造函数调用
        Person 的析构函数调用
    */

    return 0;
}