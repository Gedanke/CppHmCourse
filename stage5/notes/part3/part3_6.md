# set 与 multiset 容器

---

## set 基本概念

**简介**：

* 所有元素都会在插入时自动被排序

**本质**：

* `set/multiset` 属于 **关联式容器**，底层结构是用 **二叉树** 实现

`set` 和 `multiset` **区别**：

* `set` 不允许容器中有重复的元素
* `multiset` 允许容器中有重复的元素

---

## set 构造和赋值

**功能描述**：

创建 `set` 容器以及赋值

**构造**：

* `set<T> st;`  默认构造函数
* `set(const set &st);` 拷贝构造函数

**赋值**：

* `set& operator=(const set &st);`  重载等号操作符

demo:

```cpp
#include <iostream>
#include <set>

using namespace std;

void printSet(set<int> &s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 构造和赋值
void test1()
{
    set<int> s1;

    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(20);
    s1.insert(40);
    printSet(s1);

    // 拷贝构造
    set<int> s2(s1);
    printSet(s2);

    // 赋值
    set<int> s3;
    s3 = s2;
    printSet(s3);

    set<int> s4{10, 20, 30, 40, 10};
    printSet(s4);
}

int main()
{
    test1();

    /*
        10 20 30 40
        10 20 30 40
        10 20 30 40
        10 20 30 40
    */

    return 0;
}
```

总结：

* `set` 容器插入数据时用 `insert`
* `set` 容器插入数据的数据会自动排序

---

## set 大小和交换

**功能描述：**

* 统计 `set` 容器大小以及交换 `set` 容器

**函数原型**：

* `size();` 返回容器中元素的数目
* `empty();`    判断容器是否为空
* `swap(st);`   交换两个集合容器

demo:

```cpp
#include <iostream>
#include <set>

using namespace std;

void printSet(set<int> &s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 大小
void test1()
{
    set<int> s1;

    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    if (s1.empty())
    {
        cout << "s1 为空" << endl;
    }
    else
    {
        cout << "s1 不为空" << endl;
        cout << "s1 的大小为：" << s1.size() << endl;
    }
}

// 交换
void test2()
{
    set<int> s1;

    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    set<int> s2;

    s2.insert(100);
    s2.insert(300);
    s2.insert(200);
    s2.insert(400);

    cout << "交换前" << endl;
    printSet(s1);
    printSet(s2);

    cout << "交换后" << endl;
    s1.swap(s2);
    printSet(s1);
    printSet(s2);
}

int main()
{
    test1();
    test2();

    /*
        s1 不为空
        s1 的大小为：4
        交换前
        10 20 30 40
        100 200 300 400
        交换后
        100 200 300 400
        10 20 30 40
    */

    return 0;
}
```

总结：

* 统计大小 --- `size`
* 判断是否为空 --- `empty`
* 交换容器 --- `swap`

---

## set 插入和删除

**功能描述**：

* `set` 容器进行插入数据和删除数据

**函数原型**：

* `insert(elem);`   在容器中插入元素
* `clear();`    清除所有元素
* `erase(pos);` 删除 `pos` 迭代器所指的元素，返回下一个元素的迭代器
* `erase(beg, end);`    删除区间 `[beg, end)` 的所有元素，返回下一个元素的迭代器
* `erase(elem);`    删除容器中值为 `elem` 的元素

demo:

```cpp
#include <iostream>
#include <set>

using namespace std;

void printSet(set<int> &s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 插入和删除
void test1()
{
    set<int> s1{10, 20, 30, 60, 50, 40};

    s1.insert(40);
    printSet(s1);

    // 删除
    s1.erase(s1.begin());
    printSet(s1);

    s1.erase(30);
    printSet(s1);

    // 清空
    s1.erase(++s1.begin(), --s1.end());
    printSet(s1);

    s1.clear();
    printSet(s1);
}

int main()
{
    test1();

    /*
        10 20 30 40 50 60
        20 30 40 50 60
        20 40 50 60
        20 60

    */

    return 0;
}
```

总结：

* 插入 --- `insert`
* 删除 --- `erase`
* 清空 --- `clear`

---

## set 查找和统计

**功能描述**：

* 对 `set` 容器进行查找数据以及统计数据

**函数原型**：

* `find(key);`  查找 `key` 是否存在。若存在，返回该键的元素的迭代器；若不存在，返回 `set.end()`
* `count(key);` 统计 `key` 的元素个数

demo:

```cpp
#include <iostream>
#include <set>

using namespace std;

// 查找和统计
void test1()
{
    set<int> s1{10, 20, 30, 30, 30, 50, 40};

    // 查找
    set<int>::iterator pos = s1.find(30);

    if (pos != s1.end())
    {
        cout << "找到了元素：" << *pos << endl;
    }
    else
    {
        cout << "未找到元素" << endl;
    }

    // 统计
    int num = s1.count(30);
    cout << "num = " << num << endl;
}

int main()
{
    test1();

    /*
        找到了元素：30
        num = 1
    */

    return 0;
}
```

总结：

* 查找 --- `find`(返回的是迭代器）
* 统计 --- `count`(对于`set`，结果为 0 或者 1)

---

## set 和 multiset 区别

**学习目标**：

* 掌握 `set` 和 `multiset` 的区别

**区别**：

* `set` 不可以插入重复数据，而 `multiset` 可以
* `set` 插入数据的同时会返回插入结果，表示插入是否成功
* `multiset` 不会检测数据，因此可以插入重复数据

demo:

```cpp
#include <iostream>
#include <set>

using namespace std;

// set 和 multiset 区别
void test1()
{
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);
    if (ret.second)
    {
        cout << "第一次插入成功!" << endl;
    }
    else
    {
        cout << "第一次插入失败!" << endl;
    }

    ret = s.insert(10);
    if (ret.second)
    {
        cout << "第二次插入成功!" << endl;
    }
    else
    {
        cout << "第二次插入失败!" << endl;
    }

    // multiset
    multiset<int> ms;
    ms.insert(10);
    auto p = ms.insert(10);
    cout << *p << endl;

    for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    test1();

    /*
        第一次插入成功!
        第二次插入失败!
        10
        10 10
    */

    return 0;
}
```

总结：

* 如果不允许插入重复数据可以利用 `set`
* 如果需要插入重复数据利用 `multiset`

---

## pair 对组创建

**功能描述**：

* 成对出现的数据，利用对组可以返回两个数据

**两种创建方式**：

* `pair<type, type> p(value1, value2);`
* `pair<type, type> p = make_pair(value1, value2);`

demo:

```cpp
#include <iostream>
#include <set>

using namespace std;

// 对组创建
void test1()
{
    pair<string, int> p(string("Tom"), 20);
    cout << "姓名：" << p.first << " 年龄：" << p.second << endl;

    pair<string, int> p2 = make_pair("Jerry", 10);
    cout << "姓名：" << p2.first << " 年龄：" << p2.second << endl;
}

int main()
{
    test1();

    /*
        姓名：Tom 年龄：20
        姓名：Jerry 年龄：10
    */

    return 0;
}
```

> 两种方式都可以创建对组，记住一种即可

---

## set 容器排序

学习目标：

* `set` 容器默认排序规则为从小到大，掌握如何改变排序规则

主要技术点：

* 利用仿函数，可以改变排序规则

**示例一**   

`set` 存放内置数据类型

code:

```cpp
#include <iostream>
#include <set>

using namespace std;

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test1()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(50);

    // 默认从小到大
    for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 指定排序规则
    set<int, MyCompare> s2;
    s2.insert(10);
    s2.insert(40);
    s2.insert(20);
    s2.insert(30);
    s2.insert(50);

    for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    test1();

    /*
        10 20 30 40 50
        50 40 30 20 10
    */

    return 0;
}
```

> 利用仿函数可以指定 `set` 容器的排序规则

**示例二** 

`set` 存放自定义数据类型

code:

```cpp
#include <iostream>
#include <set>

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

class comparePerson
{
public:
    bool operator()(const Person &p1, const Person &p2)
    {
        // 按照年龄进行排序，降序
        return p1.age > p2.age;
    }
};

void test1()
{
    // set<Person> s; // error
    set<Person, comparePerson> s;

    Person p1("刘备", 23);
    Person p2("关羽", 27);
    Person p3("张飞", 25);
    Person p4("赵云", 21);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "姓名：" << it->name << " 年龄：" << it->age << endl;
    }
}

int main()
{
    test1();

    /*
        姓名：关羽 年龄：27
        姓名：张飞 年龄：25
        姓名：刘备 年龄：23
        姓名：赵云 年龄：21
    */

    return 0;
}
```

> 对于自定义数据类型，`set` 必须指定排序规则才可以插入数据

> 除了 `set`，`multiset` 外，`unordered_set` 也是经常用到的，在某些场合，效率会比 `set` 高

---
