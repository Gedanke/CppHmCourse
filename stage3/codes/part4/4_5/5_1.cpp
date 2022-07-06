#include <iostream>

using namespace std;

class Person
{
public:
    string name;
    int age;

public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    };

    bool operator==(Person &p)
    {
        if (this->name == p.name && this->age == p.age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator!=(Person &p)
    {
        if (this->name == p.name && this->age == p.age)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

void test1()
{
    // int a = 0;
    // int b = 0;

    Person a("孙悟空", 18);
    Person b("孙悟空", 18);

    if (a == b)
    {
        cout << "a 和 b 相等" << endl;
    }
    else
    {
        cout << "a 和 b 不相等" << endl;
    }

    if (a != b)
    {
        cout << "a 和 b 不相等" << endl;
    }
    else
    {
        cout << "a 和 b 相等" << endl;
    }
}

int main()
{
    test1();

    /*
        a 和 b 相等
        a 和 b 相等
    */

    return 0;
}