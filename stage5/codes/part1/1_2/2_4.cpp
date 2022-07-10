#include <iostream>

using namespace std;

// 类模板
template <class NameType, class AgeType = int>
class Person
{
public:
    NameType name;
    AgeType age;

public:
    Person(NameType name, AgeType age)
    {
        this->name = name;
        this->age = age;
    }

    void showPerson()
    {
        cout << "name: " << this->name << " age: " << this->age << endl;
    }
};

// 指定传入的类型
void printPerson1(Person<string, int> &p)
{
    p.showPerson();
}

void test1()
{
    Person<string> p("孙悟空", 100);
    printPerson1(p);
}

// 参数模板化
template <class T1, class T2>
void printPerson2(Person<T1, T2> &p)
{
    p.showPerson();
    cout << "T1 的类型为： " << typeid(T1).name() << endl;
    cout << "T2 的类型为： " << typeid(T2).name() << endl;
}

void test2()
{
    // int 类型简写为 i，double 类型简写为 d
    Person<string, int> p("猪八戒", 90);
    printPerson2(p);
}

// 整个类模板化
template <class T>
void printPerson3(T &p)
{
    cout << "T 的类型为： " << typeid(T).name() << endl;
    p.showPerson();
}

void test3()
{
    Person<string, int> p("唐僧", 30);
    printPerson3(p);

    Person<string, double> pp("唐僧", 30.2);
    printPerson3(pp);

    cout << (typeid(p).name() == typeid(pp).name()) << endl;
}

int main()
{
    test1();
    cout << "======" << endl;
    test2();
    cout << "======" << endl;
    test3();

    /*
        name: 孙悟空 age: 100
        ======
        name: 猪八戒 age: 90
        T1 的类型为： NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
        T2 的类型为： i
        ======
        T 的类型为： 6PersonINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE
        name: 唐僧 age: 30
        T 的类型为： 6PersonINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEdE
        name: 唐僧 age: 30.2
        0
    */

    return 0;
}
