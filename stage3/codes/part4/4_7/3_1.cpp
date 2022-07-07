#include <iostream>

using namespace std;

class Base
{
public:
    // 纯虚函数
    // 类中只要有一个纯虚函数就称为抽象类
    // 抽象类无法实例化对象
    // 子类必须重写父类中的纯虚函数，否则也属于抽象类
    virtual void func() = 0;
};

class Son : public Base
{
public:
    // 可以不加 virtual
    virtual void func()
    {
        cout << "func 调用" << endl;
    };
};

void test1()
{
    Base *base;
    // base = new Base; // 错误，抽象类无法实例化对象
    base = new Son;
    base->func();
    delete base; // 记得销毁
}

int main()
{
    test1();

    // func 调用

    return 0;
}