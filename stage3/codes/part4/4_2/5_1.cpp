#include <iostream>

using namespace std;

class Person
{
public:
    int m_age;
    int *m_height;

public:
    // 无参(默认)构造函数
    Person()
    {
        cout << "无参构造函数!" << endl;
    }
    // 有参构造函数
    Person(int age, int height)
    {
        cout << "有参构造函数!" << endl;
        m_age = age;
        m_height = new int(height);
    }
    // 拷贝构造函数。如果没有拷贝构造函数，则 free(): double free detected in tcache 2    Aborted
    Person(const Person &p)
    {
        cout << "拷贝构造函数!" << endl;
        // 如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
        m_age = p.m_age;
        m_height = new int(*p.m_height);
    }

    // 析构函数
    ~Person()
    {
        cout << "析构函数!" << endl;
        if (m_height != NULL)
        {
            delete m_height;
            m_height = NULL;
        }
    }
};

void test01()
{
    Person p1(18, 180);
    Person p2(p1);

    cout << "p1 的年龄： " << p1.m_age << " 身高： " << *p1.m_height << endl;
    cout << "p2 的年龄： " << p2.m_age << " 身高： " << *p2.m_height << endl;
}

int main()
{
    test01();

    /*
        有参构造函数!
        拷贝构造函数!
        p1 的年龄： 18 身高： 180
        p2 的年龄： 18 身高： 180
        析构函数!
        析构函数!
    */

    return 0;
}