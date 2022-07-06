#include <iostream>

using namespace std;

class Person
{
public:
    // 非静态成员变量占对象空间
    int mA;
    // 静态成员变量不占对象空间
    static int mB;

public:
    Person()
    {
        mA = 0;
    }

    // 函数也不占对象空间，所有函数共享一个函数实例
    void func()
    {
        cout << "mA:" << this->mA << endl;
    }

    // 静态成员函数也不占对象空间
    static void sfunc()
    {
    }
};

int main()
{
    cout << sizeof(Person) << endl;

    // 4

    return 0;
}