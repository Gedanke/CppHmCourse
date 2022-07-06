#include <iostream>

using namespace std;

class Person
{
public:
    int m_A;
    mutable int m_B; // 可修改，可变的

public:
    Person()
    {
        m_A = 0;
        m_B = 0;
    }

    // this 指针的本质是一个指针常量，指针的指向不可修改
    // 如果想让指针指向的值也不可以修改，需要声明常函数
    // 在成员函数后增加 const，修饰的是 this 指向，让指针指向的值也不可以修改
    void ShowPerson() const
    {
        // const Type* const pointer;
        // this = NULL; // 不能修改指针的指向 Person* const this;
        // this->mA = 100;

        // const 修饰成员函数，表示指针指向的内存空间的数据不能修改，除了 mutable 修饰的变量
        this->m_B = 100;
    }

    void MyFunc() const
    {
        // mA = 10000;
    }
};

// const 修饰对象 ==> 常对象
void test1()
{
    const Person person; // 常量对象
    cout << person.m_A << endl;
    // person.mA = 100; // 常对象不能修改成员变量的值，但是可以访问
    person.m_B = 100; // 但是常对象可以修改 mutable 修饰成员变量

    // 常对象访问成员函数
    person.MyFunc(); // 常对象只能调用 const 函数，不可以调用普通成员函数，因为普通成员函数可以修改成员变量
}

int main()
{
    test1();

    /*
        0
    */

    return 0;
}