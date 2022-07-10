#include <iostream>

using namespace std;

// 全局函数配合友元，类外实现 - 先做函数模板声明，下方在做函数模板定义，在做友元
template <class T1, class T2>
class Person;

// 如果声明了函数模板，可以将实现写到后面，否则需要将实现体写到类的前面让编译器提前看到
// template<class T1, class T2> void printPerson2(Person<T1, T2> & p);

template <class T1, class T2>
void printPerson2(Person<T1, T2> &p)
{
    cout << "类外实现 ---- 姓名：" << p.name << " 年龄：" << p.age << endl;
}

template <class T1, class T2>
class Person
{
private:
    T1 name;
    T2 age;

private:
    // 全局函数配合友元，类内实现
    friend void printPerson(Person<T1, T2> &p)
    {
        cout << "类内实现 ---- 姓名：" << p.name << " 年龄：" << p.age << endl;
    }

    // 全局函数配合友元，类外实现
    friend void printPerson2<>(Person<T1, T2> &p);

public:
    Person(T1 name, T2 age)
    {
        this->name = name;
        this->age = age;
    }
};

// 全局函数在类内实现
void test1()
{
    Person<string, int> p("Tom", 20);
    printPerson(p);
}

// 全局函数在类外实现
void test2()
{
    Person<string, int> p("Jerry", 30);
    printPerson2(p);
}

int main()
{
    test1();
    test2();

    /*
        类内实现 ---- 姓名：Tom 年龄：20
        类外实现 ---- 姓名：Jerry 年龄：30
    */

    return 0;
}