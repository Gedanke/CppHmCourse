#include <iostream>

using namespace std;

class Animal
{
public:
    // Speak 函数就是虚函数
    // 函数前面加上 virtual 关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "小猫在说话" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "小狗在说话" << endl;
    }
};

// 我们希望传入什么对象，那么就调用什么对象的函数
// 如果函数地址在编译阶段就能确定，那么静态联编，早绑定
// 如果函数地址在运行阶段才能确定，就是动态联编，晚绑定
void doSpeak(Animal &animal)
{
    animal.speak();
}

// 多态满足条件：
// 有继承关系
// 子类重写父类中的虚函数
// 多态使用：
// 父类指针或引用指向子类对象
void test1()
{
    Animal a;
    doSpeak(a);

    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}

int main()
{
    test1();

    /*
        动物在说话
        小猫在说话
        小狗在说话
    */

    // 如果去掉 virtual

    /*
        动物在说话
        动物在说话
        动物在说话
    */

    return 0;
}