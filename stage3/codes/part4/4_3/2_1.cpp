#include <iostream>

using namespace std;

class Person
{
public:
    int age;

public:
    Person(int age)
    {
        // 当形参和成员变量同名时，可用 this 指针来区分
        this->age = age;
    }

    Person &PersonAddPerson(Person p)
    {
        this->age += p.age;
        // 返回对象本身，this 是指向当前对象的指针，是地址，*this 指向的就是当前对象本身
        return *this;
    }

    Person PersonAddPersonP(Person p)
    {
        this->age += p.age;
        return *this;
    }
};

void test1()
{
    Person p1(10);
    cout << "p1.age = " << p1.age << endl;

    Person p2(10);
    // 链式编程
    p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
    cout << "p1.age = " << p1.age << endl;
    cout << "p2.age = " << p2.age << endl;
}

void test2()
{
    Person p1(10);
    cout << "p1.age = " << p1.age << endl;

    Person p2(10);
    // p2 只在第一次增加了一次，每次返回的不是本体，而是一个副本(拷贝构造)，后面增加的是每次返回的副本，与 p2 无关
    p2.PersonAddPersonP(p1).PersonAddPersonP(p1).PersonAddPersonP(p1);
    cout << "p1.age = " << p1.age << endl;
    cout << "p2.age = " << p2.age << endl;
}

int main()
{
    test1();
    cout << "====" << endl;
    test2();

    /*
        p1.age = 10
        p1.age = 10
        p2.age = 40
        ====
        p1.age = 10
        p1.age = 10
        p2.age = 20
    */

    return 0;
}