# vector 容器

---

## vector 基本概念

**功能**：

* `vector` 数据结构和 **数组非常相似**，也称为 **单端数组**

`vector` 与普通数组 **区别**：

* 不同之处在于数组是静态空间，而 `vector` 可以 **动态扩展**

**动态扩展**：

* 并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间

![](../../photos/part3/5_4.jpg)

* `vector` 容器的迭代器是支持随机访问的迭代器

---

## vector 构造函数

**功能描述**：

* 创建 `vector` 容器

**函数原型**：

* `vector<T> v;`    采用模板实现类实现，默认构造函数
* `vector(v.begin(), v.end());` 将 `v[begin(), end())` 区间中的元素拷贝给本身
* `vector(n, elem);`    构造函数将 `n` 个 `elem` 拷贝给本身
* `vector(const vector &vec);`  拷贝构造函数

demo:

```cpp
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test1()
{
    // 无参构造
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2(v1.begin(), v1.end() - 1);
    printVector(v2);

    vector<int> v3(10, 100);
    printVector(v3);

    vector<int> v4(v3);
    printVector(v4);
}

int main()
{
    test1();

    /*
        0 1 2 3 4 5 6 7 8 9
        0 1 2 3 4 5 6 7 8
        100 100 100 100 100 100 100 100 100 100
        100 100 100 100 100 100 100 100 100 100
    */

    return 0;
}
```

> 总结：`vector` 的多种构造方式没有可比性，灵活使用即可

---

## vector 赋值操作

**功能描述**：

* 给 `vector` 容器进行赋值

**函数原型**：

* `vector& operator=(const vector &vec);`   重载等号操作符
* `assign(beg, end);`   将 `[beg, end)` 区间中的数据拷贝赋值给本身
* `assign(n, elem);`    将 `n` 个 `elem` 拷贝赋值给本身

demo:

```cpp
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &v)
{

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 赋值操作
void test1()
{
    // 无参构造
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;
    v2 = v1;
    printVector(v2);

    vector<int> v3;
    v3.assign(v1.begin() + 1, v1.end() - 1);
    printVector(v3);

    vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);
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

> 总结：`vector` 赋值方式比较简单，使用 `operator=`，或者 `assign` 都可以

---

## vector 容量和大小

**功能描述**：

* 对 `vector` 容器的容量和大小操作

**函数原型**：

* `empty();`    判断容器是否为空
* `capacity();` 容器的容量
* `size();` 返回容器中元素的个数
* `resize(int num);`    重新指定容器的长度为 `num`，若容器变长，则以默认值填充新位置；如果容器变短，则末尾超出容器长度的元素被删除
* `resize(int num, elem);`  重新指定容器的长度为 `num`，若容器变长，则以 `elem` 值填充新位置；如果容器变短，则末尾超出容器长度的元素被删除

demo:

```cpp
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test1()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    if (v1.empty())
    {
        cout << "v1 为空" << endl;
    }
    else
    {
        cout << "v1 不为空" << endl;
        cout << "v1 的容量 = " << v1.capacity() << endl;
        cout << "v1 的大小 = " << v1.size() << endl;
    }

    // resize 重新指定大小，若指定的更大，默认用 0 填充新位置，可以利用重载版本替换默认填充
    v1.resize(15, 10);
    printVector(v1);

    // resize 重新指定大小，若指定的更小，超出部分元素被删除
    v1.resize(5);
    printVector(v1);
}

int main()
{
    test1();

    /*
        0 1 2 3 4 5 6 7 8 9
        v1 不为空
        v1 的容量 = 16
        v1 的大小 = 10
        0 1 2 3 4 5 6 7 8 9 10 10 10 10 10
        0 1 2 3 4
    */

    return 0;
}
```

总结：

* 判断是否为空 --- `empty`
* 返回元素个数 --- `size`
* 返回容器容量 --- `capacity`
* 重新指定大小 --- `resize`

---

## vector 插入和删除

**功能描述**：

* 对 `vector` 容器进行插入、删除操作

**函数原型**：

* `push_back(ele);` 尾部插入元素 `ele`
* `pop_back();` 删除最后一个元素
* `insert(const_iterator pos, ele);`    迭代器指向位置 `pos` 插入元素 `ele`
* `insert(const_iterator pos, int count,ele);`  迭代器指向位置 `pos` 插入 `count` 个元素 `ele`
* `erase(const_iterator pos);`  删除迭代器指向的元素
* `erase(const_iterator start, const_iterator end);`    删除迭代器从 `start` 到 `end` 之间的元素
* `clear();`    删除容器中所有元素

demo:

```cpp
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &v)
{

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 插入和删除
void test1()
{
    vector<int> v1;
    // 尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    printVector(v1);
    // 尾删
    v1.pop_back();
    printVector(v1);
    // 插入
    v1.insert(v1.begin(), 100);
    printVector(v1);

    v1.insert(v1.begin(), 2, 1000);
    printVector(v1);

    // 删除
    v1.erase(v1.begin());
    printVector(v1);

    // 部分清空
    v1.erase(v1.begin() + 1, v1.end() - 1);
    printVector(v1);

    // 清空
    v1.clear();
    printVector(v1);
}

int main()
{
    test1();

    /*
        10 20 30 40 50
        10 20 30 40
        100 10 20 30 40
        1000 1000 100 10 20 30 40
        1000 100 10 20 30 40
        1000 40

    */

    return 0;
}
```

总结：

* 尾插 --- `push_back`
* 尾删 --- `pop_back`
* 插入 --- `insert`(位置迭代器)
* 删除 --- `erase`(位置迭代器)
* 清空 --- `clear`

---

## vector 数据存取

**功能描述**：

* 对 `vector` 中的数据的存取操作

**函数原型**：

* `at(int idx);`    返回索引 `idx` 所指的数据
* `operator[];` 返回索引 `idx` 所指的数据
* `front();`    返回容器中第一个数据元素
* `back();` 返回容器中最后一个数据元素

demo:

```cpp
#include <iostream>
#include <vector>

using namespace std;

void test1()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << " ";
    }
    cout << endl;

    cout << v1.capacity() << endl;
    cout << v1[10] << endl;
    cout << v1[16] << endl; // 可以越界，也不会报错，但不要这样做
    // cout<<v1.at(10)<<endl; // std::out_of_range，越界

    cout << "v1 的第一个元素为：" << v1.front() << endl;
    cout << "v1 的最后一个元素为：" << v1.back() << endl;
}

int main()
{
    test1();

    /*
        0 1 2 3 4 5 6 7 8 9
        0 1 2 3 4 5 6 7 8 9
        16
        0
        0
        v1 的第一个元素为：0
        v1 的最后一个元素为：9
    */

    return 0;
}
```

总结：

* 除了用迭代器获取 `vector` 容器中元素，`[]` 和 `at` 也可以，和 `string` 类似，`[]` 可以越界访问，编译器也不会报错，但不要这样做，`at` 会进行边界检查，更加安全
* `front` 返回容器第一个元素
* `back` 返回容器最后一个元素

---

## vector 互换容器

**功能描述**：

* 实现两个容器内元素进行互换

**函数原型**：

* `swap(vec);`  将 `vec` 与本身的元素互换

demo:

```cpp
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test1()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;
    for (int i = 10; i > 0; i--)
    {
        v2.push_back(i);
    }
    printVector(v2);

    // 互换容器
    cout << "互换后" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

void test2()
{
    vector<int> v;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }

    cout << "v 的容量为：" << v.capacity() << endl;
    cout << "v 的大小为：" << v.size() << endl;

    v.resize(3);

    cout << "v 的容量为：" << v.capacity() << endl;
    cout << "v 的大小为：" << v.size() << endl;

    vector<int> vv(v);
    // 可以看出，拷贝构造是以 v 的实际大小进行初始化 vv 的大小和容量
    cout << "vv 的容量为：" << vv.capacity() << endl;
    cout << "vv 的大小为：" << vv.size() << endl;

    // 收缩内存
    vector<int>(v).swap(v); // 匿名对象

    cout << "v 的容量为：" << v.capacity() << endl;
    cout << "v 的大小为：" << v.size() << endl;
}

int main()
{
    test1();
    cout << "=========" << endl;
    test2();

    /*
        0 1 2 3 4 5 6 7 8 9
        10 9 8 7 6 5 4 3 2 1
        互换后
        10 9 8 7 6 5 4 3 2 1
        0 1 2 3 4 5 6 7 8 9
        =========
        v 的容量为：131072
        v 的大小为：100000
        v 的容量为：131072
        v 的大小为：3
        vv 的容量为：3
        vv 的大小为：3
        v 的容量为：3
        v 的大小为：3
    */

    return 0;
}
```

> 总结：`swap` 可以使两个容器互换，可以达到实用的收缩内存效果

---

## vector 预留空间

**功能描述**：

* 减少 `vector` 在动态扩展容量时的扩展次数

**函数原型**：

* `reserve(int len);`   容器预留 `len` 个元素长度，预留位置不初始化，元素不可访问

demo:

```cpp
#include <iostream>
#include <vector>

using namespace std;

void test1()
{
    vector<int> v;

    // 预留空间
    v.reserve(100000);

    int num = 0;
    int *p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }

    cout << "num: " << num << endl;
}

void test2()
{
    vector<int> v;

    // 不预留空间

    int num = 0;
    int *p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        // vector 每次扩容，数组的地址都会发生变化
        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }

    cout << "num: " << num << endl;
}

int main()
{
    test1();
    test2();

    /*
        num: 1
        num: 18
    */

    return 0;
}
```

> 总结：如果数据量较大，可以一开始利用 `reserve` 预留空间

---
