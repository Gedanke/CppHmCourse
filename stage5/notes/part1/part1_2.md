# 类模板

---

## 类模板语法

**类模板作用**：

* 建立一个通用类，类中的成员数据类型可以不具体制定，用一个 **虚拟的类型** 来代表

**语法**：

```c++
template <typename T>
class 类名
{
    ...
};
```

**解释**：

* `template` --- 声明创建模板
* `typename` --- 表面其后面的符号是一种数据类型，可以用 `class` 代替
* `T` --- 通用的数据类型，名称可以替换，通常为大写字母

demo:

```cpp
#include <iostream>

using namespace std;

// 类模板
template <class NameType, class AgeType>
class Person
{
public:
    NameType name;
    AgeType age;

public:
    Person(NameType name, AgeType age)
    {
        this->name = name;
        this->age = age;
    }

    void showPerson()
    {
        cout << "name: " << this->name << " age: " << this->age << endl;
    }
};

void test1()
{
    // 指定 NameType 为 string 类型，AgeType 为 int 类型
    Person<string, int> p1("孙悟空", 999);
    p1.showPerson();
}

void test2()
{
    // 指定 NameType 为 string 类型，AgeType 为 string 类型
    Person<string, string> p1("孙悟空", "64");
    p1.showPerson();
}

int main()
{
    test1();

    test2();

    /*
        name: 孙悟空 age: 999
        name: 孙悟空 age: 64
    */

    return 0;
}
```

> 总结：类模板和函数模板语法相似，在声明模板 `template` 后面加类，此类称为类模板

---

## 类模板与函数模板区别

类模板与函数模板区别主要有两点：

* 类模板没有自动类型推导的使用方式
* 类模板在模板参数列表中可以有默认参数

demo:

```cpp
#include <iostream>

using namespace std;

// 类模板
template <class NameType, class AgeType = int>
class Person
{
public:
    NameType name;
    AgeType age;

public:
    Person(NameType name, AgeType age)
    {
        this->name = name;
        this->age = age;
    }

    void showPerson()
    {
        cout << "name: " << this->name << " age: " << this->age << endl;
    }
};

// 类模板没有自动类型推导的使用方式
void test1()
{
    // Person p("孙悟空", 1000); // 错误，类模板使用时候，不可以用自动类型推导。缺少类模板 "Person" 的参数列表
    Person<string, int> p("孙悟空", 1000); // 必须使用显示指定类型的方式，使用类模板
    p.showPerson();
}

// 类模板在模板参数列表中可以有默认参数
void test2()
{
    Person<string> p("猪八戒", 999); // 类模板中的模板参数列表可以指定默认参数
    p.showPerson();
}

// 类模板在模板参数列表中可以有默认参数
void test3()
{
    // Person<string> p_("猪八戒", "99.9"); // 没有与参数列表匹配的构造函数 "Person<NameType, AgeType>::Person [其中 NameType=std::string, AgeType=int]" 实例
    Person<string> p("猪八戒", 99.9); // 发生了类型转换
    p.showPerson();
}

void test4()
{
    Person<string, double> p("猪八戒", 99.9);
    p.showPerson();
}

int main()
{
    test1();

    test2();

    test3();

    test4();

    /*
        name: 孙悟空 age: 1000
        name: 猪八戒 age: 999
        name: 猪八戒 age: 99
        name: 猪八戒 age: 99.9
    */

    return 0;
}
```

> 类模板使用只能用显示指定类型方式

> 类模板中的模板参数列表可以有默认参数

---

## 类模板中成员函数创建时机

类模板中成员函数和普通类中成员函数创建时机是有区别的：

* 普通类中的成员函数一开始就可以创建
* 类模板中的成员函数在调用时才创建

demo:

```cpp
#include <iostream>

using namespace std;

class Person1
{
public:
    void showPerson1()
    {
        cout << "Person1 show" << endl;
    }
};

class Person2
{
public:
    void showPerson2()
    {
        cout << "Person2 show" << endl;
    }
};

template <class T>
class MyClass
{
public:
    T obj;

public:
    // 类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成
    void fun1()
    {
        obj.showPerson1();
    }

    void fun2()
    {
        obj.showPerson2();
    }
};

void test()
{
    MyClass<Person1> m1;
    m1.fun1();
    // m1.fun2();

    /*
        main.cpp: In instantiation of ‘void MyClass<T>::fun2() [with T = Person1]’:
        main.cpp:44:13:   required from here
        main.cpp:37:13: error: ‘class Person1’ has no member named ‘showPerson2’; did you mean ‘showPerson1’?
           37 |         obj.showPerson2();
              |         ~~~~^~~~~~~~~~~
              |         showPerson1
    */

    MyClass<Person2> m2;
    m2.fun2();
}

int main()
{
    test();

    /*
        Person1 show
        Person2 show
    */

    return 0;
}
```

> 总结：类模板中的成员函数并不是一开始就创建的，在调用时才去创建

---

## 类模板对象做函数参数

**学习目标**：

* 类模板实例化出的对象，向函数传参的方式

一共有三种传入方式：

* 指定传入的类型 --- 直接显示对象的数据类型
* 参数模板化 --- 将对象中的参数变为模板进行传递
* 整个类模板化 --- 将这个对象类型 模板化进行传递

demo:

```cpp
#include <iostream>

using namespace std;

// 类模板
template <class NameType, class AgeType = int>
class Person
{
public:
    NameType name;
    AgeType age;

public:
    Person(NameType name, AgeType age)
    {
        this->name = name;
        this->age = age;
    }

    void showPerson()
    {
        cout << "name: " << this->name << " age: " << this->age << endl;
    }
};

// 指定传入的类型
void printPerson1(Person<string, int> &p)
{
    p.showPerson();
}

void test1()
{
    Person<string> p("孙悟空", 100);
    printPerson1(p);
}

// 参数模板化
template <class T1, class T2>
void printPerson2(Person<T1, T2> &p)
{
    p.showPerson();
    cout << "T1 的类型为： " << typeid(T1).name() << endl;
    cout << "T2 的类型为： " << typeid(T2).name() << endl;
}

void test2()
{
    // int 类型简写为 i，double 类型简写为 d
    Person<string, int> p("猪八戒", 90);
    printPerson2(p);
}

// 整个类模板化
template <class T>
void printPerson3(T &p)
{
    cout << "T 的类型为： " << typeid(T).name() << endl;
    p.showPerson();
}

void test3()
{
    Person<string, int> p("唐僧", 30);
    printPerson3(p);

    Person<string, double> pp("唐僧", 30.2);
    printPerson3(pp);

    cout << (typeid(p).name() == typeid(pp).name()) << endl;
}

int main()
{
    test1();
    cout << "======" << endl;
    test2();
    cout << "======" << endl;
    test3();

    /*
        name: 孙悟空 age: 100
        ======
        name: 猪八戒 age: 90
        T1 的类型为： NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
        T2 的类型为： i
        ======
        T 的类型为： 6PersonINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE
        name: 唐僧 age: 30
        T 的类型为： 6PersonINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEdE
        name: 唐僧 age: 30.2
        0
    */

    return 0;
}
```

> 通过类模板创建的对象，可以有三种方式向函数中进行传参

> 使用比较广泛是第一种：指定传入的类型

---

## 类模板与继承

当类模板碰到继承时，需要注意一下几点：

* 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中 `T` 的类型
* 如果不指定，编译器无法给子类分配内存
* 如果想灵活指定出父类中 `T` 的类型，子类也需变为类模板

demo:

```cpp
#include <iostream>

using namespace std;

template <class T>
class Base
{
public:
    T base;
};

// class Son:public Base {}; // 错误，c++ 编译需要给子类分配内存，必须知道父类中 T 的类型才可以向下继承。缺少类模板 "Base" 的参数列表
// 必须指定一个类型
class Son : public Base<int>
{
};

void test1()
{
    Son c;
}

// 类模板继承类模板，可以用 T2 指定父类中的 T 类型
template <class T1, class T2>
class Son2 : public Base<T2>
{
public:
    T1 son2;

public:
    Son2()
    {
        cout << typeid(T1).name() << endl;
        cout << typeid(T2).name() << endl;
    }
};

void test2()
{
    Son2<int, char> child1;
}

int main()
{
    test1();
    test2();

    /*
        i
        c
    */

    return 0;
}
```

> 总结：如果父类是类模板，子类需要指定出父类中 `T` 的数据类型

---

## 类模板成员函数类外实现

**学习目标**：

能够掌握类模板中的成员函数类外实现

demo:

```cpp
#include <iostream>

using namespace std;

template <class T1, class T2>
class Person
{
public:
    T1 name;
    T2 age;

public:
    // 成员函数类内声明
    Person(T1 name, T2 age);
    void showPerson();
};

// 构造函数类外实现
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->name = name;
    this->age = age;
}

// 成员函数类外实现
template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << "姓名: " << this->name << " 年龄: " << this->age << endl;
}

void test1()
{
    Person<string, int> p("Tom", 22);
    p.showPerson();
}

int main()
{
    test1();

    /*
        姓名: Tom 年龄: 22
     */

    return 0;
}
```

> 总结：类模板中成员函数类外实现时，需要加上模板参数列表

---

## 类模板分文件编写

**学习目标**：

* 掌握类模板成员函数分文件编写产生的问题以及解决方式

**问题**：

* 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到

**解决**：

* 解决方式 1：直接包含 `.cpp` 源文件
* 解决方式 2：将声明和实现写到同一个文件中，并更改后缀名为 `.hpp`，`hpp` 是约定的名称，并不是强制

demo:

`person.h`

```h
#pragma once
#include <iostream>

using namespace std;

template <class T1, class T2>
class Person
{
public:
    T1 name;
    T2 age;

public:
    // 成员函数类内声明
    Person(T1 name, T2 age);
    void showPerson();
};
```

`person.cpp`

```cpp
#include "person.h"

// 构造函数类外实现
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->name = name;
    this->age = age;
}

// 成员函数类外实现
template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << "姓名: " << this->name << " 年龄: " << this->age << endl;
}
```

`person.hpp`

```cpp
#pragma once
#include <iostream>

using namespace std;

template <class T1, class T2>
class Person
{
public:
    T1 name;
    T2 age;

public:
    // 成员函数类内声明
    Person(T1 name, T2 age);
    void showPerson();
};

// 构造函数类外实现
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->name = name;
    this->age = age;
}

// 成员函数类外实现
template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << "姓名: " << this->name << " 年龄: " << this->age << endl;
}
```

`main.cpp`

```cpp
#include <iostream>
// #include "person.h" // 只包含 .h 的文件是不行的
#include "person.cpp" // 解决方式 1，包含 cpp 源文件

// 解决方式 2，将声明和实现写到一起，文件后缀名改为 .hpp
// #include "person.hpp"

using namespace std;

void test1()
{
    Person<string, int> p("Tom", 22);
    p.showPerson();
}

int main()
{
    test1();

    /*
        姓名: Tom 年龄: 22
     */

    return 0;
}
```

> 总结：主流的解决方式是第二种，将类模板成员函数写到一起，并将后缀名改为 `.hpp`

---

## 类模板与友元

**学习目标**：

掌握类模板配合友元函数的类内和类外实现

* 全局函数类内实现 - 直接在类内声明友元即可
* 全局函数类外实现 - 需要提前让编译器知道全局函数的存在

demo:

```cpp
#include <iostream>

using namespace std;

// 全局函数配合友元，类外实现 - 先做函数模板声明，下方在做函数模板定义，在做友元
template <class T1, class T2>
class Person;

// 如果声明了函数模板，可以将实现写到后面，否则需要将实现体写到类的前面让编译器提前看到
// template<class T1, class T2> void printPerson2(Person<T1, T2> & p);

template <class T1, class T2>
void printPerson2(Person<T1, T2> &p)
{
    cout << "类外实现 ---- 姓名：" << p.name << " 年龄：" << p.age << endl;
}

template <class T1, class T2>
class Person
{
private:
    T1 name;
    T2 age;

private:
    // 全局函数配合友元，类内实现
    friend void printPerson(Person<T1, T2> &p)
    {
        cout << "类内实现 ---- 姓名：" << p.name << " 年龄：" << p.age << endl;
    }

    // 全局函数配合友元，类外实现
    friend void printPerson2<>(Person<T1, T2> &p);

public:
    Person(T1 name, T2 age)
    {
        this->name = name;
        this->age = age;
    }
};

// 全局函数在类内实现
void test1()
{
    Person<string, int> p("Tom", 20);
    printPerson(p);
}

// 全局函数在类外实现
void test2()
{
    Person<string, int> p("Jerry", 30);
    printPerson2(p);
}

int main()
{
    test1();
    test2();

    /*
        类内实现 ---- 姓名：Tom 年龄：20
        类外实现 ---- 姓名：Jerry 年龄：30
    */

    return 0;
}
```

> 总结：建议全局函数做类内实现，用法简单，而且编译器可以直接识别

---
