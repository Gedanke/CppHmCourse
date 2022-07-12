#include <iostream>
#include <list>

using namespace std;

class Person
{
public:
    string name; // 姓名
    int age;     // 年龄
    int height;  // 身高

public:
    Person(string name, int age, int height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
    }
};

bool ComparePerson(Person &p1, Person &p2)
{
    if (p1.age == p2.age)
    {
        return p1.height < p2.height;
    }
    else
    {
        return p1.age < p2.age;
    }
}

void test1()
{
    list<Person> L;

    Person p1("刘备", 35, 175);
    Person p2("曹操", 45, 180);
    Person p3("孙权", 40, 170);
    Person p4("赵云", 25, 190);
    Person p5("张飞", 35, 160);
    Person p6("关羽", 35, 200);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);

    for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "姓名：" << it->name << " 年龄：" << it->age
             << " 身高：" << it->height << endl;
    }
    cout << "---------------------------------" << endl;
    L.sort(ComparePerson); // 排序
    for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "姓名：" << it->name << " 年龄：" << it->age
             << " 身高：" << it->height << endl;
    }
}

int main()
{
    test1();

    /*
        姓名：刘备 年龄：35 身高：175
        姓名：曹操 年龄：45 身高：180
        姓名：孙权 年龄：40 身高：170
        姓名：赵云 年龄：25 身高：190
        姓名：张飞 年龄：35 身高：160
        姓名：关羽 年龄：35 身高：200
        ---------------------------------
        姓名：赵云 年龄：25 身高：190
        姓名：张飞 年龄：35 身高：160
        姓名：刘备 年龄：35 身高：175
        姓名：关羽 年龄：35 身高：200
        姓名：孙权 年龄：40 身高：170
        姓名：曹操 年龄：45 身高：180
    */

    return 0;
}