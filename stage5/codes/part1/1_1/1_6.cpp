#include <iostream>

using namespace std;

class Person
{
public:
    string name;
    int age;

public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};

// 普通函数模板
template <class T>
bool myCompare(T &a, T &b)
{
    return (a == b);
}

// 具体化，显示具体化的原型和定意思以 template<> 开头，并通过名称来指出类型
// 具体化优先于常规模板
template <>
bool myCompare(Person &p1, Person &p2)
{
    return (p1.name == p2.name && p1.age == p2.age);
}

void test1()
{
    int a = 10;
    int b = 20;
    // 内置数据类型可以直接使用通用的函数模板
    bool ret = myCompare(a, b);
    if (ret)
    {
        cout << "a == b " << endl;
    }
    else
    {
        cout << "a != b " << endl;
    }
}

void test2()
{
    Person p1("Tom", 10);
    Person p2("Tom", 10);
    // 自定义数据类型，不会调用普通的函数模板
    // 可以创建具体化的 Person 数据类型的模板，用于特殊处理这个类型
    bool ret = myCompare(p1, p2);
    if (ret)
    {
        cout << "p1 == p2 " << endl;
    }
    else
    {
        cout << "p1 != p2 " << endl;
    }
}

int main()
{
    test1();
    test2();

    /*
        a != b
        p1 == p2
    */

    return 0;
}