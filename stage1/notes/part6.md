# 函数

---

## 概述

**作用**：将一段经常使用的代码封装起来，减少重复代码

一个较大的程序，一般分为若干个程序块，每个模块实现特定的功能

---

## 函数的定义

函数的定义一般主要有 5 个步骤：

* 返回值类型 
* 函数名
* 参数表列
* 函数体语句 
* `return` 表达式

**语法**： 

```cpp
返回值类型 函数名 (参数列表)
{
       函数体语句;
       return 表达式;
}
```

如上所示

* 返回值类型：一个函数可以返回一个值。在函数定义中
* 函数名：给函数起个名称
* 参数列表：使用该函数时，传入的数据
* 函数体语句：花括号内的代码，函数内需要执行的语句
* `return` 表达式：和返回值类型挂钩，函数执行完后，返回相应的数据

**示例**：定义一个加法函数，实现两个数相加

demo:

```cpp
#include <iostream>

using namespace std;

int sum(int num1, int num2)
{
    int sum = num1 + num2;
    return sum;
}

int main()
{
    cout << sum(1, 2) << endl;
    // 3
    return 0;
}
```

---

## 函数的调用

**功能**：使用定义好的函数

**语法**：

```cpp 
函数名(参数)
```

**示例**：

demo:

```cpp
#include <iostream>

using namespace std;

// 函数定义
int add(int num1, int num2) // 定义中的 num1，num2 称为形式参数，简称形参
{
    int sum = num1 + num2;
    return sum;
}

int main()
{
    int a = 10;
    int b = 10;
    // 调用 add 函数
    int sum = add(a, b); // 调用时的 a，b 称为实际参数，简称实参
    cout << "sum = " << sum << endl;

    a = 100;
    b = 100;

    sum = add(a, b);
    cout << "sum = " << sum << endl;

    /*
        sum = 20
        sum = 200
    */

    return 0;
}
```

> 总结：函数定义里小括号内称为形参，函数调用时传入的参数称为实参

---

## 值传递

* 所谓值传递，就是函数调用时实参将数值传入给形参
* 值传递时，如果形参发生，并不会影响实参

demo:

```cpp
#include <iostream>

using namespace std;

void swap(int num1, int num2)
{
    cout << "交换前：" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "交换后：" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    // return ; // 当函数声明时候，不需要返回值，可以不写 return
}

int main()
{
    int a = 10;
    int b = 20;

    swap(a, b);

    cout << "main 中的 a = " << a << endl;
    cout << "main 中的 b = " << b << endl;

    /*
        交换前：
        num1 = 10
        num2 = 20
        交换后：
        num1 = 20
        num2 = 10
        main 中的 a = 10
        main 中的 b = 20
    */

    return 0;
}
```

> 总结：值传递时，形参是修饰不了实参的

---

## 函数的常见样式

常见的函数样式有 4 种

* 无参无返
* 有参无返
* 无参有返
* 有参有返

demo:

```cpp
#include <iostream>

using namespace std;

// 函数常见样式
// 1、无参无返
void test1()
{
    // void a = 10; // 无类型不可以创建变量，原因无法分配内存
    cout << "this is test1" << endl;
}

// 2、有参无返
void test2(int a)
{
    cout << "this is test2" << endl;
    cout << "a = " << a << endl;
}

// 3、无参有返
int test3()
{
    cout << "this is test3 " << endl;
    return 10;
}

// 4、有参有返
int test4(int a, int b)
{
    cout << "this is test4 " << endl;
    int sum = a + b;
    return sum;
}

int main()
{
    test1();
    test2(1);
    cout << test3() << endl;
    cout << test4(1, 2) << endl;

    /*
        this is test1
        this is test2
        a = 1
        this is test3
        10
        this is test4
        3
    */

    return 0;
}
```

---

##  函数的声明

**作用**：告诉编译器函数名称及如何调用函数。函数的实际主体可以单独定义

* 函数的**声明可以多次**，但是函数的**定义只能有一次**

demo:

```cpp
#include <iostream>

using namespace std;

// 声明可以多次，定义只能一次
// 声明
int max(int a, int b);
int max(int a, int b);

int main()
{
    int a = 100;
    int b = 200;

    cout << max(a, b) << endl;

    // 200

    return 0;
}

// 定义
int max(int a, int b)
{
    return a > b ? a : b;
}
```

---

## 函数的分文件编写

**作用**：让代码结构更加清晰

函数分文件编写一般有 4 个步骤

* 创建后缀名为 `.h` 的头文件  
* 创建后缀名为 `.cpp` 的源文件
* 在头文件中写函数的声明
* 在源文件中写函数的定义

demo:

```cpp
#include <iostream>

using namespace std;

// swap.h 文件

void swap(int a, int b);
```

```cpp
#include "swap.h"

// swap.cpp 文件

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}
```

```cpp
#include <iostream>
#include "swap.h"

using namespace std;

int main()
{
    int a = 100;
    int b = 200;
    swap(a, b);

    /*
        a = 200
        b = 100
    */

    return 0;
}
```

---
