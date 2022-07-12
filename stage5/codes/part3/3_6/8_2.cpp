#include <iostream>
#include <set>

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
    }
};

class comparePerson
{
public:
    bool operator()(const Person &p1, const Person &p2)
    {
        // 按照年龄进行排序，降序
        return p1.age > p2.age;
    }
};

void test1()
{
    // set<Person> s; // error
    set<Person, comparePerson> s;

    Person p1("刘备", 23);
    Person p2("关羽", 27);
    Person p3("张飞", 25);
    Person p4("赵云", 21);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "姓名：" << it->name << " 年龄：" << it->age << endl;
    }
}

int main()
{
    test1();

    /*
        姓名：关羽 年龄：27
        姓名：张飞 年龄：25
        姓名：刘备 年龄：23
        姓名：赵云 年龄：21
    */

    return 0;
}