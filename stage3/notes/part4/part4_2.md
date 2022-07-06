# 对象的初始化和清理

* 生活中买的电子产品都基本会有出厂设置，在某一天不用的时候，我们也会删除一些自己信息数据保证安全
* C++ 中的面向对象来源于生活，每个对象也都会有初始设置以及对象销毁前的清理数据的设置

---

## 构造函数和析构函数

对象的 **初始化和清理** 也是两个非常重要的安全问题

* 一个对象或者变量没有初始状态，对其使用后果是未知
* 同样的使用完一个对象或变量，没有及时清理，也会造成一定的安全问题

C++ 利用了 **构造函数** 和 **析构函数** 解决上述问题，这两个函数将会被编译器自动调用，完成对象初始化和清理工作

对象的初始化和清理工作是编译器强制要我们做的事情，因此如果 **我们不提供构造和析构，编译器会提供**

**编译器提供的构造函数和析构函数是空实现**

* 构造函数：主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无须手动调用
* 析构函数：主要作用在于对象 **销毁前** 系统自动调用，执行一些清理工作

**构造函数语法**：

```cpp
类名()
{

}
```

* 构造函数，没有返回值也不写 `void`
* 函数名称与类名相同
* 构造函数可以有参数，因此可以发生重载
* 程序在调用对象时候会自动调用构造，无须手动调用，而且只会调用一次

**析构函数语法**： 

```cpp
~类名()
{

}
```

* 析构函数，没有返回值也不写 `void`
* 函数名称与类名相同，在名称前加上符号 `~`
* 析构函数不可以有参数，因此不可以发生重载
* 程序在对象销毁前会自动调用析构，无须手动调用，而且只会调用一次

demo:

```cpp
#include <iostream>

using namespace std;

class Person
{
public:
    // 构造函数
    Person()
    {
        cout << "Person 的构造函数调用" << endl;
    }
    // 析构函数
    ~Person()
    {
        cout << "Person 的析构函数调用" << endl;
    }
};

void test01()
{
    Person p;
}

int main()
{
    test01();

    Person p;

    /*
        Person 的构造函数调用
        Person 的析构函数调用
        Person 的构造函数调用
        Person 的析构函数调用
    */

    return 0;
}
```

---

## 构造函数的分类及调用

构造函数的两种分类方式:

* ​按参数分为：有参构造和无参构造
* ​按类型分为：普通构造和拷贝构造

构造函数的三种调用方式：

* ​括号法
* ​显示法
* ​隐式转换法

demo:

```cpp
#include <iostream>

using namespace std;

// 构造函数分类
// 按照参数分类分为有参构造和无参构造，无参又称为默认构造函数
// 按照类型分类分为普通构造和拷贝构造

class Person
{
public:
    int age;

public:
    // 无参(默认)构造函数
    Person()
    {
        cout << "无参构造函数!" << endl;
    }
    // 有参构造函数
    Person(int a)
    {
        age = a;
        cout << "有参构造函数!" << endl;
    }
    // 拷贝构造函数
    Person(const Person &p)
    {
        age = p.age;
        cout << "拷贝构造函数!" << endl;
    }
    // 析构函数
    ~Person()
    {
        cout << "析构函数!" << endl;
    }
};

// 构造函数的调用
// 调用无参构造函数
void test01()
{
    Person p; // 调用无参构造函数
}

// 调用有参的构造函数
void test02()
{
    cout << "括号法: " << endl;
    // 括号法，常用
    Person p(10);
    // 注意 1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明，不会认为是在创建对象
    // Person pp(); // error
    Person ppp(p);
    cout << "======" << endl;

    cout << "显式法: " << endl;
    // 显式法
    Person p1 = Person();
    Person p2 = Person(10);
    Person p3 = Person(p2);
    // Person(10) 单独写就是匿名对象，当前行结束之后，马上析构
    // Person(p3);
    // 注意 2：不能利用拷贝构造函数初始化匿名对象，编译器认为是对象声明，Person(p3) ==> Person p3
    cout << "======" << endl;

    cout << "隐式转换法: " << endl;
    // 隐式转换法
    Person p4 = 10; // Person p4 = Person(10);
    Person p5 = p4; // Person p5 = Person(p4);
    cout << "======" << endl;
}

int main()
{
    test01();
    test02();

    /*
        无参构造函数!
        析构函数!
        括号法:
        有参构造函数!
        拷贝构造函数!
        ======
        显式法:
        无参构造函数!
        有参构造函数!
        拷贝构造函数!
        ======
        隐式转换法:
        有参构造函数!
        拷贝构造函数!
        ======
        析构函数!
        析构函数!
        析构函数!
        析构函数!
        析构函数!
        析构函数!
        析构函数!
    */

    return 0;
}
```

---

## 拷贝构造函数调用时机

C++ 中拷贝构造函数调用时机通常有三种情况

* 使用一个已经创建完毕的对象来初始化一个新对象
* 值传递的方式给函数参数传值
* 以值方式返回局部对象(windos 平台会调用拷贝构造函数，linux 平台则不会，编译器做了优化(可以开启禁止优化选项))

demo:

```cpp
#include <iostream>

using namespace std;

class Person
{
public:
    int mAge;

public:
    Person()
    {
        cout << "无参构造函数!" << endl;
        mAge = 0;
    }
    Person(int age)
    {
        cout << "有参构造函数!" << endl;
        mAge = age;
    }
    Person(const Person &p)
    {
        cout << "拷贝构造函数!" << endl;
        mAge = p.mAge;
    }
    // 析构函数在释放内存之前调用
    ~Person()
    {
        cout << "析构函数!" << endl;
    }
};

// 使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
    Person man(100);      // p 对象已经创建完毕
    Person newman(man);   // 调用拷贝构造函数
    Person newman2 = man; // 拷贝构造

    Person newman3; // 无参
    newman3 = man;  // newman3 不是调用拷贝构造函数，因为已经在上一行通过无参构造函数创建出来了，赋值操作
}

// 值传递的方式给函数参数传值
// 相当于 Person p1 = p;
void doWork(Person p1) {}
// 引用传递，未调用拷贝构造函数
void doWork_(Person &p1) {}

void test02()
{
    Person p; // 无参构造函数
    doWork(p);
    doWork_(p);
}

// 以值方式返回局部对象：Windows vs 2022，会调用拷贝构造函数，linux g++ 则不会
Person doWork2()
{
    Person p1;
    cout << (int *)&p1 << endl;
    return p1;
}

void test03()
{
    Person p = doWork2();
    cout << (int *)&p << endl;
}

int main()
{
    test01();
    cout << "====" << endl;
    test02();
    cout << "====" << endl;
    test03();

    // linux g++
    /*
        有参构造函数!
        拷贝构造函数!
        拷贝构造函数!
        无参构造函数!
        析构函数!
        析构函数!
        析构函数!
        析构函数!
        ====
        无参构造函数!
        拷贝构造函数!
        析构函数!
        析构函数!
        ====
        无参构造函数!
        0x7ffe71ed6894
        0x7ffe71ed6894
        析构函数!
    */

    // windows vs 2022
    /*
        有参构造函数!
        拷贝构造函数!
        拷贝构造函数!
        无参构造函数!
        析构函数!
        析构函数!
        析构函数!
        析构函数!
        ====
        无参构造函数!
        拷贝构造函数!
        析构函数!
        析构函数!
        ====
        无参构造函数!
        000000E3262FF664
        拷贝构造函数!
        析构函数!
        000000E3262FF7A4
        析构函数!
    */

    return 0;
}
```

对于第三点，如果在 g++ 中加入禁止优化选项，则两个对象的地址不同，具体可参考 [https://developer.51cto.com/article/702353.html](https://developer.51cto.com/article/702353.html)

---

## 构造函数调用规则

默认情况下，C++ 编译器至少给一个类添加 3 个函数

* 默认构造函数(无参，函数体为空)
* 默认析构函数(无参，函数体为空)
* 默认拷贝构造函数，对属性进行值拷贝

构造函数调用规则如下:

* 如果用户定义有参构造函数，C++ 不在提供默认无参构造，但是会提供默认拷贝构造(浅拷贝)
* 如果用户定义拷贝构造函数，C++ 不会再提供其他构造函数

demo:

```cpp
#include <iostream>

using namespace std;

class Person
{
public:
    int age;

public:
    // 无参(默认)构造函数
    Person()
    {
        cout << "无参构造函数!" << endl;
    }
    // 有参构造函数
    Person(int a)
    {
        age = a;
        cout << "有参构造函数!" << endl;
    }
    // 拷贝构造函数
    Person(const Person &p)
    {
        age = p.age;
        cout << "拷贝构造函数!" << endl;
    }
    // 析构函数
    ~Person()
    {
        cout << "析构函数!" << endl;
    }
};

void test01()
{
    Person p1(18);
    // 如果不写拷贝构造，编译器会自动添加拷贝构造，并且做浅拷贝操作
    Person p2(p1);

    cout << "p2 的年龄为： " << p2.age << endl;
}

void test02()
{
    // 如果用户提供有参构造，编译器不会提供默认构造，会提供拷贝构造
    Person p1;     // 此时如果用户自己没有提供默认构造，会出错
    Person p2(10); // 用户提供的有参
    Person p3(p2); // 此时如果用户没有提供拷贝构造，编译器会提供

    // 如果用户提供拷贝构造，编译器不会提供其他构造函数
    Person p4;     // 此时如果用户自己没有提供默认构造，会出错
    Person p5(10); // 此时如果用户自己没有提供有参，会出错
    Person p6(p5); // 用户自己提供拷贝构造
}

int main()
{
    test01();
    cout << "====" << endl;
    test02();

    /*
        有参构造函数!
        拷贝构造函数!
        p2 的年龄为： 18
        析构函数!
        析构函数!
        ====
        无参构造函数!
        有参构造函数!
        拷贝构造函数!
        无参构造函数!
        有参构造函数!
        拷贝构造函数!
        析构函数!
        析构函数!
        析构函数!
        析构函数!
        析构函数!
        析构函数!
    */

    return 0;
}
```

---

## 深拷贝与浅拷贝

深浅拷贝是面试经典问题，也是常见的一个坑

**浅拷贝**：简单的赋值拷贝操作

**深拷贝**：在堆区重新申请空间，进行拷贝操作

demo:

```cpp
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
```

> 总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题

---

## 初始化列表

**作用**:

C++ 提供了初始化列表语法，用来初始化属性

**语法**:

```cpp
构造函数(参数列表): 属性 1(值 1), 属性 2(值 2) ... 
{

}
```

demo:

```cpp
#include <iostream>

using namespace std;

class Person
{
private:
    int m_A;
    int m_B;
    int m_C;

public:
    // 传统方式初始化
    // Person(int a, int b, int c) {
    // 	m_A = a;
    // 	m_B = b;
    // 	m_C = c;
    // }

    // 初始化列表方式初始化
    Person(int a, int b, int c) : m_A(a), m_B(b), m_C(c) {}
    void PrintPerson()
    {
        cout << "mA:" << m_A << endl;
        cout << "mB:" << m_B << endl;
        cout << "mC:" << m_C << endl;
    }
};

int main()
{
    Person p(1, 2, 3);
    p.PrintPerson();

    /*
        mA:1
        mB:2
        mC:3
    */

    return 0;
}
```

---

## 类对象作为类成员

C++ 类中的成员可以是另一个类的对象，称该成员为对象成员

**例如**：

```cpp
class A {};
class B
{
    A a;
}
```

B 类中有对象 A 作为成员，A 为对象成员

那么当创建 B 对象时，A 与 B 的构造和析构的顺序是谁先谁后？

demo:

```cpp
#include <iostream>

using namespace std;

class Phone
{
public:
    string phoneName;

public:
    Phone(string name)
    {
        phoneName = name;
        cout << "Phone 构造" << endl;
    }

    ~Phone()
    {
        cout << "Phone 析构" << endl;
    }
};

class Person
{
public:
    string name;
    Phone phone;

public:
    // 初始化列表可以告诉编译器调用哪一个构造函数
    // phone(name) ==> Phone phone = name
    Person(string name, string pName) : name(name), phone(pName)
    {
        cout << "Person 构造" << endl;
    }

    ~Person()
    {
        cout << "Person 析构" << endl;
    }

    void playGame()
    {
        cout << name << " 使用 " << phone.phoneName << " 牌手机" << endl;
    }
};

void test01()
{
    // 当类中成员是其他类对象时，我们称该成员为对象成员
    // 构造的顺序是：先调用对象成员的构造，再调用本类构造
    // 析构顺序与构造相反
    Person p("张三", "苹果");
    p.playGame();
}

int main()
{
    test01();

    /*
        Phone 构造
        Person 构造
        张三 使用 苹果 牌手机
        Person 析构
        Phone 析构
    */

    return 0;
}
```

---

## 静态成员

静态成员就是在成员变量和成员函数前加上关键字 `static`，称为静态成员

静态成员分为：

* 静态成员变量
    * 所有对象共享同一份数据
    * 在编译阶段分配内存(全局区)
    * 类内声明，类外初始化
* 静态成员函数
    * 所有对象共享同一个函数
    * 静态成员函数只能访问静态成员变量，非静态成员函数可以访问静态成员变量，也可以访问非静态成员变量

**示例 1**: 静态成员变量

code:

```cpp
#include <iostream>

using namespace std;

class Person
{
public:
    static int m_A; // 静态成员变量
    // 静态成员变量特点：
    // 在编译阶段分配内存
    // 类内声明，类外初始化
    // 所有对象共享同一份数据

private:
    static int m_B; // 静态成员变量也是有访问权限的
};

int Person::m_A = 10;
int Person::m_B = 10;

void test01()
{
    // 静态成员变量两种访问方式
    // 通过对象
    Person p1;
    p1.m_A = 100;
    cout << "p1.m_A = " << p1.m_A << endl;

    Person p2;
    p2.m_A = 200;
    cout << "p1.m_A = " << p1.m_A << endl; // 共享同一份数据
    cout << "p2.m_A = " << p2.m_A << endl;

    // 通过类名
    cout << "m_A = " << Person::m_A << endl;
    // cout << "m_B = " << Person::m_B << endl; // 私有权限访问不到
}

int main()
{
    test01();

    /*
        p1.m_A = 100
        p1.m_A = 200
        p2.m_A = 200
        m_A = 200
    */

    return 0;
}
```

**示例 2**：静态成员函数

code:

```cpp
#include <iostream>

using namespace std;

class Person
{
public:
    static int m_A; // 静态成员变量
    int m_B;        // 非静态成员变量

public:
    // 静态成员函数特点：
    // 程序共享一个函数
    // 静态成员函数只能访问静态成员变量

    static void func()
    {
        cout << "func 调用" << endl;
        m_A = 100;
        // m_B = 100; // 错误，不可以访问非静态成员变量，无法区分
    }

private:
    // 静态成员函数也是有访问权限的
    static void func2()
    {
        cout << "func2 调用" << endl;
    }
};

int Person::m_A = 10;

void test01()
{
    // 静态成员变量两种访问方式

    // 通过对象
    Person p1;
    p1.func();

    // 通过类名
    Person::func();

    // Person::func2(); // 私有权限访问不到
}

int main()
{
    test01();

    /*
        func 调用
        func 调用
    */

    return 0;
}
```

---
