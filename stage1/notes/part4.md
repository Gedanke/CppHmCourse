# 程序流程结构

C/C++ 支持最基本的三种程序运行结构：顺序结构、选择结构、循环结构

* 顺序结构：程序按顺序执行，不发生跳转
* 选择结构：依据条件是否满足，有选择的执行相应功能
* 循环结构：依据条件是否满足，循环多次执行某段代码

---

## 选择结构

### if 语句

**作用**：执行满足条件的语句

`if` 语句的三种形式

* 单行格式 `if` 语句
* 多行格式 `if` 语句
* 多条件的 `if` 语句

单行格式 `if` 语句：

```cpp
if (条件)
{ 
    条件满足执行的语句 
}
```

![](../photos/part4/4_1.png)

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{

    // 选择结构-单行 if 语句
    // 输入一个分数，如果分数大于 600 分，视为考上好大学，并在屏幕上打印

    int score = 0;
    cout << "请输入一个分数：" << endl;
    cin >> score;

    cout << "您输入的分数为： " << score << endl;

    // if 语句
    // 注意事项，在 if 判断语句后面，不要加分号
    if (score > 600)
    {
        cout << "我考上了好大学！！！" << endl;
    }

    /*
        请输入一个分数：
        598
        您输入的分数为： 598

        请输入一个分数：
        601
        您输入的分数为： 601
        我考上了好大学！！！
    */

    return 0;
}
```

> 注意：`if` 条件表达式后不要加分号

多行格式 `if` 语句：
 
 ```cpp
if (条件)
{ 
    条件满足执行的语句 
} else 
{ 
    条件不满足执行的语句 
};
```

![](../photos/part4/4_2.png)

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{

    int score = 0;
    cout << "请输入考试分数：" << endl;
    cin >> score;

    if (score > 600)
    {
        cout << "我考上了好大学" << endl;
    }
    else
    {
        cout << "我未考上好大学" << endl;
    }

    /*
        请输入考试分数：
        589
        我未考上好大学
        请输入考试分数：
        602
        我考上了好大学
    */

    return 0;
}
```

多条件的 `if` 语句：

```cpp
if (条件 1)
{ 
    条件 1 满足执行的语句 
} else if (条件 2)
{
    条件 2 满足执行的语句
}... 
else
{
    都不满足执行的语句
}
```

![](../photos/part4/4_3.png)

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{

    int score = 0;
    cout << "请输入考试分数：" << endl;

    cin >> score;
    if (score > 600)
    {
        cout << "我考上了一本大学" << endl;
    }
    else if (score > 500)
    {
        cout << "我考上了二本大学" << endl;
    }
    else if (score > 400)
    {
        cout << "我考上了三本大学" << endl;
    }
    else
    {
        cout << "我未考上本科" << endl;
    }

    /*
        请输入考试分数：
        555
        我考上了二本大学
    */

    return 0;
}
```

**嵌套 if 语句**：在 `if` 语句中，可以嵌套使用 `if` 语句，达到更精确的条件判断

案例需求：

* 提示用户输入一个高考考试分数，根据分数做如下判断
* 分数如果大于 600 分视为考上一本，大于 500 分考上二本，大于 400 分考上三本，其余视为未考上本科
* 在一本分数中，如果大于 700 分，考入北大，大于 650 分，考入清华，大于 600 分考入人大

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    int score = 0;
    cout << "请输入考试分数：" << endl;

    cin >> score;
    if (score > 600)
    {
        cout << "我考上了一本大学" << endl;
        if (score > 700)
        {
            cout << "我考上了北大" << endl;
        }
        else if (score > 650)
        {
            cout << "我考上了清华" << endl;
        }
        else
        {
            cout << "我考上了人大" << endl;
        }
    }
    else if (score > 500)
    {
        cout << "我考上了二本大学" << endl;
    }
    else if (score > 400)
    {
        cout << "我考上了三本大学" << endl;
    }
    else
    {
        cout << "我未考上本科" << endl;
    }

    /*
        请输入考试分数：
        666
        我考上了一本大学
        我考上了清华
    */

    return 0;
}
```

**练习案例**：三只小猪称体重

有三只小猪 A B C，请分别输入三只小猪的体重，并且判断哪只小猪最重？

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a > b)
    {
        if (c > a)
        {
            cout << c << endl;
        }
        else
        {
            cout << a << endl;
        }
    }
    else
    {
        if (c > b)
        {
            cout << c << endl;
        }
        else
        {
            cout << b << endl;
        }
    }

    /*
        2 1 3
        3
    */

    return 0;
}
```

### 三目运算符

**作用**：通过三目运算符实现简单的判断

**语法**：

```cpp
表达式 1 ? 表达式 2 ：表达式 3
```

**解释**：

* 如果表达式 1 的值为真，执行表达式 2，并返回表达式 2 的结果
* 如果表达式 1 的值为假，执行表达式 3，并返回表达式 3 的结果

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int b = 20;
    int c = 0;

    c = (a > b ? a : b);
    cout << "c = " << c << endl;

    // C++ 中三目运算符返回的是变量，可以继续赋值

    (a > b ? a : b) = 100;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    /*
        c = 20
        a = 10
        b = 100
        c = 20
    */

    return 0;
}
```

> 总结：和 `if` 语句比较，三目运算符优点是短小整洁，缺点是如果用嵌套，结构不清晰

### switch 语句

**作用**：执行多条件分支语句

**语法**：

```cpp
switch (表达式)
{
    case 结果 1:
        执行语句;
        break;
	case 结果 2: 
        执行语句;
        break;
    ...
	default:
        执行语句;
        break;
}
```

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    // 请给电影评分
    // 10 ~ 9   经典
    // 8 ~ 7   非常好
    // 6 ~ 5   一般
    // 5 分以下 烂片

    int score = 0;
    cout << "请给电影打分" << endl;
    cin >> score;

    switch (score)
    {
    case 10:
    case 9:
        cout << "经典" << endl;
        break;
    case 8:
    case 7:
        cout << "非常好" << endl;
        break;
    case 6:
    case 5:
        cout << "一般" << endl;
        break;
    default:
        cout << "烂片" << endl;
        break;
    }

    /*
        请给电影打分
        7
        非常好
    */

    return 0;
}
```

> 注意 1：`switch` 语句中表达式类型只能是整型或者字符型

> 注意 2：`case` 里如果没有 `break`，那么程序会一直向下执行

> 总结：与 `if` 语句比，对于多条件判断时，`switch` 的结构清晰，执行效率高，缺点是 `switch` 不可以判断区间

---

## 循环结构

### while 循环语句

**作用**：满足循环条件，执行循环语句

**语法**：

```cpp
while (循环条件)
{
    循环语句
}
```

**解释**：只要循环条件的结果为真，就执行循环语句

![](../photos/part4/4_4.png)

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    int num = 0;
    while (num < 10)
    {
        cout << "num = " << num << endl;
        num++;
    }

    /*
        num = 0
        num = 1
        num = 2
        num = 3
        num = 4
        num = 5
        num = 6
        num = 7
        num = 8
        num = 9
    */

    return 0;
}
```

> 注意：在执行循环语句时候，程序必须提供跳出循环的出口，否则出现死循环

**while 循环练习案例**：猜数字

**案例描述**：系统随机生成一个 1 到 100 之间的数字，玩家进行猜测，如果猜错，提示玩家数字过大或过小，如果猜对恭喜玩家胜利，并且退出游戏。

![](../photos/part4/4_5.jpg)

demo:

```cpp
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    // 随机种子
    srand((unsigned)time(NULL));
    // [0, 100] 的随机数
    int res = (rand() % (100 - 1 + 1)) + 1;
    cout << "res = " << res << endl;

    int c = -1;
    while (c != res)
    {
        cout << "输入你的答案:" << endl;
        cin >> c;
        if (c > res)
        {
            cout << "你的答案过大" << endl;
        }
        else if (c < res)
        {
            cout << "你的答案过小" << endl;
        }
        else
        {
            cout << "你的答案正确" << endl;
        }
    }

    /*
        res = 43
        输入你的答案:
        50
        你的答案过大
        输入你的答案:
        25
        你的答案过小
        输入你的答案:
        37
        你的答案过小
        输入你的答案:
        42
        你的答案过小
        输入你的答案:
        47
        你的答案过大
        输入你的答案:
        45
        你的答案过大
        输入你的答案:
        44
        你的答案过大
        输入你的答案:
        43
        你的答案正确
    */

    return 0;
}
```

### do...while 循环语句

**作用**：满足循环条件，执行循环语句

**语法**：

```cpp
do { 
    循环语句
} while (循环条件);
```

**注意**：与 `while` 的区别在于 `do...while` 会先执行一次循环语句，再判断循环条件

![](../photos/part4/4_6.png)

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    int num = 0;

    do
    {
        cout << num << endl;
        num++;

    } while (num < 10);

    /*
        0
        1
        2
        3
        4
        5
        6
        7
        8
        9
    */

    return 0;
}
```

**练习案例：水仙花数**

**案例描述**：水仙花数是指一个 3 位数，它的每个位上的数字的 3 次幂之和等于它本身

例如：$1^3 + 5^3+ 3^3 = 153$

请利用 `do...while` 语句，求出所有 3 位数中的水仙花数

```cpp
#include <iostream>

using namespace std;

bool fun(int n)
{
    int num = n;
    int num_ = n;
    int res = 0;
    while (num != 0)
    {
        res += (num % 10) * (num % 10) * (num % 10);
        num /= 10;
    }
    return num_ == res;
}

int main()
{
    int num = 100;
    do
    {
        if (fun(num))
        {
            cout << num << endl;
        }
        num++;
    } while (num < 1000);

    /*
        153
        370
        371
        407
    */

    return 0;
}
```

###  for 循环语句

**作用**：满足循环条件，执行循环语句

**语法**：

```cpp
for (起始表达式; 条件表达式; 末尾循环体) 
{ 
    循环语句; 
}
```

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cout << i << endl;
    }

    /*
        0
        1
        2
        3
        4
        5
        6
        7
        8
        9
    */

    return 0;
}
```

图示

![](../photos/part4/4_7.png)

> 注意：`for` 循环中的表达式，要用分号进行分隔

> 总结：`while , do...while, for` 都是开发中常用的循环语句，`for` 循环结构比较清晰，比较常用

**练习案例：敲桌子**

案例描述：从 1 开始数到数字 100， 如果数字个位含有 7，或者数字十位含有 7，或者该数字是 7 的倍数，我们打印敲桌子，其余数字直接打印输出。

```cpp
#include <iostream>

using namespace std;

int main()
{
    for (int i = 1; i <= 100; i++)
    {
        if (i % 10 == 7 || i / 10 == 7 || i % 7 == 0)
        {
            cout << "敲桌子"
                 << " ";
        }
        else
        {
            cout << i << " ";
        }
    }
    cout << endl;

    /*
        1 2 3 4 5 6 敲桌子 8 9 10 11 12 13 敲桌子 15 16 敲桌子 18 19 20 敲桌子 22 23 24 25 26 敲桌子 敲桌子 29 30 31 32 33 34 敲桌子 36 敲桌子 38 39 40 41 敲桌子 43 44 45 46 敲桌子 48 敲桌子 50 51 52 53 54 55 敲桌子 敲桌子 58 59 60 61 62 敲桌子 64 65 66 敲桌子 68 69 敲桌子 敲桌子 敲桌子 敲桌子 敲桌子 敲桌子 敲桌子 敲桌子 敲桌子 敲桌子 80 81 82 83 敲桌子 85 86 敲桌子 88 89 90 敲桌子 92 93 94 95 96 敲桌子 敲桌子 99 100
    */

    return 0;
}
```

### 嵌套循环

**作用**：在循环体中再嵌套一层循环，解决一些实际问题

例如想在屏幕中打印如下图片，就需要利用嵌套循环

![](../photos/part4/4_8.png)

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{

    // 外层循环执行 1 次，内层循环执行 1 轮
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << "*"
                 << " ";
        }
        cout << endl;
    }

    /*
     * * * * * * * * * *
     * * * * * * * * * *
     * * * * * * * * * *
     * * * * * * * * * *
     * * * * * * * * * *
     * * * * * * * * * *
     * * * * * * * * * *
     * * * * * * * * * *
     * * * * * * * * * *
     * * * * * * * * * *
     */

    return 0;
}
```

**练习案例**：乘法口诀表

案例描述：利用嵌套循环，实现九九乘法表

![](../photos/part4/4_9.jpg)

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " x " << i << " = " << i * j << "\t";
        }
        cout << endl;
    }

    /*
        1 x 1 = 1
        1 x 2 = 2       2 x 2 = 4
        1 x 3 = 3       2 x 3 = 6       3 x 3 = 9
        1 x 4 = 4       2 x 4 = 8       3 x 4 = 12      4 x 4 = 16
        1 x 5 = 5       2 x 5 = 10      3 x 5 = 15      4 x 5 = 20      5 x 5 = 25
        1 x 6 = 6       2 x 6 = 12      3 x 6 = 18      4 x 6 = 24      5 x 6 = 30      6 x 6 = 36
        1 x 7 = 7       2 x 7 = 14      3 x 7 = 21      4 x 7 = 28      5 x 7 = 35      6 x 7 = 42      7 x 7 = 49
        1 x 8 = 8       2 x 8 = 16      3 x 8 = 24      4 x 8 = 32      5 x 8 = 40      6 x 8 = 48      7 x 8 = 56      8 x 8 = 64
        1 x 9 = 9       2 x 9 = 18      3 x 9 = 27      4 x 9 = 36      5 x 9 = 45      6 x 9 = 54      7 x 9 = 63      8 x 9 = 72      9 x 9 = 81
    */

    return 0;
}
```

---

## 跳转语句

### break 语句

**作用**：用于跳出选择结构或者循环结构

`break` 使用的时机：

* 出现在 `switch` 条件语句中，作用是终止 `case` 并跳出 `switch`
* 出现在循环语句中，作用是跳出当前的循环语句
* 出现在嵌套循环中，跳出最近的内层循环语句

demo1:

```cpp
#include <iostream>

using namespace std;

int main()
{
    // 1、在 switch 语句中使用 break
    cout << "请选择您挑战副本的难度：" << endl;
    cout << "1、普通" << endl;
    cout << "2、中等" << endl;
    cout << "3、困难" << endl;

    int num = 0;
    cin >> num;

    switch (num)
    {
    case 1:
        cout << "您选择的是普通难度" << endl;
        break;
    case 2:
        cout << "您选择的是中等难度" << endl;
        break;
    case 3:
        cout << "您选择的是困难难度" << endl;
        break;
    }

    /*
        请选择您挑战副本的难度：
        1、普通
        2、中等
        3、困难
        2
        您选择的是中等难度
    */

    return 0;
}
```

demo2:

```cpp
#include <iostream>

using namespace std;

int main()
{
    // 2、在循环语句中用 break
    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            break; // 跳出循环语句
        }
        cout << i << endl;
    }

    /*
        0
        1
        2
        3
        4
    */

    return 0;
}
```

demo3:

```cpp
#include <iostream>

using namespace std;

int main()
{
    // 3、在嵌套循环语句中使用 break，退出内层循环
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 5)
            {
                break;
            }
            cout << "*"
                 << " ";
        }
        cout << endl;
    }

    /*
     * * * * *
     * * * * *
     * * * * *
     * * * * *
     * * * * *
     * * * * *
     * * * * *
     * * * * *
     * * * * *
     * * * * *
     */

    return 0;
}
```

### continue 语句

**作用**：在循环语句中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }
        cout << i << endl;
    }

    /*
        1
        3
        5
        7
        9
    */

    return 0;
}
```

> 注意：`continue` 并没有使整个循环终止，而 `break` 会跳出循环

### goto 语句

**作用**：可以无条件跳转语句

**语法**：

```cpp
goto 标记;
```

**解释**：如果标记的名称存在，执行到 `goto` 语句时，会跳转到标记的位置

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{

    cout << "1" << endl;

    goto FLAG;

    cout << "2" << endl;
    cout << "3" << endl;
    cout << "4" << endl;

FLAG:
{
    cout << "5" << endl;
    cout << "6" << endl;
}

    /*
        1
        5
        6
    */

    return 0;
}
```

> 注意：在程序中不建议使用 `goto` 语句，以免造成程序流程混乱

---
