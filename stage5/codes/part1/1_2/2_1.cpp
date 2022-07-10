#include <iostream>

using namespace std;

// 类模板
template <class NameType, class AgeType>
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

void test1()
{
    // 指定 NameType 为 string 类型，AgeType 为 int 类型
    Person<string, int> p1("孙悟空", 999);
    p1.showPerson();
}

void test2()
{
    // 指定 NameType 为 string 类型，AgeType 为 string 类型
    Person<string, string> p1("孙悟空", "64");
    p1.showPerson();
}

int main()
{
    test1();

    test2();

    /*
        name: 孙悟空 age: 999
        name: 孙悟空 age: 64
    */

    return 0;
}
