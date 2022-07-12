#include <iostream>
#include <queue>

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

void test1()
{
    // 创建队列
    queue<Person> q;

    // 准备数据
    Person p1("唐僧", 30);
    Person p2("孙悟空", 1000);
    Person p3("猪八戒", 900);
    Person p4("沙僧", 800);

    // 向队列中添加元素，入队操作
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    // 队列不提供迭代器，更不支持随机访问
    while (!q.empty())
    {
        // 输出队头元素
        cout << "队头元素-- 姓名： " << q.front().name
             << " 年龄： " << q.front().age << endl;

        cout << "队尾元素-- 姓名： " << q.back().name
             << " 年龄： " << q.back().age << endl;

        // 弹出队头元素
        q.pop();
    }

    cout << "队列大小为：" << q.size() << endl;
}

int main()
{
    test1();

    /*
        队头元素-- 姓名： 唐僧 年龄： 30
        队尾元素-- 姓名： 沙僧 年龄： 800
        队头元素-- 姓名： 孙悟空 年龄： 1000
        队尾元素-- 姓名： 沙僧 年龄： 800
        队头元素-- 姓名： 猪八戒 年龄： 900
        队尾元素-- 姓名： 沙僧 年龄： 800
        队头元素-- 姓名： 沙僧 年龄： 800
        队尾元素-- 姓名： 沙僧 年龄： 800
        队列大小为：0
    */

    return 0;
}