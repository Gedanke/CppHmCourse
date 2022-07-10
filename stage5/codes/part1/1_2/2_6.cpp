#include <iostream>

using namespace std;

template <class T1, class T2>
class Person
{
public:
    T1 name;
    T2 age;

public:
    // 成员函数类内声明
    Person(T1 name, T2 age);
    void showPerson();
};

// 构造函数类外实现
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->name = name;
    this->age = age;
}

// 成员函数类外实现
template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << "姓名: " << this->name << " 年龄: " << this->age << endl;
}

void test1()
{
    Person<string, int> p("Tom", 22);
    p.showPerson();
}

int main()
{
    test1();

    /*
        姓名: Tom 年龄: 22
     */

    return 0;
}
