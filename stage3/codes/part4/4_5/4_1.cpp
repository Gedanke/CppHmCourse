#include <iostream>

using namespace std;

class Person
{
public:
    // 年龄的指针
    int *age;

public:
    Person(int age)
    {
        // 将年龄数据开辟到堆区
        this->age = new int(age);
    }

    // 重载赋值运算符
    Person &operator=(Person &p)
    {
        if (this->age != NULL)
        {
            delete this->age;
            this->age = NULL;
        }
        // 编译器提供的代码是浅拷贝
        // this->age = p.age;

        // 提供深拷贝，以解决浅拷贝的问题
        this->age = new int(*p.age);

        // 返回自身，引用
        return *this;
    }

    ~Person()
    {
        if (this->age != NULL)
        {
            delete this->age;
            this->age = NULL;
        }
    }
};

void test1()
{
    Person p1(18);
    Person p2(20);
    Person p3(30);

    p3 = p2 = p1; // 赋值操作

    cout << "p1 的年龄为：" << *p1.age << endl;
    cout << "p2 的年龄为：" << *p2.age << endl;
    cout << "p3 的年龄为：" << *p3.age << endl;
}

int main()
{
    test1();

    int a = 10;
    int b = 20;
    int c = 30;

    c = b = a;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    /*
        p1 的年龄为：18
        p2 的年龄为：18
        p3 的年龄为：18
        a = 10
        b = 10
        c = 10
    */

    return 0;
}