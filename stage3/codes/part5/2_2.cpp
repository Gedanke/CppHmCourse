#include <iostream>
#include <fstream>

using namespace std;

class Person
{
public:
    char name[64];
    int age;
};

class People
{
public:
    string name;
    int age;
};

void test1()
{
    ifstream ifs("person.txt", ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
    }

    Person p;
    ifs.read((char *)&p, sizeof(p));

    cout << "姓名： " << p.name << " 年龄： " << p.age << endl;
}

void test2()
{
    // 使用 string 作为成员属性的类对象在进行二进制读写时，会发生内存错误
    ifstream ifs("people.txt", ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
    }

    People p;
    ifs.read((char *)&p, sizeof(p));

    cout << "姓名： " << p.name << " 年龄： " << p.age << endl;
}

int main()
{
    test1();
    cout << "======" << endl;
    test2();

    /*
        姓名： 张三 年龄： 18
        ======
        姓名：  年龄： 0
        Segmentation fault
    */

    return 0;
}