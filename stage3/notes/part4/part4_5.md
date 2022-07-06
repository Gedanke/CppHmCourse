# 运算符重载

**运算符重载概念**：

对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型

---

## 加号运算符重载

**作用**：实现两个自定义数据类型相加的运算

demo:

```cpp
#include <iostream>

using namespace std;

class Person
{
public:
    int m_A;
    int m_B;

public:
    Person(){};

    Person(int a, int b)
    {
        this->m_A = a;
        this->m_B = b;
    }

    // 成员函数实现 + 号运算符重载
    Person operator+(const Person &p)
    {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }
};

// 全局函数实现 + 号运算符重载
Person operator+(const Person &p1, const Person &p2)
{
    Person temp(0, 0);
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}

// 运算符重载也可以发生函数重载
Person operator+(const Person &p, int val)
{
    Person temp;
    temp.m_A = p.m_A + val;
    temp.m_B = p.m_B + val;
    return temp;
}

void test()
{
    Person p1(10, 10);
    Person p2(20, 20);

    // 成员函数方式
    Person p3 = p1.operator+(p2); // p1.operaor+(p2)
    cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;

    Person p4 = p1 + p2; // operator+(p1, p2)
    cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;

    Person p5 = p1 + 10; // operator+(p1, 10)
    cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;
}

int main()
{
    test();

    /*
        mA:30 mB:30
        mA:30 mB:30
        mA:30 mB:30
    */

    return 0;
}
```

> 总结 1：对于内置的数据类型的表达式的的运算符是不可能改变的

> 总结 2：不要滥用运算符重载

> 类似的，其他基本运算，如 `+ - * /` 也是相似写法 

---

## 左移运算符重载

**作用**：可以输出自定义数据类型

demo:

```cpp
#include <iostream>

using namespace std;

class Person
{
private:
    int m_A;
    int m_B;

    // 声明友元函数
    friend ostream &operator<<(ostream &out, const Person &p);
    friend istream &operator>>(istream &in, Person &p);

public:
    Person()
    {
    }

    Person(int a, int b)
    {
        this->m_A = a;
        this->m_B = b;
    }

    // 成员函数 实现不了 p << cout，不是我们想要的效果
    // void operator<<(Person& p){
    // }
};

// 全局函数实现左移重载
// ostream 对象只能有一个
ostream &operator<<(ostream &out, const Person &p)
{
    out << "a:" << p.m_A << " b:" << p.m_B;
    return out;
}

// istream 对象只能有一个
istream &operator>>(istream &in, Person &p)
{
    in >> p.m_A >> p.m_B;
    return in;
}

void test()
{
    Person p;
    cout << "input person: " << endl;
    cin >> p;
    cout << p << endl; // 链式编程
}

int main()
{
    test();

    /*
        input person:
        12 12
        a:12 b:12
    */

    return 0;
}
```

> 总结：重载左移运算符配合友元可以实现输出自定义数据类型；类似的，重载右移运算符配合友元可以实现输入自定义数据类型

---

## 递增运算符重载

**作用**：通过重载递增运算符，实现自己的整型数据

demo:

```cpp
#include <iostream>

using namespace std;

class MyInteger
{
private:
    int num;

    friend ostream &operator<<(ostream &out, MyInteger myint);

public:
    MyInteger()
    {
        this->num = 0;
    }
    // 前置++
    MyInteger &operator++()
    {
        // 先++
        this->num++;
        // 再返回，返回自身引用，如果返回类型不是引用，则只是递增后的一个副本，不是调用前置++ 的当前对象本身
        return *this;
    }

    // 后置++，int 是占位参数，用于区分前置还是后置递增或者递减
    MyInteger operator++(int)
    {
        // 先返回
        MyInteger temp = *this; // 记录当前本身的值，然后让本身的值加 1，但是返回的是以前的值，达到先返回后 ++
        ++this->num;
        // 后置引用要返回值，而不是引用，因为 temp 是临时变量
        return temp;
    }
};

ostream &operator<<(ostream &out, MyInteger myint)
{
    out << myint.num;
    return out;
}

// 前置++，先 ++，再返回
void test1()
{
    MyInteger myInt;
    cout << ++myInt << endl;
    cout << myInt << endl;
    cout << ++myInt << endl;
    cout << myInt << endl;
}

// 后置++，先返回，再 ++
void test2()
{
    MyInteger myInt;
    cout << myInt++ << endl;
    cout << myInt << endl;
    cout << myInt++ << endl;
    cout << myInt << endl;
}

int main()
{
    test1();
    cout << "======" << endl;
    test2();

    /*
        1
        1
        2
        2
        ======
        0
        1
        1
        2
    */

    return 0;
}
```

> 前置递增返回引用，后置递增返回值。区分前置与后置的写法，并类推到递减操作

---

## 赋值运算符重载

C++ 编译器至少给一个类添加 4 个函数

* 默认构造函数(无参，函数体为空)
* 默认析构函数(无参，函数体为空)
* 默认拷贝构造函数，对属性进行值拷贝
* 赋值运算符 `operator=`，对属性进行值拷贝

如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题

demo:

```cpp
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
```

> 如果类中有属性指向堆区，一定要自己提供拷贝构造函数以及析构函数，避免默认的函数因浅拷贝而造成内存重复释放等问题

---

## 关系运算符重载

**作用**：重载关系运算符，可以让两个自定义类型对象进行对比操作

demo:

```cpp
#include <iostream>

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
    };

    bool operator==(Person &p)
    {
        if (this->name == p.name && this->age == p.age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator!=(Person &p)
    {
        if (this->name == p.name && this->age == p.age)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

void test1()
{
    // int a = 0;
    // int b = 0;

    Person a("孙悟空", 18);
    Person b("孙悟空", 18);

    if (a == b)
    {
        cout << "a 和 b 相等" << endl;
    }
    else
    {
        cout << "a 和 b 不相等" << endl;
    }

    if (a != b)
    {
        cout << "a 和 b 不相等" << endl;
    }
    else
    {
        cout << "a 和 b 相等" << endl;
    }
}

int main()
{
    test1();

    /*
        a 和 b 相等
        a 和 b 相等
    */

    return 0;
}
```

> 比较操作需要比较到每个成员变量，如果类成员不是基本类型，类成员也要重载比较运算符，此时需要进一步向下比较每一位成员的成员变量

---

## 函数调用运算符重载

* 函数调用运算符 `()` 也可以重载
* 由于重载后使用的方式非常像函数的调用，因此称为仿函数
* 仿函数没有固定写法，非常灵活

demo:

```cpp
#include <iostream>

using namespace std;

class MyPrint
{
public:
    void operator()(string text)
    {
        cout << text << endl;
    }
};

void test1()
{
    // 重载的 () 操作符也称为仿函数
    MyPrint myFunc;
    myFunc("hello world");
}

class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

void test2()
{
    MyAdd add;
    int ret = add(10, 10);
    cout << "ret = " << ret << endl;

    // 匿名对象调用
    cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
}

int main()
{
    test1();
    test2();

    /*
        hello world
        ret = 20
        MyAdd()(100,100) = 200
    */

    return 0;
}
```

---
