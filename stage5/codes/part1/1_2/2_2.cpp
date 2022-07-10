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

// 类模板没有自动类型推导的使用方式
void test1()
{
    // Person p("孙悟空", 1000); // 错误，类模板使用时候，不可以用自动类型推导。缺少类模板 "Person" 的参数列表
    Person<string, int> p("孙悟空", 1000); // 必须使用显示指定类型的方式，使用类模板
    p.showPerson();
}

// 类模板在模板参数列表中可以有默认参数
void test2()
{
    Person<string> p("猪八戒", 999); // 类模板中的模板参数列表可以指定默认参数
    p.showPerson();
}

// 类模板在模板参数列表中可以有默认参数
void test3()
{
    // Person<string> p_("猪八戒", "99.9"); // 没有与参数列表匹配的构造函数 "Person<NameType, AgeType>::Person [其中 NameType=std::string, AgeType=int]" 实例
    Person<string> p("猪八戒", 99.9); // 发生了类型转换
    p.showPerson();
}

void test4()
{
    Person<string, double> p("猪八戒", 99.9);
    p.showPerson();
}

int main()
{
    test1();

    test2();

    test3();

    test4();

    /*
        name: 孙悟空 age: 1000
        name: 猪八戒 age: 999
        name: 猪八戒 age: 99
        name: 猪八戒 age: 99.9
    */

    return 0;
}
