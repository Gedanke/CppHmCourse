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

// 二进制文件，写文件
void test1()
{
    // 包含头文件

    // 创建输出流对象
    ofstream ofs("person.txt", ios::out | ios::binary);

    // 打开文件
    // ofs.open("person.txt", ios::out | ios::binary);

    Person p = {"张三", 18};

    // 写文件
    ofs.write((const char *)&p, sizeof(p));

    // 关闭文件
    ofs.close();
}

// 二进制文件，写文件，此时不建议用 string 作为成员属性来进行二进制读写，会造成内存方面的问题
void test2()
{
    // 包含头文件

    // 创建输出流对象
    ofstream ofs("people.txt", ios::out | ios::binary);

    // 打开文件
    // ofs.open("person.txt", ios::out | ios::binary);

    People p = {"张三", 18};

    // 写文件
    ofs.write((const char *)&p, sizeof(p));

    // 关闭文件
    ofs.close();
}

int main()
{
    test1();
    // test2();

    return 0;
}