# 数据类型

C++ 规定在创建一个变量或者常量时，必须要指定出相应的数据类型，否则无法给变量分配合适的内存(空间)

---

## 整型

**作用**：整型变量表示的是 **整数类型** 的数据

C++ 中能够表示整型的类型有以下几种方式，**区别在于所占内存空间不同**

| 数据类型 | 占用空间 | 取值范围 |
|:----:|:----:|:----:|
| short(短整型) | 2 字节| $-2^{15}$ 到 $2^{15}-1$ |
| int(整型) | 4 字节 | $-2^{31}$ 到 $2^{31}-1$ |
| long(长整形) | Windows(x64) 为 4 字节，Linux(x86) 为 4 字节，(x64)为 8 字节 | $-2^{31}$ 到 $2^{31}-1$ |
| long long(长长整形) | 8 字节 | $-2^{63}$ 到 $2^{63}-1$ |

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    // 短整型 [-32768, 32767]
    short num1 = 10;
    short num11 = 32768;

    // 整型
    int num2 = 10;

    // 长整型
    long num3 = 10;

    // 长长整型
    long long num4 = 10;

    cout << "num1 = " << num1 << endl;
    cout << "num11 = " << num11 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num3 = " << num3 << endl;
    cout << "num4 = " << num4 << endl;

    /*
        num1 = 10
        num11 = -32768
        num2 = 10
        num3 = 10
        num4 = 10
    */

    return 0;
}
```

---

## sizeof 关键字

**作用**：利用 `sizeof` 关键字可以 **统计数据类型所占内存大小**

**语法**：`sizeof`(数据类型/变量)

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    cout << "short 类型所占内存空间为： " << sizeof(short) << endl;
    cout << "int 类型所占内存空间为： " << sizeof(int) << endl;
    cout << "long 类型所占内存空间为： " << sizeof(long) << endl;
    cout << "long long 类型所占内存空间为： " << sizeof(long long) << endl;

    /*
        short 类型所占内存空间为： 2
        int 类型所占内存空间为： 4
        long 类型所占内存空间为： 8
        long long 类型所占内存空间为： 8
    */

    return 0;
}
```

> 整型结论：short < int <=(Windows) long <=(Linux) long long

---

## 实型(浮点型)

**作用**：用于 **表示小数**

浮点型变量分为两种：

* 单精度 `float` 
* 双精度 `double`

两者的 **区别** 在于表示的有效数字范围不同

| 数据类型 | 占用空间 | 有效数字范围 |
|:----:|:----:|:----:|
| float | 4 字节 | 7 位有效数字 |
| double | 8 字节 | 15～16 位有效数字 |

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    // 不加 f，编译器默认为 double，会进行类型转换，损失精度
    float f1 = 3.14f;
    double d1 = 3.14;

    cout << "f1 = " << f1 << endl;
    cout << "d1 = " << d1 << endl;

    f1 = 3.1415926f;
    d1 = 3.1415926;

    // 默认显示 6 位有效数字
    cout << "f1 = " << f1 << endl;
    cout << "d1 = " << d1 << endl;

    cout << "float  sizeof = " << sizeof(f1) << endl;
    cout << "double sizeof = " << sizeof(d1) << endl;

    // 科学计数法
    float f2 = 3e2; // 3 * 10 ^ 2
    cout << "f2 = " << f2 << endl;

    float f3 = 3e-2; // 3 * 0.1 ^ 2
    cout << "f3 = " << f3 << endl;

    /*
        f1 = 3.14
        d1 = 3.14
        f1 = 3.14159
        d1 = 3.14159
        float  sizeof = 4
        double sizeof = 8
        f2 = 300
        f3 = 0.03
    */

    return 0;
}
```

---

## 字符型

**作用**：字符型变量用于显示单个字符

**语法**：

```cpp
char ch = 'a';
```

> 注意 1：在显示字符型变量时，用单引号将字符括起来，不要用双引号

> 注意 2：单引号内只能有一个字符，不可以是字符串

* C 和 C++ 中字符型变量只占用 **1 个字节**
* 字符型变量并不是把字符本身放到内存中存储，而是将对应的 ASCII 编码放入到存储单元

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    char ch = 'a';
    cout << ch << endl;
    cout << sizeof(char) << endl;

    // ch = "abcde"; // 错误，不可以用双引号
    // ch = 'abcde'; // 错误，单引号内只能引用一个字符

    cout << (int)ch << endl; // 查看字符 a 对应的 ASCII 码
    ch = 97;                 // 可以直接用 ASCII 给字符型变量赋值
    // a - 97，A - 65
    cout << ch << endl;

    /*
        a
        1
        97
        a
    */

    return 0;
}
```

ASCII 码表：

| ASCII 值 | 控制字符 | ASCII 值 | 字符 | ASCII 值 | 字符 | ASCII 值 | 字符 |
|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
| 0 | NUT | 32 | (space) | 64 | @ | 96 | 、|
| 1 | SOH | 33 | ! | 65 | A | 97 | a |
| 2 | STX | 34 | " | 66 | B | 98 | b |
| 3 | ETX | 35 | # | 67 | C | 99 | c |
| 4 | EOT | 36 | $ | 68 | D | 100 | d |
| 5 | ENQ | 37 | % | 69 | E | 101 | e |
| 6 | ACK | 38 | & | 70 | F | 102 | f |
| 7 | BEL | 39 | , | 71 | G | 103 | g |
| 8 | BS | 40 | ( | 72 | H | 104 | h |
| 9 | HT | 41 | ) | 73 | I | 105 | i |
| 10 | LF | 42 | * | 74 | J | 106 | j |
| 11 | VT | 43 | + | 75 | K | 107 | k |
| 12 | FF | 44 | , | 76 | L | 108 | l |
| 13 | CR | 45 | - | 77 | M | 109 | m |
| 14 | SO | 46 | . | 78 | N | 110 | n |
| 15 | SI | 47 | / | 79 | O | 111 | o |
| 16 | DLE | 48 | 0 | 80 | P | 112 | p |
| 17 | DCI | 49 | 1 | 81 | Q | 113 | q |
| 18 | DC2 | 50 | 2 | 82 | R | 114 | r |
| 19 | DC3 | 51 | 3 | 83 | S | 115 | s |
| 20 | DC4 | 52 | 4 | 84 | T | 116 | t |
| 21 | NAK | 53 | 5 | 85 | U | 117 | u |
| 22 | SYN | 54 | 6 | 86 | V | 118 | v |
| 23 | TB | 55 | 7  | 87 | W | 119 | w |
| 24 | CAN | 56 | 8 | 88 | X | 120 | x |
| 25 | EM | 57 | 9 | 89 | Y | 121 | y |
| 26 | SUB | 58 | : | 90 | Z | 122 | z |
| 27 | ESC | 59 | ; | 91 | [ | 123 | { |
| 28 | FS | 60 | < | 92 | / | 124 | \| |
| 29 | GS | 61 | = | 93 | ] | 125 | } |
| 30 | RS | 62 | > | 94 | ^ | 126 | ` |
| 31 | US | 63 | ? | 95 | _ | 127 | DEL |     |

ASCII 码大致由以下 **两部分组** 成：

* ASCII 非打印控制字符：ASCII 表上的数字 **0-31** 分配给了控制字符，用于控制像打印机等一些外围设备
* ASCII 打印字符：数字 **32-126** 分配给了能在键盘上找到的字符，当查看或打印文档时就会出现

---

## 转义字符

**作用**：用于表示一些 **不能显示出来的 ASCII 字符**

现阶段常用的转义字符有：

```
\n  \\  \t
```

| 转义字符 | 含义 | ASCII 码值(十进制) |
|:----:|:----:|:----:|
| `\a` | 警报 | 007 |
| `\b` | 退格(BS)，将当前位置移到前一列 | 008 |
| `\f` | 换页(FF)，将当前位置移到下页开头 | 012 |
| `\n` | 换行(LF)，将当前位置移到下一行开头 | 010 |
| `\r` | 回车(CR)，将当前位置移到本行开头 | 013 |
| `\t` | 水平制表(HT)，跳到下一个 TAB 位置 | 009 |
| `\v` | 垂直制表(VT) | 011 |
| `\\` | 代表一个反斜线字符 "\\" | 092 |
| `\'` | 代表一个单引号(撇号)字符 | 039 |
| `\"` | 代表一个双引号字符 | 034 |
| `\?` | 代表一个问号 | 063 |
| `\0` | 数字 0 | 000 |
| `\ddd` | 8 进制转义字符，d 范围 0~7 | 3 位 8 进制 |
| `\xhh` | 16 进制转义字符，h 范围 0~9，a~f，A~F | 3 位 16 进制 |

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    cout << "hello\\hello" << endl;
    cout << "hello\thello" << endl;
    cout << "hello\nhello"
         << endl;

    /*
        hello\hello
        hello   hello
        hello
        hello
    */

    return 0;
}
```

---

## 字符串型

**作用**：用于表示一串字符

两种风格

* **C 风格字符串**： `char 变量名[] = "字符串值"`

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    char str[] = "hello world";
    cout << str << endl;

    // hello world

    return 0;
}
```

> 注意：C 风格的字符串要用双引号括起来

* **C++ 风格字符串**：`string 变量名 = "字符串值"`

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    string str = "hello world";
    cout << str << endl;

    // hello world

    return 0;
}
```

> 注意：C++ 风格字符串，需要加入头文件 ```#include <string>```(新版本不需要增加也可以使用)

---

## 布尔类型 bool

**作用**：布尔数据类型代表真或假的值 

`bool` 类型只有两个值：

* `true`  --- 真(本质是 1)，非 0 就是真
* `false` --- 假(本质是 0)

`bool` 类型占 1 个字节

demo:

```C++
#include <iostream>

using namespace std;

int main()
{
    bool flag = true;
    cout << flag << endl; // 1

    flag = false;
    cout << flag << endl; // 0

    cout << "size of bool = " << sizeof(bool) << endl; // 1

    /*
        1
        0
        size of bool = 1
    */

    return 0;
}
```

---

## 数据的输入

**作用**：用于从键盘获取数据

**关键字**：`cin`

**语法**：

```cpp
cin >> 变量;
```

示例：

```cpp
#include <iostream>

using namespace std;

int main()
{
    // 整型输入
    int a = 0;
    cout << "请输入整型变量：" << endl;
    cin >> a;
    cout << a << endl;

    // 浮点型输入
    double d = 0;
    cout << "请输入浮点型变量：" << endl;
    cin >> d;
    cout << d << endl;

    // 字符型输入
    char ch = 0;
    cout << "请输入字符型变量：" << endl;
    cin >> ch;
    cout << ch << endl;

    // 字符串型输入
    string str;
    cout << "请输入字符串型变量：" << endl;
    cin >> str;
    cout << str << endl;

    // 布尔类型输入
    bool flag = true;
    cout << "请输入布尔型变量：" << endl;
    cin >> flag;
    cout << flag << endl;

    /*
        请输入整型变量：
        12
        12
        请输入浮点型变量：
        12.14
        12.14
        请输入字符型变量：
        c
        c
        请输入字符串型变量：
        wasd
        wasd
        请输入布尔型变量：
        0
        0
    */

    return EXIT_SUCCESS;
}
```

---
