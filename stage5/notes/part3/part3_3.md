# deque 容器

---

## deque 容器基本概念

**功能**：

* 双端数组，可以对头端进行插入删除操作

`deque` 与 `vector` 区别：

* `vector` 对于头部的插入删除效率低，数据量越大，效率越低
* `deque` 相对而言，对头部的插入删除速度回比 `vector` 快
* `vector` 访问元素时的速度会比 `deque` 快，这和两者内部实现有关

![](../../photos/part3/5_5.jpg)

`deque` 内部工作原理:

`deque` 内部有个 **中控器**，维护每段缓冲区中的内容，缓冲区中存放真实数据

中控器维护的是每个缓冲区的地址，使得使用 `deque` 时像一片连续的内存空间

![](../../photos/part3/5_6.jpg)

* `deque` 容器的迭代器也是支持随机访问的

---

## deque 构造函数

**功能描述**：

* `deque` 容器构造

**函数原型**：

* `deque<T> deqT;`  默认构造形式
* `deque(beg, end);`    构造函数将 `[beg, end)` 区间中的元素拷贝给本身
* `deque(n, elem);` 构造函数将 `n` 个 `elem` 拷贝给本身
* `deque(const deque &deq);`    拷贝构造函数

demo:

```cpp
#include <iostream>
#include <deque>

using namespace std;

void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// deque 构造
void test1()
{
    // 无参构造函数
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int> d2(d1.begin() + 1, d1.end() - 1);
    printDeque(d2);

    deque<int> d3(10, 100);
    printDeque(d3);

    deque<int> d4 = d3;
    printDeque(d4);
}

int main()
{
    test1();

    /*
        0 1 2 3 4 5 6 7 8 9
        1 2 3 4 5 6 7 8
        100 100 100 100 100 100 100 100 100 100
        100 100 100 100 100 100 100 100 100 100
    */

    return 0;
}
```

> 总结：`deque` 容器和 `vector` 容器的构造方式几乎一致，灵活使用即可

---

## deque 赋值操作

**功能描述**：

* 给 `deque` 容器进行赋值

**函数原型**：

* `deque& operator=(const deque &deq);` 重载等号操作符
* `assign(beg, end);`   将 `[beg, end)` 区间中的数据拷贝赋值给本身
* `assign(n, elem);`    将 `n` 个 `elem` 拷贝赋值给本身

demo:

```cpp
#include <iostream>
#include <deque>

using namespace std;

void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 赋值操作
void test1()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int> d2;
    d2 = d1;
    printDeque(d2);

    deque<int> d3;
    d3.assign(d1.begin() + 1, d1.end() - 1);
    printDeque(d3);

    deque<int> d4;
    d4.assign(10, 100);
    printDeque(d4);
}

int main()
{
    test1();

    /*
        0 1 2 3 4 5 6 7 8 9
        0 1 2 3 4 5 6 7 8 9
        1 2 3 4 5 6 7 8
        100 100 100 100 100 100 100 100 100 100
    */

    return 0;
}
```

> 总结：`deque` 赋值操作也与 `vector` 相同，需熟练掌握

---

## deque 大小操作

**功能描述**：

* 对 `deque` 容器的大小进行操作

**函数原型**：

* `deque.empty();`  判断容器是否为空
* `deque.size();`   返回容器中元素的个数
* `deque.resize(num);`  重新指定容器的长度为 `num`，若容器变长，则以默认值填充新位置；如果容器变短，则末尾超出容器长度的元素被删除
* `deque.resize(num, elem);`    重新指定容器的长度为 `num`，若容器变长，则以 `elem` 值填充新位置；如果容器变短，则末尾超出容器长度的元素被删除

demo:

```cpp
#include <iostream>
#include <deque>

using namespace std;

void printDeque(const deque<int> &d)
{
    for (auto it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 大小操作
void test1()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    // 判断容器是否为空
    if (d1.empty())
    {
        cout << "d1 为空!" << endl;
    }
    else
    {
        cout << "d1 不为空!" << endl;
        // 统计大小
        cout << "d1 的大小为：" << d1.size() << endl;
    }

    // 重新指定大小
    d1.resize(15, 1);
    printDeque(d1);

    d1.resize(5);
    printDeque(d1);
}

int main()
{
    test1();

    /*
        0 1 2 3 4 5 6 7 8 9
        d1 不为空!
        d1 的大小为：10
        0 1 2 3 4 5 6 7 8 9 1 1 1 1 1
        0 1 2 3 4
    */

    return 0;
}
```

总结：

* `deque` 没有容量的概念
* 判断是否为空 --- `empty`
* 返回元素个数 --- `size`
* 重新指定个数 --- `resize`

---

## deque 插入和删除

**功能描述**：

* 向 `deque` 容器中插入和删除数据

**函数原型**：

两端插入操作：

* `push_back(elem);`    在容器尾部添加一个数据
* `push_front(elem);`   在容器头部插入一个数据
* `pop_back();` 删除容器最后一个数据
* `pop_front();`    删除容器第一个数据

指定位置操作：

* `insert(pos,elem);`   在 `pos` 位置插入一个 `elem` 元素的拷贝，返回新数据的位置
* `insert(pos,n,elem);` 在 `pos` 位置插入 `n` 个 `elem` 数据，无返回值
* `insert(pos,beg,end);`    在 `pos` 位置插入 `[beg,end)` 区间的数据，无返回值
* `clear();`    清空容器的所有数据
* `erase(beg,end);` 删除 `[beg,end)` 区间的数据，返回下一个数据的位置
* `erase(pos);` 删除 `pos` 位置的数据，返回下一个数据的位置

demo:

```cpp
#include <iostream>
#include <deque>

using namespace std;

void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 两端操作
void test1()
{
    deque<int> d;
    // 尾插
    d.push_back(10);
    d.push_back(20);
    // 头插
    d.push_front(100);
    d.push_front(200);

    printDeque(d);

    // 尾删
    d.pop_back();
    // 头删
    d.pop_front();
    printDeque(d);
}

// 插入
void test2()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);
    printDeque(d);

    d.insert(d.begin(), 1000);
    printDeque(d);

    d.insert(d.begin(), 2, 10000);
    printDeque(d);

    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d.insert(d.begin() + 1, d2.begin(), d2.end());
    printDeque(d);
}

// 删除
void test3()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);
    printDeque(d);

    d.erase(d.begin());
    printDeque(d);

    d.erase(d.begin(), d.end() - 1);
    printDeque(d);

    d.clear();
    printDeque(d);
}

int main()
{
    test1();
    cout << "=========" << endl;
    test2();
    cout << "=========" << endl;
    test3();

    /*
        200 100 10 20
        100 10
        =========
        200 100 10 20
        1000 200 100 10 20
        10000 10000 1000 200 100 10 20
        10000 1 2 3 10000 1000 200 100 10 20
        =========
        200 100 10 20
        100 10 20
        20

    */

    return 0;
}
```

总结：

* 插入和删除提供的位置是迭代器
* 尾插 --- `push_back`
* 尾删 --- `pop_back`
* 头插 --- `push_front`
* 头删 --- `pop_front`

---

## deque 数据存取

**功能描述**：

* 对 `deque` 中的数据的存取操作

**函数原型**：

* `at(int idx);`    返回索引 `idx` 所指的数据
* `operator[];`    返回索引 `idx` 所指的数据
* `front();`    返回容器中第一个数据元素
* `back();` 返回容器中最后一个数据元素

demo:

```cpp
#include <iostream>
#include <deque>

using namespace std;

void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 数据存取
void test1()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);

    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < d.size(); i++)
    {
        cout << d.at(i) << " ";
    }
    cout << endl;

    cout << d[4] << endl; // 越界不会报错
    // cout << d.at(4) << endl;

    cout << "front: " << d.front() << endl;
    cout << "back: " << d.back() << endl;
}

int main()
{
    test1();

    /*
        200 100 10 20
        200 100 10 20
        0
        front: 200
        back: 20
    */

    return 0;
}
```

总结：

* 除了用迭代器获取 `deque` 容器中元素，`[]` 和 `at` 也可以，具体情况与 `string`，`vector` 一样
* `front` 返回容器第一个元素
* `back` 返回容器最后一个元素

---

## deque 排序

**功能描述**：

* 利用算法实现对 `deque` 容器进行排序

**算法**：

* `sort(iterator beg, iterator end)`    对 `beg` 和 `end` 区间内元素进行排序

demo:

```cpp
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test1()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);

    printDeque(d);
    sort(d.begin(), d.end());
    printDeque(d);
}

int main()
{
    test1();

    /*
        200 100 10 20
        10 20 100 200
    */

    return 0;
}
```

> 总结：`sort` 算法非常实用，使用时包含头文件 `algorithm` 即可

---
