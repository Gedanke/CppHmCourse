#include <iostream>
#include <fstream>

using namespace std;

void test1()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    // 第一种
    cout << "第一种" << endl;
    char buf[100] = {0};
    // char buf[5] = {0};
    // 字符数组的 size 要大，如果太小，则
    // *** stack smashing detected ***: terminated Aborted
    while (ifs >> buf)
    {
        cout << buf << endl;
    }

    ifs.close();
}

void test2()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    // 第二种
    cout << "第二种" << endl;
    char buf[1024] = {0};
    // char buf[10] = {0};
    // 字符数组的 size 要大，如果太小，则无法读出数据
    while (ifs.getline(buf, sizeof(buf)))
    {
        cout << buf << endl;
    }

    ifs.close();
}

void test3()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    cout << "第三种" << endl;
    // 第三种，由于不是字符数组，则没有第一二种情况
    string buf;
    while (getline(ifs, buf))
    {
        cout << buf << endl;
    }

    ifs.close();
}

void test4()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    cout << "第四种" << endl;
    // 第四种
    char c;
    while ((c = ifs.get()) != EOF)
    {
        cout << c;
    }

    ifs.close();
}

int main()
{
    test1();
    test2();
    test3();
    test4();

    /*
        第一种
        姓名：张三
        性别：男
        年龄：18
        第二种
        姓名：张三
        性别：男
        年龄：18
        第三种
        姓名：张三
        性别：男
        年龄：18
        第四种
        姓名：张三
        性别：男
        年龄：18
    */

    return 0;
}