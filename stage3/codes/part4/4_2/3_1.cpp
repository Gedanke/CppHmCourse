#include <iostream>

using namespace std;

class Person
{
public:
    int mAge;

public:
    Person()
    {
        cout << "无参构造函数!" << endl;
        mAge = 0;
    }
    Person(int age)
    {
        cout << "有参构造函数!" << endl;
        mAge = age;
    }
    Person(const Person &p)
    {
        cout << "拷贝构造函数!" << endl;
        mAge = p.mAge;
    }
    // 析构函数在释放内存之前调用
    ~Person()
    {
        cout << "析构函数!" << endl;
    }
};

// 使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
    Person man(100);      // p 对象已经创建完毕
    Person newman(man);   // 调用拷贝构造函数
    Person newman2 = man; // 拷贝构造

    Person newman3; // 无参
    newman3 = man;  // newman3 不是调用拷贝构造函数，因为已经在上一行通过无参构造函数创建出来了，赋值操作
}

// 值传递的方式给函数参数传值
// 相当于 Person p1 = p;
void doWork(Person p1) {}
// 引用传递，未调用拷贝构造函数
void doWork_(Person &p1) {}

void test02()
{
    Person p; // 无参构造函数
    doWork(p);
    doWork_(p);
}

// 以值方式返回局部对象：Windows vs 2022，会调用拷贝构造函数，linux g++ 则不会
Person doWork2()
{
    Person p1;
    cout << (int *)&p1 << endl;
    return p1;
}

void test03()
{
    Person p = doWork2();
    cout << (int *)&p << endl;
}

int main()
{
    test01();
    cout << "====" << endl;
    test02();
    cout << "====" << endl;
    test03();

    // linux g++
    /*
        有参构造函数!
        拷贝构造函数!
        拷贝构造函数!
        无参构造函数!
        析构函数!
        析构函数!
        析构函数!
        析构函数!
        ====
        无参构造函数!
        拷贝构造函数!
        析构函数!
        析构函数!
        ====
        无参构造函数!
        0x7ffe71ed6894
        0x7ffe71ed6894
        析构函数!
    */

    // windows vs 2022
    /*
        有参构造函数!
        拷贝构造函数!
        拷贝构造函数!
        无参构造函数!
        析构函数!
        析构函数!
        析构函数!
        析构函数!
        ====
        无参构造函数!
        拷贝构造函数!
        析构函数!
        析构函数!
        ====
        无参构造函数!
        000000E3262FF664
        拷贝构造函数!
        析构函数!
        000000E3262FF7A4
        析构函数!
    */

    return 0;
}