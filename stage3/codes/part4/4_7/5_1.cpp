#include <iostream>

using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal 构造函数调用！" << endl;
    }
    virtual void Speak() = 0;

    // 析构函数加上 virtual 关键字，变成虚析构函数
    // virtual ~Animal()
    // {
    // 	cout << "Animal虚析构函数调用！" << endl;
    // }

    virtual ~Animal() = 0;

    // ~Animal(); // 此时 Cat 析构函数没有被调用
    /*
        Animal 构造函数调用！
        Cat 构造函数调用！
        Tom 小猫在说话!
        Animal 纯虚析构函数调用！
    */
};

// 和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化
Animal::~Animal()
{
    cout << "Animal 纯虚析构函数调用！" << endl;
}

class Cat : public Animal
{
public:
    string *name;

public:
    Cat(string name)
    {
        cout << "Cat 构造函数调用！" << endl;
        this->name = new string(name);
    }

    virtual void Speak()
    {
        cout << *this->name << " 小猫在说话!" << endl;
    }

    ~Cat()
    {
        cout << "Cat 析构函数调用!" << endl;
        if (this->name != NULL)
        {
            delete this->name;
            this->name = NULL;
        }
    }
};

void test1()
{
    Animal *animal = new Cat("Tom");
    animal->Speak();

    // Speak() 在父类中是纯虚函数，子类重新实现了，体现了多态性。但是，父类的析构函数不是虚函数，子类的析构函数释放了自己的内存，没有体现出多态性
    // 通过父类指针去释放，不会调用子类中的析构函数，会导致子类对象可能清理不干净，造成内存泄漏
    // 怎么解决？给基类增加一个虚析构函数
    // 虚析构函数就是用来解决通过父类指针释放子类对象
    delete animal;
}

int main()
{
    test1();

    return 0;
}