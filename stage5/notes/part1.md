# 模板

## 模板的概念

模板就是建立 **通用的模具**，大大 **提高复用性**

例如生活中的模板

一寸照片模板：

![](../photos/part1/5_1.png)

PPT 模板：

![](../photos/part1/5_2.png)

![](../photos/part1/5_3.png)

模板的特点：

* 模板不可以直接使用，它只是一个框架
* 模板的通用并不是万能的

本章节为模板，主要介绍函数模板和类模板，目录如下:

* [函数模板](./part1/part1_1.md)
* [类模板](./part1/part1_2.md)

---

## 类模板案例

**案例描述**:  

实现一个通用的数组类，要求如下：

* 可以对内置数据类型以及自定义数据类型的数据进行存储
* 将数组中的数据存储到堆区
* 构造函数中可以传入数组的容量
* 提供对应的拷贝构造函数以及 `operator=` 防止浅拷贝问题
* 提供尾插法和尾删法对数组中的数据进行增加和删除
* 可以通过下标的方式访问数组中的元素
* 可以获取数组中当前元素个数和数组的容量

demo:

`myArray.hpp`

```cpp
#pragma once
#include <iostream>

using namespace std;

template <class T>
class MyArray
{
private:
    // 指向一个堆空间，这个空间存储真正的数据
    T *address;
    // 容量
    int capacity;
    // 大小
    int size;

public:
    // 构造函数
    MyArray(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->address = new T[this->capacity];
    }

    // 拷贝构造
    MyArray(const MyArray &arr)
    {
        this->capacity = arr.capacity;
        this->size = arr.size;
        this->address = new T[this->capacity];
        for (int i = 0; i < this->size; i++)
        {
            // 如果 T 为对象，而且还包含指针，必须需要重载 = 操作符，因为这个等号不是构造而是赋值
            // 普通类型可以直接 = 但是指针类型需要深拷贝
            this->address[i] = arr.address[i];
        }
    }

    // 重载 = 操作符  防止浅拷贝问题
    MyArray &operator=(const MyArray &myarray)
    {

        if (this->address != NULL)
        {
            delete[] this->address;
            this->capacity = 0;
            this->size = 0;
        }

        this->capacity = myarray.capacity;
        this->size = myarray.size;
        this->address = new T[this->capacity];
        for (int i = 0; i < this->size; i++)
        {
            this->address[i] = myarray[i];
        }
        return *this;
    }

    // 重载 [] 操作符 arr[0]
    T &operator[](int index)
    {
        // 不考虑越界，用户自己去处理
        return this->address[index];
    }

    // 尾插法
    void push_back(const T &val)
    {
        if (this->capacity == this->size)
        {
            return;
        }
        this->address[this->size] = val;
        this->size++;
    }

    // 尾删法
    void pop_back()
    {
        if (this->size == 0)
        {
            return;
        }
        this->size--;
    }

    // 获取数组容量
    int getCapacity()
    {
        return this->capacity;
    }

    // 获取数组大小
    int getSize()
    {
        return this->size;
    }

    // 析构
    ~MyArray()
    {
        if (this->address != NULL)
        {
            delete[] this->address;
            this->address = NULL;
            this->capacity = 0;
            this->size = 0;
        }
    }
};
```

`main.cpp`

```cpp
#include <iostream>
#include "myArray.hpp"

using namespace std;

void printIntArray(MyArray<int> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 测试内置数据类型
void test1()
{
    MyArray<int> array1(10);
    for (int i = 0; i < 10; i++)
    {
        array1.push_back(i);
    }
    cout << "array1 打印输出：" << endl;
    printIntArray(array1);
    cout << "array1 的大小：" << array1.getSize() << endl;
    cout << "array1 的容量：" << array1.getCapacity() << endl;

    cout << "--------------------------" << endl;

    MyArray<int> array2(array1);
    array2.pop_back();
    cout << "array2 打印输出：" << endl;
    printIntArray(array2);
    cout << "array2 的大小：" << array2.getSize() << endl;
    cout << "array2 的容量：" << array2.getCapacity() << endl;
}

// 测试自定义数据类型
class Person
{
public:
    string name;
    int age;

public:
    Person()
    {
    }

    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};

void printPersonArray(MyArray<Person> &personArr)
{
    for (int i = 0; i < personArr.getSize(); i++)
    {
        cout << "姓名：" << personArr[i].name << " 年龄： " << personArr[i].age << endl;
    }
}

void test2()
{
    // 创建数组
    MyArray<Person> pArray(10);
    Person p1("Jar", 30);
    Person p2("Anna", 20);
    Person p3("Cory", 18);
    Person p4("Sam", 15);
    Person p5("Frank", 24);

    // 插入数据
    pArray.push_back(p1);
    pArray.push_back(p2);
    pArray.push_back(p3);
    pArray.push_back(p4);
    pArray.push_back(p5);

    printPersonArray(pArray);

    cout << "pArray 的大小：" << pArray.getSize() << endl;
    cout << "pArray 的容量：" << pArray.getCapacity() << endl;
}

int main()
{
    test1();
    cout << "======" << endl;
    test2();

    /*
        array1 打印输出：
        0 1 2 3 4 5 6 7 8 9
        array1 的大小：10
        array1 的容量：10
        --------------------------
        array2 打印输出：
        0 1 2 3 4 5 6 7 8
        array2 的大小：9
        array2 的容量：10
        ======
        姓名：Jar 年龄： 30
        姓名：Anna 年龄： 20
        姓名：Cory 年龄： 18
        姓名：Sam 年龄： 15
        姓名：Frank 年龄： 24
        pArray 的大小：5
        pArray 的容量：10
    */

    return 0;
}
```

> 能够利用所学知识点实现通用的数组

---
