# 引用

---

## 引用的基本使用

**作用**：给变量起别名

**语法**： 

```cpp
数据类型 &别名 = 原名;
```

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int &b = a;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    b = 100;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    a = 1000;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    /*
        a = 10
        b = 10
        a = 100
        b = 100
        a = 1000
        b = 1000
    */

    return 0;
}
```

---

## 引用注意事项

注意:

* 引用必须初始化
* 引用在初始化后，不可以改变

```cpp
#include <iostream>

using namespace std;

int main()
{

    int a = 10;
    int b = 20;
    // int &c; // 错误，引用必须初始化
    int &c = a; // 一旦初始化后，就不可以更改
    // &c = b; // 表达式必须是可修改的左值
    c = b; // 这是赋值操作，不是更改引用

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    /*
        a = 20
        b = 20
        c = 20
    */

    return 0;
}
```

---

## 引用做函数参数

**作用**：函数传参时，可以利用引用的技术让形参修饰实参

**优点**：可以简化指针修改实参

demo:

```cpp
#include <iostream>

using namespace std;

// 值传递
void mySwap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 地址传递
void mySwap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 引用传递
void mySwap3(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10;
    int b = 20;

    mySwap1(a, b);
    cout << "a:" << a << " b:" << b << endl;

    mySwap2(&a, &b);
    cout << "a:" << a << " b:" << b << endl;

    mySwap3(a, b);
    cout << "a:" << a << " b:" << b << endl;

    /*
        a:10 b:20
        a:20 b:10
        a:10 b:20
    */

    return 0;
}
```

> 总结：通过引用参数产生的效果同按地址传递是一样的。引用的语法更清楚简单

---

## 引用做函数返回值

**作用**：引用是可以作为函数的返回值存在的

**注意**：不要返回局部变量引用

**用法**：函数调用作为左值

demo:

```cpp
#include <iostream>

using namespace std;

// 返回局部变量引用
// int &test01()
// {
//     // 局部变量，栈区
//     int a = 10;
//     return a;
// }

// 返回静态变量引用
int &test02()
{
    static int a = 20;
    return a;
}

int main()
{
    // 不能返回局部变量的引用
    // int &ref = test01();
    // cout << "ref = " << ref << endl;

    /*
        main.cpp: In function ‘int& test01()’:
        main.cpp:10:12: warning: reference to local variable ‘a’ returned [-Wreturn-local-addr]
            10 |     return a;
               |            ^
        main.cpp:9:9: note: declared here
             9 |     int a = 10;
               |         ^
        Segmentation fault
    */

    // 静态变量存放在全局区
    // 如果函数做左值，那么必须返回引用
    int &ref2 = test02();
    cout << "ref2 = " << ref2 << endl;

    test02() = 1000;

    cout << "ref2 = " << ref2 << endl;

    /*
        ref2 = 20
        ref2 = 1000
    */

    return 0;
}
```

---

## 引用的本质

**本质**：引用的本质在 c++ 内部实现是一个指针常量

demo:

```cpp
#include <iostream>

using namespace std;

// 发现是引用，转换为 int *const ref = &a;
void func(int &ref)
{
    // ref 是引用，转换为 *ref = 100
    ref = 100;
}

int main()
{
    int a = 10;
    int &ref = a; // 自动转换为 int *const ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
    ref = 20;     // 内部发现 ref 是引用，自动帮我们转换为: *ref = 20

    cout << "a:" << a << endl;
    cout << "ref:" << ref << endl;

    func(a);

    /*
        a:20
        ref:20
    */

    return 0;
}
```

> 结论：c++ 推荐用引用技术，因为语法方便，引用本质是指针常量，但是所有的指针操作编译器都帮我们做了

---

## 常量引用

**作用**：常量引用主要用来修饰形参，防止误操作

在函数形参列表中，可以加 `const` 修饰形参，防止形参改变实参

demo:

```cpp
#include <iostream>

using namespace std;

// 引用使用的场景，通常用来修饰形参
void showValue(const int &v)
{
    // v += 10;
    cout << v << endl;
}

int main()
{
    // int& ref = 10;  // 非常量引用的初始值必须为左值
    // 引用本身需要一个合法的内存空间，字面量 10 在常量区，因此这行错误
    // 加入 const 就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
    const int &ref = 10;

    // ref = 100;  // 加入 const 后不可以修改变量
    cout << ref << endl;

    // 函数中利用常量引用防止误操作修改实参
    int a = 10;
    showValue(a);

    /*
        10
        10
    */

    return 0;
}
```

---
