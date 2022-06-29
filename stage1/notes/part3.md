# 运算符

**作用**：用于执行代码的运算

本章主要讲解以下几类运算符：

| 运算符类型 | 作用 |
|:----:|:----:|
| 算术运算符 | 用于处理四则运算 |
| 赋值运算符 | 用于将表达式的值赋给变量 |
| 比较运算符 | 用于表达式的比较，并返回一个真值或假值 |
| 逻辑运算符 | 用于根据表达式的值返回真值或假值 |

---

## 算术运算符

**作用**：用于处理四则运算 

算术运算符包括以下符号：

| 运算符 | 术语 | 示例 | 结果 |
|:----:|:----:|:----:|:----:|
| + | 正号 | +3 | 3 |
| - | 负号 | -3 | -3 |
| + | 加 | 10 + 5 | 15 |
| - | 减 | 10 - 5 | 5 |
| * | 乘 | 10 * 5 | 50 |
| / | 除 | 10 / 5 | 2 |
| % | 取模(取余) | 10 % 3 | 1 |
| ++ | 前置递增 | a = 2; b = ++a; | a = 3; b = 3; |
| ++ | 后置递增 | a = 2; b = a++; | a = 3; b = 2; |
| -- | 前置递减 | a = 2; b = --a; | a = 1; b = 1; |
| -- | 后置递减 | a = 2; b = a--; | a = 1; b = 2; |

demo1:

```cpp
#include <iostream>

using namespace std;

int main()
{
    // 加减乘除
    int a1 = 10;
    int b1 = 3;

    cout << a1 + b1 << endl;
    cout << a1 - b1 << endl;
    cout << a1 * b1 << endl;
    cout << a1 / b1 << endl; // 两个整数相除结果依然是整数
    cout << a1 / (double)b1 << endl;

    int a2 = 10;
    int b2 = 20;
    cout << a2 / b2 << endl;

    int a3 = 10;
    int b3 = 0;
    // cout << a3 / b3 << endl; // 报错，除数不可以为 0

    // 两个小数可以相除
    double d1 = 0.5;
    double d2 = 0.25;
    cout << d1 / d2 << endl;

    /*
        13
        7
        30
        3
        3.33333
        0
        2
    */

    return 0;
}
```

> 总结：在除法运算中，除数不能为 0

demo2:

```cpp
#include <iostream>

using namespace std;

int main()
{
    // 取模
    int a1 = 10;
    int b1 = 3;

    cout << 10 % 3 << endl;

    int a2 = 10;
    int b2 = 20;

    cout << a2 % b2 << endl;

    int a3 = 10;
    int b3 = 0;

    // cout << a3 % b3 << endl; // 取模运算时，除数也不能为 0

    // 两个小数不可以取模
    double d1 = 3.14;
    double d2 = 1.1;

    // cout << d1 % d2 << endl;

    /*
        1
        10
    */

    return 0;
}
```

> 总结：只有整型变量可以进行取模运算

demo3:

```cpp
#include <iostream>

using namespace std;

int main()
{
    // 递增

    // 后置递增
    int a = 10;
    a++;               // 等价于 a = a + 1
    cout << a << endl; // 11

    // 前置递增
    int b = 10;
    ++b;
    cout << b << endl; // 11

    // 区别

    // 前置递增先对变量进行 ++，再计算表达式
    int a2 = 10;
    int b2 = ++a2 * 10;
    cout << b2 << endl;

    // 后置递增先计算表达式，后对变量进行 ++
    int a3 = 10;
    int b3 = a3++ * 10;
    cout << b3 << endl;

    int num1 = 10;
    int num2 = 10;
    cout << num1++ * ++num2 << endl;
    cout << num1 << " " << num2 << endl;

    /*
        11
        11
        110
        100
        110
        11 11
    */

    return 0;
}
```

> 总结：前置递增先对变量进行 ++，再计算表达式，后置递增相反

---

## 赋值运算符

**作用**：用于将表达式的值赋给变量

赋值运算符包括以下几个符号：

| 运算符 | 术语 | 示例 | 结果 |
|:----:|:----:|:----:|:----:|
| = | 赋值 | a = 2; b = 3; | a = 2; b = 3; |
| += | 加等于 | a = 0; a += 2; | a = 2; |
| -= | 减等于 | a = 5; a -= 3; | a = 2; |
| *= | 乘等于 | a = 2; a *= 2; | a = 4; |
| /= | 除等于 | a = 4; a /= 2; | a = 2; |
| %= | 模等于 | a = 3; a %= 2; | a = 1; |

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{

    // 赋值运算符

    // =
    int a = 10;
    a = 100;
    cout << "a = " << a << endl;

    // +=
    a = 10;
    a += 2; // a = a + 2;
    cout << "a = " << a << endl;

    // -=
    a = 10;
    a -= 2; // a = a - 2
    cout << "a = " << a << endl;

    // *=
    a = 10;
    a *= 2; // a = a * 2
    cout << "a = " << a << endl;

    // /=
    a = 10;
    a /= 2; // a = a / 2;
    cout << "a = " << a << endl;

    // %=
    a = 10;
    a %= 2; // a = a % 2;
    cout << "a = " << a << endl;

    /*
        a = 100
        a = 12
        a = 8
        a = 20
        a = 5
        a = 0
    */

    return 0;
}
```

---

## 比较运算符

**作用**：用于表达式的比较，并返回一个真值或假值

比较运算符有以下符号：

| 运算符 | 术语 | 示例 | 结果 |
|:----:|:----:|:----:|:----:|
| == | 相等于 | 4 == 3 | 0 |
| != | 不等于 | 4 != 3 | 1 |
| < | 小于 | 4 < 3 | 0 |
| > | 大于 | 4 > 3 | 1 |
| <= | 小于等于 | 4 <= 3 | 0 |
| >= | 大于等于 | 4 >= 1 | 1 |

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{

    int a = 10;
    int b = 20;

    cout << (a == b) << endl; // 0
    cout << (a != b) << endl; // 1
    cout << (a > b) << endl;  // 0
    cout << (a < b) << endl;  // 1
    cout << (a >= b) << endl; // 0
    cout << (a <= b) << endl; // 1

    return 0;
}
```

> 注意：C 和 C++ 语言的比较运算中，“真” 用数字 “1” 来表示， “假” 用数字 “0” 来表示 

---

## 逻辑运算符

**作用**：用于根据表达式的值返回真值或假值

逻辑运算符有以下符号：

| 运算符 | 术语 | 示例 | 结果 |
|:----:|:----:|:----:|:----:|
| ! | 非 | !a | 如果 a 为假，则 !a 为真；如果 a 为真，则 !a 为假 |
| && | 与 | a && b | 如果 a 和 b 都为真，则结果为真，否则为假 |
| \|\| | 或 | a \|\| b | 如果 a 和 b 有一个为真，则结果为真，二者都为假时，结果为假 |

逻辑非，demo

```cpp
#include <iostream>

using namespace std;

int main()
{
    // 逻辑运算符  --- 非

    int a = 10;
    cout << !a << endl;  // 0
    cout << !!a << endl; // 1

    return 0;
}
```

> 总结： 真变假，假变真

逻辑与，demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    // 逻辑运算符  --- 与

    int a = 10;
    int b = 10;
    cout << (a && b) << endl; // 1

    a = 10;
    b = 0;
    cout << (a && b) << endl; // 0

    a = 0;
    b = 0;
    cout << (a && b) << endl; // 0

    return 0;
}
```

> 总结：逻辑与运算符总结：同真为真，其余为假

逻辑或，demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    // 逻辑运算符  --- 或

    int a = 10;
    int b = 10;
    cout << (a || b) << endl; // 1

    a = 10;
    b = 0;
    cout << (a || b) << endl; // 1

    a = 0;
    b = 0;
    cout << (a || b) << endl; // 0

    return 0;
}
```

> 逻辑或运算符总结：同假为假，其余为真

---