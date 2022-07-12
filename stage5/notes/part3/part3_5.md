# list 容器

---

## list 基本概念

**功能**：

将数据进行链式存储

**链表**(`list`)是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的

链表的组成：链表由一系列 **结点** 组成

结点的组成：一个是存储数据元素的 **数据域**，另一个是存储下一个结点地址的 **指针域**

STL 中的链表是一个双向循环链表

![](../../photos/part3/5_11.jpg)

由于链表的存储方式并不是连续的内存空间，因此链表 `list` 中的迭代器只支持前移和后移，属于 **双向迭代器**

`list` 的优点：

* 采用动态存储分配，不会造成内存浪费和溢出
* 链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素

`list` 的缺点：

* 链表灵活，但是空间(指针域)和时间(遍历)额外耗费较大

`list` 有一个重要的性质，插入操作和删除操作都不会造成原有 `list` 迭代器的失效，这在 `vector` 是不成立的

总结：STL 中 `list` 和 `vector` 是两个最常被使用的容器，各有优缺点

---

## list 构造函数

**功能描述**：

* 创建 `list` 容器

**函数原型**：

* `list<T> lst;`    `list` 采用采用模板类实现，对象的默认构造形式
* `list(beg, end);`  构造函数将 `[beg, end)` 区间中的元素拷贝给本身
* `list(n, elem);`   构造函数将 `n` 个 `elem` 拷贝给本身
* `list(const list &lst);`  拷贝构造函数

demo:

```cpp
#include <iostream>
#include <list>

using namespace std;

void printList(const list<int> &L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test1()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    printList(L1);

    // list<int>L2(L1.begin() + 1, L1.end() - 1); // 没有与这些操作数匹配的 "+" 运算符C/C++(349)
    list<int> L2(L1.begin(), L1.end());
    printList(L2);

    list<int> L3(L2);
    printList(L3);

    list<int> L4(10, 1000);
    printList(L4);
}

int main()
{
    test1();

    /*
        10 20 30 40
        10 20 30 40
        10 20 30 40
        1000 1000 1000 1000 1000 1000 1000 1000 1000 1000
    */

    return 0;
}
```

> 总结：`list` 构造方式同其他几个 STL 常用容器，熟练掌握即可

---

## list 赋值和交换

**功能描述**：

* 给 `list` 容器进行赋值，以及交换 `list` 容器

**函数原型**：

* `assign(beg, end);`   将 `[beg, end)` 区间中的数据拷贝赋值给本身
* `assign(n, elem);`    将 `n` 个 `elem` 拷贝赋值给本身
* `list& operator=(const list &lst);`   重载等号操作符
* `swap(lst);`  将 `lst` 与本身的元素互换

demo:

```cpp
#include <iostream>
#include <list>

using namespace std;

void printList(const list<int> &L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 赋值和交换
void test1()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);

    // 赋值
    list<int> L2;
    L2 = L1;
    printList(L2);

    list<int> L3;
    L3.assign(L2.begin(), L2.end());
    printList(L3);

    list<int> L4;
    L4.assign(10, 100);
    printList(L4);
}

// 交换
void test2()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    list<int> L2;
    L2.assign(10, 100);
    cout << "交换前：" << endl;
    printList(L1);
    printList(L2);

    L1.swap(L2);
    cout << "交换后：" << endl;
    printList(L1);
    printList(L2);
}

int main()
{
    test1();
    cout << "=========" << endl;
    test2();

    /*
        10 20 30 40
        10 20 30 40
        10 20 30 40
        100 100 100 100 100 100 100 100 100 100
        =========
        交换前：
        10 20 30 40
        100 100 100 100 100 100 100 100 100 100
        交换后：
        100 100 100 100 100 100 100 100 100 100
        10 20 30 40
    */

    return 0;
}
```

> 总结：`list` 赋值和交换操作能够灵活运用即可

---

## list 大小操作

**功能描述**：

* 对 `list` 容器的大小进行操作

**函数原型**：

* `size();` 返回容器中元素的个数
* `empty();`    判断容器是否为空
* `resize(num);`    重新指定容器的长度为 `num`，若容器变长，则以默认值填充新位置；如果容器变短，则末尾超出容器长度的元素被删除
* `resize(num, elem);`  重新指定容器的长度为 `num`，若容器变长，则以 `elem` 值填充新位置；如果容器变短，则末尾超出容器长度的元素被删除

demo:

```cpp
#include <iostream>
#include <list>

using namespace std;

void printList(const list<int> &L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 大小操作
void test1()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    if (L1.empty())
    {
        cout << "L1 为空" << endl;
    }
    else
    {
        cout << "L1 不为空" << endl;
        cout << "L1 的大小为：" << L1.size() << endl;
    }

    // 重新指定大小
    L1.resize(10);
    printList(L1);

    L1.resize(2);
    printList(L1);
}

int main()
{
    test1();

    /*
        L1 不为空
        L1 的大小为：4
        10 20 30 40 0 0 0 0 0 0
        10 20
    */

    return 0;
}
```

总结：

* 判断是否为空 --- `empty`
* 返回元素个数 --- `size`
* 重新指定个数 --- `resize`

---

## list 插入和删除

**功能描述**：

* 对 `list` 容器进行数据的插入和删除

**函数原型**：

* `push_back(elem);`    在容器尾部加入一个元素
* `pop_back();` 删除容器中最后一个元素
* `push_front(elem);`   在容器开头插入一个元素
* `pop_front();`    从容器开头移除第一个元素
* `insert(pos, elem);`  在 `pos` 位置插 `elem` 元素的拷贝，返回新数据的位置
* `insert(pos, n, elem);`   在 `pos` 位置插入 `n` 个 `elem` 数据，无返回值
* `insert(pos, beg, end);`  在 `pos` 位置插入 `[beg, end)` 区间的数据，无返回值
* `clear();`    移除容器的所有数据
* `erase(beg, end);`    删除 `[beg,end)` 区间的数据，返回下一个数据的位置
* `erase(pos);` 删除 `pos` 位置的数据，返回下一个数据的位置
* `remove(elem);`   删除容器中所有与 `elem` 值匹配的元素

demo:

```cpp
#include <iostream>
#include <list>

using namespace std;

void printList(const list<int> &L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 插入和删除
void test1()
{
    list<int> L;
    // 尾插
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    // 头插
    L.push_front(100);
    L.push_front(200);
    L.push_front(300);

    printList(L);

    // 尾删
    L.pop_back();
    printList(L);

    // 头删
    L.pop_front();
    printList(L);

    // 插入
    list<int>::iterator it = L.begin();
    ++it;
    auto postion = L.insert(it, 1000);
    cout << *postion << endl;
    printList(L);

    // 删除
    it = L.begin();
    // it = it + 1; // 没有与这些操作数匹配的 "+" 运算符
    it++;
    L.erase(it);
    printList(L);

    // 移除
    L.push_back(10000);
    L.push_back(10000);
    L.push_back(10000);
    printList(L);
    L.remove(10000);
    printList(L);

    // 清空
    L.clear();
    printList(L);
}

int main()
{
    test1();

    /*
        300 200 100 10 20 30
        300 200 100 10 20
        200 100 10 20
        1000
        200 1000 100 10 20
        200 100 10 20
        200 100 10 20 10000 10000 10000
        200 100 10 20

    */

    return 0;
}
```

总结：

* 尾插 --- `push_back`
* 尾删 --- `pop_back`
* 头插 --- `push_front`
* 头删 --- `pop_front`
* 插入 --- `insert`
* 删除 --- `erase`
* 移除 --- `remove`
* 清空 --- `clear`

---

## list 数据存取

**功能描述**：

* 对 `list` 容器中数据进行存取

**函数原型**：

* `front();`    返回第一个元素
* `back();` 返回最后一个元素

demo:

```cpp
#include <iostream>
#include <list>

using namespace std;

// 数据存取
void test1()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    // cout << L1.at(0) << endl; // 错误，不支持 at 访问数据
    // cout << L1[0] << endl; // 错误，不支持 [] 方式访问数据
    cout << "第一个元素为：" << L1.front() << endl;
    cout << "最后一个元素为：" << L1.back() << endl;

    // list 容器的迭代器是双向迭代器，不支持随机访问
    list<int>::iterator it = L1.begin();
    // it = it + 1; // 错误，不可以跳跃访问，即使是 +1

    advance(it, 2);
    cout << *it << endl;
}

int main()
{
    test1();

    /*
        第一个元素为：10
        最后一个元素为：40
        30
    */

    return 0;
}
```

总结：

* `list` 容器中不可以通过 `[]` 或者 `at` 方式访问数据
* 返回第一个元素 --- `front`
* 返回最后一个元素 --- `back`
* `list` 容器迭代器只能进行 `++` 和 `--`，不能进行算术运算，如果想大幅度移动迭代器，可以用 `advance(it, step)`

---

## list 反转和排序

**功能描述**：

* 将容器中的元素反转，以及将容器中的数据进行排序

**函数原型**：

* `reverse();`  反转链表
* `sort();` 链表排序

demo:

```cpp
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void printList(const list<int> &L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

bool myCompare(int val1, int val2)
{
    return val1 > val2;
}

// 反转和排序
void test1()
{
    list<int> L;
    L.push_back(90);
    L.push_back(30);
    L.push_back(20);
    L.push_back(70);
    printList(L);

    // 反转容器的元素
    L.reverse();
    printList(L);

    // 排序
    L.sort(); // 默认的排序规则 从小到大
    printList(L);

    L.sort(myCompare); // 指定规则，从大到小
    printList(L);

    // sort(L.begin(), L.end()); // error
}

int main()
{
    test1();

    /*
        90 30 20 70
        70 20 30 90
        20 30 70 90
        90 70 30 20
    */

    return 0;
}
```

总结：

* 反转 --- `reverse`
* 排序 --- `sort`(内部提供了成员函数)，所有不支持随机访问迭代器的容器，不可以使用标准的 `sort` 算法

---

## 排序案例

案例描述：将 `Person` 自定义数据类型进行排序，`Person` 中属性有姓名、年龄、身高

排序规则：按照年龄进行升序，如果年龄相同按照身高进行升序

demo:

```cpp
#include <iostream>
#include <list>

using namespace std;

class Person
{
public:
    string name; // 姓名
    int age;     // 年龄
    int height;  // 身高

public:
    Person(string name, int age, int height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
    }
};

bool ComparePerson(Person &p1, Person &p2)
{
    if (p1.age == p2.age)
    {
        return p1.height < p2.height;
    }
    else
    {
        return p1.age < p2.age;
    }
}

void test1()
{
    list<Person> L;

    Person p1("刘备", 35, 175);
    Person p2("曹操", 45, 180);
    Person p3("孙权", 40, 170);
    Person p4("赵云", 25, 190);
    Person p5("张飞", 35, 160);
    Person p6("关羽", 35, 200);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);

    for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "姓名：" << it->name << " 年龄：" << it->age
             << " 身高：" << it->height << endl;
    }
    cout << "---------------------------------" << endl;
    L.sort(ComparePerson); // 排序
    for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "姓名：" << it->name << " 年龄：" << it->age
             << " 身高：" << it->height << endl;
    }
}

int main()
{
    test1();

    /*
        姓名：刘备 年龄：35 身高：175
        姓名：曹操 年龄：45 身高：180
        姓名：孙权 年龄：40 身高：170
        姓名：赵云 年龄：25 身高：190
        姓名：张飞 年龄：35 身高：160
        姓名：关羽 年龄：35 身高：200
        ---------------------------------
        姓名：赵云 年龄：25 身高：190
        姓名：张飞 年龄：35 身高：160
        姓名：刘备 年龄：35 身高：175
        姓名：关羽 年龄：35 身高：200
        姓名：孙权 年龄：40 身高：170
        姓名：曹操 年龄：45 身高：180
    */

    return 0;
}
```

总结：

* 对于自定义数据类型，必须要指定排序规则，否则编译器不知道如何进行排序
* 高级排序只是在排序规则上再进行一次逻辑规则制定，并不复杂

---
