# 函数模板

* C++ 另一种编程思想称为 **泛型编程**，主要利用的技术就是模板
* C++ 提供两种模板机制: **函数模板** 和 **类模板** 

---

## 函数模板语法

**函数模板作用**：

建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个 **虚拟的类型** 来代表

**语法**：

```cpp
template <typename T>
函数声明或定义
```

**解释**：

* `template` --- 声明创建模板
* `typename` --- 表面其后面的符号是一种数据类型，可以用 `class` 代替
* `T` --- 通用的数据类型，名称可以替换，通常为大写字母

demo:

```cpp
#include <iostream>

using namespace std;

// 交换整型函数
void swapInt(int &a, int &b);

// 交换浮点型函数
void swapDouble(double &a, double &b);

// 利用模板提供通用的交换函数
template <typename T>
void mySwap(T &a, T &b);

void test1();

void test2();

int main()
{
    test1();
    cout << "======" << endl;
    test2();

    /*
        a = 20
        b = 10
        a = 10
        b = 20
        a = 20
        b = 10
        ======
        a = 2.2
        b = 1.1
        a = 1.1
        b = 2.2
        a = 2.2
        b = 1.1
    */

    return 0;
}

template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapDouble(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

void test1()
{
    int a = 10;
    int b = 20;

    swapInt(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // 利用模板实现交换
    // 自动类型推导
    mySwap(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // 显示指定类型
    mySwap<int>(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

void test2()
{
    double a = 1.1;
    double b = 2.2;

    swapDouble(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // 利用模板实现交换
    // 自动类型推导
    mySwap(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // 显示指定类型
    mySwap<double>(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}
```

**总结**：

* 函数模板利用关键字 `template`
* 使用函数模板有两种方式：自动类型推导、显示指定类型
* 模板的目的是为了提高复用性，将类型参数化

---

## 函数模板注意事项

**注意事项**：

* 自动类型推导，必须推导出一致的数据类型 `T`，才可以使用
* 模板必须要确定出 `T` 的数据类型，才可以使用

demo:

```cpp
#include <iostream>

using namespace std;

// 利用模板提供通用的交换函数
template <class T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 自动类型推导，必须推导出一致的数据类型 T，才可以使用
void test1()
{
    int a = 10;
    int b = 20;
    char c = 'c';

    mySwap(a, b); // 正确，可以推导出一致的 T 类型
    // mySwap(a, c); // 错误，推导不出一致的 T 类型
    mySwap<int>(a, b);
}

// 模板必须要确定出 T 的数据类型，才可以使用
template <class T>
void func()
{
    cout << "func 调用" << endl;
}

void test2()
{
    // func(); // 错误，模板不能独立使用，必须确定出 T 的类型
    // func(1); // 没有与参数列表匹配的函数模板 "func" 实例
    func<int>(); // 利用显示指定类型的方式，给 T 一个类型，才可以使用该模板
}

int main()
{
    test1();
    test2();

    // func 调用

    return 0;
}
```

> 使用模板时必须确定出通用数据类型 T，并且能够推导出一致的类型

---

## 函数模板案例

**案例描述**：

* 利用函数模板封装一个排序的函数，可以对 **不同数据类型数组** 进行排序
* 排序规则从大到小，排序算法为 **选择排序**
* 分别利用 **char 数组** 和 **int 数组** 进行测试

demo:

```cpp
#include <iostream>

using namespace std;

// 交换的函数模板
template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T> // 也可以替换成 typename
// 利用选择排序，进行对数组从大到小的排序
void mySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i; // 最大数的下标
        for (int j = i + 1; j < len; j++)
        {
            if (arr[max] < arr[j])
            {
                max = j;
            }
        }
        if (max != i) // 如果最大数的下标不是 i，交换两者
        {
            mySwap(arr[max], arr[i]);
        }
    }
}

template <typename T>
void printArray(T arr[], int len)
{

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test1()
{
    // 测试 char 数组
    char charArr[] = "bdcfeagh";
    int num = sizeof(charArr) / sizeof(char);

    mySort(charArr, num);
    printArray(charArr, num);
}

void test2()
{
    // 测试 int 数组
    int intArr[] = {7, 5, 8, 1, 3, 9, 2, 4, 6};
    int num = sizeof(intArr) / sizeof(int);

    mySort(intArr, num);
    printArray(intArr, num);
}

int main()
{
    test1();
    test2();

    /*
        h g f e d c b a
        9 8 7 6 5 4 3 2 1
    */

    return 0;
}
```

> 总结：模板可以提高代码复用，需要熟练掌握

---

## 普通函数与函数模板的区别

普通函数与函数模板 **区别**：

* 普通函数调用时可以发生自动类型转换(隐式类型转换)
* 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
* 如果利用显示指定类型的方式，可以发生隐式类型转换

demo:

```cpp
#include <iostream>

using namespace std;

// 普通函数
int myAdd1(int a, int b)
{
    return a + b;
}

// 函数模板
template <class T>
T myAdd2(T a, T b)
{
    return a + b;
}

// 使用函数模板时，如果用自动类型推导，不会发生自动类型转换，即隐式类型转换
void test1()
{
    int a = 10;
    int b = 20;
    char c = 'c';

    cout << myAdd1(a, c) << endl; // 正确，将 char 类型的 'c' 隐式转换为 int 类型 'c' 对应 ASCII 码 99
    // myAdd2(a, c); // 报错，使用自动类型推导时，不会发生隐式类型转换
    cout << myAdd2<int>(a, c) << endl; // 正确，如果用显示指定类型，可以发生隐式类型转换
}

int main()
{
    test1();

    /*
        109
        109
    */

    return 0;
}
```

> 总结：建议使用显示指定类型的方式，调用函数模板，因为可以自己确定通用类型 `T`

---

## 普通函数与函数模板的调用规则

调用规则如下：

* 如果函数模板和普通函数都可以实现，优先调用普通函数
* 可以通过空模板参数列表来强制调用函数模板
* 函数模板也可以发生重载
* 如果函数模板可以产生更好的匹配，优先调用函数模板

demo:

```cpp
#include <iostream>

using namespace std;

// 普通函数与函数模板调用规则
void myPrint(int a, int b)
{
    cout << "调用的普通函数" << endl;
}

template <typename T>
void myPrint(T a, T b)
{
    cout << "调用的模板" << endl;
}

template <typename T>
void myPrint(T a, T b, T c)
{
    cout << "调用重载的模板" << endl;
}

void test1()
{
    // 如果函数模板和普通函数都可以实现，优先调用普通函数
    // 注意，如果告诉编译器普通函数是存在的，但只是声明没有实现，或者不在当前文件内实现，就会报错找不到

    /*
        /usr/bin/ld: /tmp/ccycDidk.o: in function `test1()':
        main.cpp:(.text+0x25): undefined reference to `myPrint(int, int)'
        collect2: error: ld returned 1 exit status
    */

    int a = 10;
    int b = 20;
    // 调用普通函数
    myPrint(a, b);

    // 可以通过空模板参数列表来强制调用函数模板
    // 调用函数模板
    myPrint<>(a, b);
    myPrint<int>(a, b);

    // 函数模板也可以发生重载
    int c = 30;
    // 调用重载的函数模板
    myPrint(a, b, c);

    // 如果函数模板可以产生更好的匹配，优先调用函数模板
    char c1 = 'a';
    char c2 = 'b';
    // 调用函数模板
    myPrint(c1, c2);
}

int main()
{
    test1();

    /*
        调用的普通函数
        调用的模板
        调用的模板
        调用重载的模板
        调用的模板
    */

    return 0;
}
```

> 总结：既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性

---

## 模板的局限性

**局限性**：

* 模板的通用性并不是万能的

例如:

```cpp
template <class T>
void f(T a, T b)
{
    a = b;
}
```

在上述代码中提供的赋值操作，如果传入的 `a` 和 `b` 是一个数组，就无法实现了

再如:

```cpp
template <class T>
void f(T a, T b)
{
    if (a > b)
    {
        ...
    }
}
```

在上述代码中，如果 `T` 的数据类型传入的是像 `Person` 这样的自定义数据类型，也无法正常运行

因此 C++ 为了解决这种问题，提供模板的重载，可以为这些 **特定的类型** 提供 **具体化的模板**

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
    }
};

// 普通函数模板
template <class T>
bool myCompare(T &a, T &b)
{
    return (a == b);
}

// 具体化，显示具体化的原型和定意思以 template<> 开头，并通过名称来指出类型
// 具体化优先于常规模板
template <>
bool myCompare(Person &p1, Person &p2)
{
    return (p1.name == p2.name && p1.age == p2.age);
}

void test1()
{
    int a = 10;
    int b = 20;
    // 内置数据类型可以直接使用通用的函数模板
    bool ret = myCompare(a, b);
    if (ret)
    {
        cout << "a == b " << endl;
    }
    else
    {
        cout << "a != b " << endl;
    }
}

void test2()
{
    Person p1("Tom", 10);
    Person p2("Tom", 10);
    // 自定义数据类型，不会调用普通的函数模板
    // 可以创建具体化的 Person 数据类型的模板，用于特殊处理这个类型
    bool ret = myCompare(p1, p2);
    if (ret)
    {
        cout << "p1 == p2 " << endl;
    }
    else
    {
        cout << "p1 != p2 " << endl;
    }
}

int main()
{
    test1();
    test2();

    /*
        a != b
        p1 == p2
    */

    return 0;
}
```

> 利用具体化的模板，可以解决自定义类型的通用化

> 学习模板并不是为了写模板，而是在 STL 能够运用系统提供的模板

---
