#include <iostream>

using namespace std;

class Person
{
public:
    int age;

public:
    // 无参(默认)构造函数
    Person()
    {
        cout << "无参构造函数!" << endl;
    }
    // 有参构造函数
    Person(int a)
    {
        age = a;
        cout << "有参构造函数!" << endl;
    }
    // 拷贝构造函数
    Person(const Person &p)
    {
        age = p.age;
        cout << "拷贝构造函数!" << endl;
    }
    // 析构函数
    ~Person()
    {
        cout << "析构函数!" << endl;
    }
};

void test01()
{
    Person p1(18);
    // 如果不写拷贝构造，编译器会自动添加拷贝构造，并且做浅拷贝操作
    Person p2(p1);

    cout << "p2 的年龄为： " << p2.age << endl;
}

void test02()
{
    // 如果用户提供有参构造，编译器不会提供默认构造，会提供拷贝构造
    Person p1;     // 此时如果用户自己没有提供默认构造，会出错
    Person p2(10); // 用户提供的有参
    Person p3(p2); // 此时如果用户没有提供拷贝构造，编译器会提供

    // 如果用户提供拷贝构造，编译器不会提供其他构造函数
    Person p4;     // 此时如果用户自己没有提供默认构造，会出错
    Person p5(10); // 此时如果用户自己没有提供有参，会出错
    Person p6(p5); // 用户自己提供拷贝构造
}

int main()
{
    test01();
    cout << "====" << endl;
    test02();

    /*
        有参构造函数!
        拷贝构造函数!
        p2 的年龄为： 18
        析构函数!
        析构函数!
        ====
        无参构造函数!
        有参构造函数!
        拷贝构造函数!
        无参构造函数!
        有参构造函数!
        拷贝构造函数!
        析构函数!
        析构函数!
        析构函数!
        析构函数!
        析构函数!
        析构函数!
    */

    return 0;
}