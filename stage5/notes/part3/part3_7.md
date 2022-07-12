# map 与 multimap 容器

---

## map 基本概念

**简介**：

* `map` 中所有元素都是 `pair`
* `pair` 中第一个元素为 `key`(键值)，起到索引作用，第二个元素为 `value`(实值)
* 所有元素都会根据元素的键值自动排序

**本质**：

* `map/multimap` 属于 **关联式容器**，底层结构是用二叉树实现

**优点**：

* 可以根据 `key` 值快速找到 `value` 值

`map` 和 `multimap` **区别**：

* `map` 不允许容器中有重复 `key` 值元素
* `multimap` 允许容器中有重复 `key` 值元素

---

## map 构造和赋值

**功能描述**：

* 对 `map` 容器进行构造和赋值操作

**函数原型**：

**构造**：

* `map<T1, T2> mp;` `map` 默认构造函数
* `map(const map &mp);` 拷贝构造函数

**赋值**：

* `map& operator=(const map &mp);`  重载等号操作符

demo:

```cpp
#include <iostream>
#include <map>

using namespace std;

void printMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
}

void test1()
{
    // 默认构造
    map<int, int> m{{1, 10}, {2, 20}};
    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(3, 30));
    printMap(m);

    // 拷贝构造
    map<int, int> m2(m);
    printMap(m2);

    map<int, int> m3;
    // 赋值
    m3 = m2;
    printMap(m3);
}

int main()
{
    test1();

    /*
        key = 1 value = 10
        key = 2 value = 20
        key = 3 value = 30
        key = 4 value = 40
        key = 1 value = 10
        key = 2 value = 20
        key = 3 value = 30
        key = 4 value = 40
        key = 1 value = 10
        key = 2 value = 20
        key = 3 value = 30
        key = 4 value = 40
    */

    return 0;
}
```

> 总结：`map` 中所有元素都是成对出现，插入数据时候要使用对组

---

## map 大小和交换

**功能描述**：

* 统计 `map` 容器大小以及交换 `map` 容器

**函数原型**：

- `size();` 返回容器中元素的数目
- `empty();`    判断容器是否为空
- `swap(st);`   交换两个集合容器

demo:

```cpp
#include <iostream>
#include <map>

using namespace std;

void printMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
}

void test1()
{
    map<int, int> m{{0, 0}};
    m[4] = 40;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    if (m.empty())
    {
        cout << "m 为空" << endl;
    }
    else
    {
        cout << "m 不为空" << endl;
        cout << "m 的大小为：" << m.size() << endl;
    }
}

// 交换
void test2()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    map<int, int> m2;
    m2.insert(pair<int, int>(4, 100));
    m2.insert(pair<int, int>(5, 200));
    m2.insert(pair<int, int>(6, 300));

    cout << "交换前" << endl;
    printMap(m);
    printMap(m2);

    cout << "交换后" << endl;
    m.swap(m2);
    printMap(m);
    printMap(m2);
}

int main()
{
    test1();
    cout << "=========" << endl;
    test2();

    /*
        m 不为空
        m 的大小为：5
        =========
        交换前
        key = 1 value = 10
        key = 2 value = 20
        key = 3 value = 30
        key = 4 value = 100
        key = 5 value = 200
        key = 6 value = 300
        交换后
        key = 4 value = 100
        key = 5 value = 200
        key = 6 value = 300
        key = 1 value = 10
        key = 2 value = 20
        key = 3 value = 30
    */

    return 0;
}
```

总结：

* 统计大小 --- `size`
* 判断是否为空 --- `empty`
* 交换容器 --- `swap`

---

## map 插入和删除

**功能描述**：

* `map` 容器进行插入数据和删除数据

**函数原型**：

* `insert(elem);`   在容器中插入元素
* `clear();`    清除所有元素
* `erase(pos);` 删除 `pos` 迭代器所指的元素，返回下一个元素的迭代器
* `erase(beg, end);`删除区间 `[beg, end)` 的所有元素，返回下一个元素的迭代器
* `erase(key);` 删除容器中值为 `key` 的元素

demo:

```cpp
#include <iostream>
#include <map>

using namespace std;

void printMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    cout << "=======" << endl;
}

void test1()
{
    // 插入
    map<int, int> m{{0, 0}};

    // 第一种插入方式
    m.insert(pair<int, int>(1, 10));

    // 第二种插入方式
    m.insert(make_pair(2, 20));

    // 第三种插入方式
    m.insert(map<int, int>::value_type(3, 30));

    // 第四种插入方式
    m[4] = 40;
    // cout << m[5] << endl; // [] 不建议插入，可以用 key 访问到 value
    cout << m[4] << endl;

    printMap(m);

    // 删除
    m.erase(m.begin());
    printMap(m);

    m.erase(3);
    printMap(m);

    m.erase(++m.begin(), --m.end());
    printMap(m);

    // 清空
    m.clear();
    printMap(m);
}

int main()
{
    test1();

    /*
        40
        key = 0 value = 0
        key = 1 value = 10
        key = 2 value = 20
        key = 3 value = 30
        key = 4 value = 40
        =======
        key = 1 value = 10
        key = 2 value = 20
        key = 3 value = 30
        key = 4 value = 40
        =======
        key = 1 value = 10
        key = 2 value = 20
        key = 4 value = 40
        =======
        key = 1 value = 10
        key = 4 value = 40
        =======
        =======
    */

    return 0;
}
```

`map` 插入方式很多，记住其一即可

* 插入 --- `insert`
* 删除 --- `erase`
* 清空 --- `clear`

---

## map 查找和统计

**功能描述**：

* 对 `map` 容器进行查找数据以及统计数据

**函数原型**：

* `find(key);`  查找 `key` 是否存在。若存在，返回该键的元素的迭代器；若不存在，返回 `set.end()`
* `count(key);` 统计 `key` 的元素个数

demo:

```cpp
#include <iostream>
#include <map>

using namespace std;

// 查找和统计
void test1()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    // 查找
    map<int, int>::iterator pos = m.find(3);

    if (pos != m.end())
    {
        cout << "找到了元素 key = " << (*pos).first << "; value = " << (*pos).second << endl;
    }
    else
    {
        cout << "未找到元素" << endl;
    }

    // 统计
    int num = m.count(3);
    cout << "num = " << num << endl;
}

int main()
{
    test1();

    /*
        找到了元素 key = 3; value = 30
        num = 1
    */

    return 0;
}
```

总结：

* 查找 --- `find`(返回的是迭代器）
* 统计 --- `count`(对于 `map`，结果为 0 或者 1)，`multimap` 结果为 0 或大于等于 1

---

## map 容器排序

**学习目标**：

* `map` 容器默认排序规则为，按照 `key` 值进行从小到大排序，掌握如何改变排序规则

**主要技术点**:

* 利用仿函数，可以改变排序规则

demo:

```cpp
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

// 按 key
bool compareKey(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return p1.first > p2.first;
}

// 按 value
bool compareValue(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return p1.second > p2.second;
}

void test1()
{
    // 默认从小到大排序
    // 利用仿函数实现从大到小排序
    map<int, int, MyCompare> m;

    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));
    m.insert(make_pair(4, 40));
    m.insert(make_pair(5, 50));

    for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key: " << it->first << " value: " << it->second << endl;
    }

    cout << "=========" << endl;

    cout << "对现有的 map 进行按 key 或者 value 排序" << endl;

    map<int, int> mine{{1, 50}, {2, 40}, {3, 30}, {4, 20}, {5, 10}};
    vector<pair<int, int>> v(mine.begin(), mine.end());

    sort(v.begin(), v.end(), compareKey);
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << "key: " << it->first << " value: " << it->second << endl;
    }

    cout << "=========" << endl;

    sort(v.begin(), v.end(), compareValue);

    map<int, int> mm(v.begin(), v.end());
    for (auto it = mm.begin(); it != mm.end(); it++)
    {
        cout << "key: " << it->first << " value: " << it->second << endl;
    }
}

int main()
{
    test1();

    /*
        key: 5 value: 50
        key: 4 value: 40
        key: 3 value: 30
        key: 2 value: 20
        key: 1 value: 10
        =========
        对现有的 map 进行按 key 或者 value 排序
        key: 5 value: 10
        key: 4 value: 20
        key: 3 value: 30
        key: 2 value: 40
        key: 1 value: 50
        =========
        key: 1 value: 50
        key: 2 value: 40
        key: 3 value: 30
        key: 4 value: 20
        key: 5 value: 10
    */

    return 0;
}
```

总结：

* 利用仿函数可以指定 `map` 容器的排序规则
* 对于自定义数据类型，`map` 必须要指定排序规则，同 `set` 容器

---
