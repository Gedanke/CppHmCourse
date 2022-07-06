# C++ 对象模型和 this 指针

---

## 成员变量和成员函数分开存储

在 C++ 中，类内的成员变量和成员函数分开存储

只有非静态成员变量才属于类的对象上

demo:

```cpp
#include <iostream>

using namespace std;

class Person
{
public:
    // 非静态成员变量占对象空间
    int mA;
    // 静态成员变量不占对象空间
    static int mB;

public:
    Person()
    {
        mA = 0;
    }

    // 函数也不占对象空间，所有函数共享一个函数实例
    void func()
    {
        cout << "mA:" << this->mA << endl;
    }

    // 静态成员函数也不占对象空间
    static void sfunc()
    {
    }
};

int main()
{
    cout << sizeof(Person) << endl;

    // 4

    return 0;
}
```

> 空类的大小为 1，C++ 编译会给每个空对象分配一个字节的唯一内存空间，是为了区分空对象占内存的位置

---

## this 指针概念

通过的一部分我们知道，在 C++ 中成员变量和成员函数是分开存储的

每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码

那么问题是：

这一块代码是如何区分那个对象调用自己的呢？

C++ 通过提供特殊的对象指针，`this` 指针，解决上述问题

**this 指针指向被调用的成员函数所属的对象**，`this` 指针是隐含每一个非静态成员函数内的一种指针，`this` 指针不需要定义，直接使用即可

`this` 指针的用途：

* 当形参和成员变量同名时，可用 `this` 指针来区分
* 在类的非静态成员函数中返回对象本身(返回引用)，可使用 `return *this`

demo:

```cpp
#include <iostream>

using namespace std;

class Person
{
public:
    int age;

public:
    Person(int age)
    {
        // 当形参和成员变量同名时，可用 this 指针来区分
        this->age = age;
    }

    Person &PersonAddPerson(Person p)
    {
        this->age += p.age;
        // 返回对象本身，this 是指向当前对象的指针，是地址，*this 指向的就是当前对象本身
        return *this;
    }

    Person PersonAddPersonP(Person p)
    {
        this->age += p.age;
        return *this;
    }
};

void test1()
{
    Person p1(10);
    cout << "p1.age = " << p1.age << endl;

    Person p2(10);
    // 链式编程
    p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
    cout << "p1.age = " << p1.age << endl;
    cout << "p2.age = " << p2.age << endl;
}

void test2()
{
    Person p1(10);
    cout << "p1.age = " << p1.age << endl;

    Person p2(10);
    // p2 只在第一次增加了一次，每次返回的不是本体，而是一个副本(拷贝构造)，后面增加的是每次返回的副本，与 p2 无关
    p2.PersonAddPersonP(p1).PersonAddPersonP(p1).PersonAddPersonP(p1);
    cout << "p1.age = " << p1.age << endl;
    cout << "p2.age = " << p2.age << endl;
}

int main()
{
    test1();
    cout << "====" << endl;
    test2();

    /*
        p1.age = 10
        p1.age = 10
        p2.age = 40
        ====
        p1.age = 10
        p1.age = 10
        p2.age = 20
    */

    return 0;
}
```

---

## 空指针访问成员函数

C++ 中空指针也是可以调用成员函数的，但是也要注意有没有用到 `this` 指针

如果用到 `this` 指针，需要加以判断保证代码的健壮性

demo:

```cpp
#include <iostream>

using namespace std;

// 空指针访问成员函数
class Person
{
public:
    int mAge;

public:
    void ShowClassName()
    {
        cout << "我是 Person 类!" << endl;
    }

    void ShowPerson()
    {
        if (this == NULL)
        {
            return;
        }
        cout << mAge << endl;
    }
};

void test1()
{
    Person *p = NULL;
    // cout << p->mAge << endl; // Segmentation fault
    p->ShowClassName(); // 空指针，可以调用成员函数
    p->ShowPerson();    // 但是如果成员函数中用到了 this 指针，就不可以了，Segmentation fault
}

int main()
{
    test1();

    /*
        我是 Person 类!
    */

    return 0;
}
```

---

## const 修饰成员函数

**常函数**:

* 成员函数后加 `const` 称为这个函数为 **常函数**
* 常函数内不可以修改成员属性
* 成员属性声明时加关键字 `mutable` 后，在常函数中依然可以修改

**常对象**:

* 声明对象前加 `const` 称该对象为常对象
* 常对象只能调用常函数
* 常对象可以修改 `mutable` 修饰成员变量

demo:

```cpp
#include <iostream>

using namespace std;

class Person
{
public:
    int m_A;
    mutable int m_B; // 可修改，可变的

public:
    Person()
    {
        m_A = 0;
        m_B = 0;
    }

    // this 指针的本质是一个指针常量，指针的指向不可修改
    // 如果想让指针指向的值也不可以修改，需要声明常函数
    // 在成员函数后增加 const，修饰的是 this 指向，让指针指向的值也不可以修改
    void ShowPerson() const
    {
        // const Type* const pointer;
        // this = NULL; // 不能修改指针的指向 Person* const this;
        // this->mA = 100;

        // const 修饰成员函数，表示指针指向的内存空间的数据不能修改，除了 mutable 修饰的变量
        this->m_B = 100;
    }

    void MyFunc() const
    {
        // mA = 10000;
    }
};

// const 修饰对象 ==> 常对象
void test1()
{
    const Person person; // 常量对象
    cout << person.m_A << endl;
    // person.mA = 100; // 常对象不能修改成员变量的值，但是可以访问
    person.m_B = 100; // 但是常对象可以修改 mutable 修饰成员变量

    // 常对象访问成员函数
    person.MyFunc(); // 常对象只能调用 const 函数，不可以调用普通成员函数，因为普通成员函数可以修改成员变量
}

int main()
{
    test1();

    /*
        0
    */

    return 0;
}
```

---
