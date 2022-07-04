# 函数提高

---

### 函数默认参数

在 C++ 中，函数的形参列表中的形参是可以有默认值的

**语法**：

```cpp
返回值类型 函数名(参数类型 参数 = 默认值)
{

}
```

demo:

```cpp
#include <iostream>

using namespace std;

int func(int a, int b = 10, int c = 10)
{
    return a + b + c;
}

// 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
// 如果函数声明有默认值，函数实现的时候就不能有默认参数，声明与实现只能一个有默认参数
int func2(int a = 10, int b = 10);

int main()
{

    cout << "ret = " << func(100) << endl;
    cout << "ret = " << func(20, 20) << endl;
    cout << "ret = " << func(20, 20, 20) << endl;

    cout << "ret = " << func2() << endl;
    cout << "ret = " << func2(1) << endl;
    cout << "ret = " << func2(1, 1) << endl;

    /*
        ret = 120
        ret = 50
        ret = 60
        ret = 20
        ret = 11
        ret = 2
    */

    return 0;
}

int func2(int a, int b)
{
    return a + b;
}
```

---

## 函数占位参数

C++ 中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置

**语法**： 

```cpp
返回值类型 函数名(数据类型)
{

}
```

在现阶段函数的占位参数存在意义不大，但是后面的课程中会用到该技术

demo:

```cpp
#include <iostream>

using namespace std;

// 函数占位参数，占位参数也可以有默认参数
void func(int a, int)
{
    cout << "this is func" << endl;
}

int main()
{
    func(10, 10); // 占位参数必须填补

    // this is func

    return 0;
}
```

---

## 函数重载

###  函数重载概述

**作用**：函数名可以相同，提高复用性

函数重载满足条件:

* 同一个作用域下
* 函数名称相同
* 函数参数 **类型不同** 或者 **个数不同** 或者 **顺序不同**

**注意**: 函数的返回值不可以作为函数重载的条件

demo:

```cpp
#include <iostream>

using namespace std;

// 函数重载需要函数都在同一个作用域下
void func()
{
    cout << "func() 的调用！" << endl;
}
void func(int a)
{
    cout << "func(int a) 的调用！" << endl;
}
void func(double a)
{
    cout << "func(double a) 的调用！" << endl;
}
void func(int a, double b)
{
    cout << "func(int a, double b) 的调用！" << endl;
}
void func(double a, int b)
{
    cout << "func(double a, int b) 的调用！" << endl;
}

// 函数返回值不可以作为函数重载条件
// int func(double a, int b)
// {
// 	cout << "func(double a ,int b) 的调用！" << endl;
// }

int main()
{
    func();
    func(10);
    func(3.14);
    func(10, 3.14);
    func(3.14, 10);

    /*
        func() 的调用！
        func(int a) 的调用！
        func(double a) 的调用！
        func(int a, double b) 的调用！
        func(double a, int b) 的调用！
    */

    return 0;
}
```

### 函数重载注意事项

* 引用作为重载条件
* 函数重载碰到函数默认参数

demo:

```cpp
#include <iostream>

using namespace std;

// 函数重载注意事项
// 引用作为重载条件
void func(int &a)
{
    cout << "func(int &a) 调用 " << endl;
}

void func(const int &a)
{
    cout << "func(const int &a) 调用 " << endl;
}

void fun(const int &a)
{
    cout << "fun(const int &a) 调用 " << endl;
}

// 函数重载碰到函数默认参数
void func2(int a, int b = 10)
{
    cout << "func2(int a, int b = 10) 调用" << endl;
}

void func2(int a)
{
    cout << "func2(int a) 调用" << endl;
}

int main()
{
    int a = 10;
    func(a);  // 调用无 const。int& a = a，合法，可以修改 a；const int &a = a，合法，但是无法修改 a
    fun(a);   // 原则上既可以调用有 const 的，也可以调用无 const 的。如果存在有 const 与无 const 的函数重载时，a 只会调用无 const 的
    func(10); // 调用有 const。int& a = 10，不合法；const int &a = 10，合法，不可同时也不打算修改 a

    // func2(10); // func2，还有 2 个重载，有多个重载函数 "func2" 实例与参数列表匹配。碰到默认参数产生歧义，需要避免

    /*
        func(int &a) 调用
        fun(const int &a) 调用
        func(const int &a) 调用
    */

    return 0;
}
```

> 引用作为重载条件时，需要注意下上述代码中的注释

> 未发生重载时，`const` 变量只能调用 `const` 修饰形参的函数，而非 `const` 变量既可以调用非 `const` 修饰形参的函数，也可以调用 `const` 修饰过的函数

> 如果有了重载，`const` 变量只能调用 `const` 修饰形参的函数，非 `const` 变量只会调用非 `const` 修饰的函数，此时不存在二义性

---
