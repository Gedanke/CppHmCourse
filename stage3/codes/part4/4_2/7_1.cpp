#include <iostream>

using namespace std;

class Phone
{
public:
    string phoneName;

public:
    Phone(string name)
    {
        phoneName = name;
        cout << "Phone 构造" << endl;
    }

    ~Phone()
    {
        cout << "Phone 析构" << endl;
    }
};

class Person
{
public:
    string name;
    Phone phone;

public:
    // 初始化列表可以告诉编译器调用哪一个构造函数
    // phone(name) ==> Phone phone = name
    Person(string name, string pName) : name(name), phone(pName)
    {
        cout << "Person 构造" << endl;
    }

    ~Person()
    {
        cout << "Person 析构" << endl;
    }

    void playGame()
    {
        cout << name << " 使用 " << phone.phoneName << " 牌手机" << endl;
    }
};

void test01()
{
    // 当类中成员是其他类对象时，我们称该成员为对象成员
    // 构造的顺序是：先调用对象成员的构造，再调用本类构造
    // 析构顺序与构造相反
    Person p("张三", "苹果");
    p.playGame();
}

int main()
{
    test01();

    /*
        Phone 构造
        Person 构造
        张三 使用 苹果 牌手机
        Person 析构
        Phone 析构
    */

    return 0;
}