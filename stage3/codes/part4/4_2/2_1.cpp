#include <iostream>

using namespace std;

// 构造函数分类
// 按照参数分类分为有参构造和无参构造，无参又称为默认构造函数
// 按照类型分类分为普通构造和拷贝构造

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

// 构造函数的调用
// 调用无参构造函数
void test01()
{
    Person p; // 调用无参构造函数
}

// 调用有参的构造函数
void test02()
{
    cout << "括号法: " << endl;
    // 括号法，常用
    Person p(10);
    // 注意 1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明，不会认为是在创建对象
    // Person pp(); // error
    Person ppp(p);
    cout << "======" << endl;

    cout << "显式法: " << endl;
    // 显式法
    Person p1 = Person();
    Person p2 = Person(10);
    Person p3 = Person(p2);
    // Person(10) 单独写就是匿名对象，当前行结束之后，马上析构
    // Person(p3);
    // 注意 2：不能利用拷贝构造函数初始化匿名对象，编译器认为是对象声明，Person(p3) ==> Person p3
    cout << "======" << endl;

    cout << "隐式转换法: " << endl;
    // 隐式转换法
    Person p4 = 10; // Person p4 = Person(10);
    Person p5 = p4; // Person p5 = Person(p4);
    cout << "======" << endl;
}

int main()
{
    test01();
    test02();

    /*
        无参构造函数!
        析构函数!
        括号法:
        有参构造函数!
        拷贝构造函数!
        ======
        显式法:
        无参构造函数!
        有参构造函数!
        拷贝构造函数!
        ======
        隐式转换法:
        有参构造函数!
        拷贝构造函数!
        ======
        析构函数!
        析构函数!
        析构函数!
        析构函数!
        析构函数!
        析构函数!
        析构函数!
    */

    return 0;
}