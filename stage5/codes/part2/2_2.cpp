#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 自定义数据类型
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

// 存放对象
void test1(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        // it => Person*
        cout << "Name:" << (*it).name << " Age:" << it->age << endl;
    }
}

// 放对象指针
void test2(vector<Person *> &v)
{
    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
    {
        Person *p = (*it);
        // it => Person**
        cout << "Name:" << (*(*it)).name << " Age:" << (*it)->age << endl;
        cout << "Name:" << p->name << " Age:" << (*p).age << endl;
    }
}

void helpTest3(Person &p)
{
    cout << "Name:" << p.name << " Age:" << p.age << endl;
}

// 存放对象，使用 for_each
void test3(vector<Person> &v)
{
    for_each(v.begin(), v.end(), helpTest3);
}

int main()
{
    vector<Person> v;
    vector<Person *> vp;

    //创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    vp.push_back(&p1);
    vp.push_back(&p2);
    vp.push_back(&p3);
    vp.push_back(&p4);
    vp.push_back(&p5);

    test1(v);
    cout << "=========" << endl;
    test2(vp);
    cout << "=========" << endl;
    test3(v);

    /*
        Name:aaa Age:10
        Name:bbb Age:20
        Name:ccc Age:30
        Name:ddd Age:40
        Name:eee Age:50
        =========
        Name:aaa Age:10
        Name:aaa Age:10
        Name:bbb Age:20
        Name:bbb Age:20
        Name:ccc Age:30
        Name:ccc Age:30
        Name:ddd Age:40
        Name:ddd Age:40
        Name:eee Age:50
        Name:eee Age:50
        =========
        Name:aaa Age:10
        Name:bbb Age:20
        Name:ccc Age:30
        Name:ddd Age:40
        Name:eee Age:50
    */

    return 0;
}
