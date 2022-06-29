# 数组

---

##  概述

所谓数组，就是一个集合，里面存放了相同类型的数据元素

* **特点 1**：数组中的每个数据元素都是相同的数据类型
* **特点 2**：数组是由连续的内存位置组成的

![](../photos/part5/5_1.png)

---

## 一维数组

### 一维数组定义方式

一维数组定义的三种方式：

* 方式一

```cpp
数据类型 数组名[数组长度]; 
```

* 方式二

```cpp
数据类型 数组名[数组长度] = {值 1, 值 2, ...};
```

* 方式三

```cpp
数据类型 数组名[] = {值 1, 值 2, ...};
```

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    // 定义方式 1
    // 数据类型 数组名[元素个数];
    int score[10];

    // 利用下标赋值
    score[0] = 100;
    score[1] = 99;
    score[2] = 85;

    // 利用下标输出
    cout << score[0] << endl;
    cout << score[1] << endl;
    cout << score[2] << endl;

    // 定义方式 2
    // 数据类型 数组名[元素个数] = {值 1, 值 2, 值 3, ...};
    // 如果 {} 内不足 10 个数据，剩余数据用 0 补全
    int score2[10] = {100, 90, 80, 70, 60, 50, 40, 30};

    // 逐个输出
    // cout << score2[0] << endl;
    // cout << score2[1] << endl;

    // 一个一个输出太麻烦，因此可以利用循环进行输出
    for (int i = 0; i < 10; i++)
    {
        cout << score2[i] << endl;
    }

    // 定义方式 3
    // 数据类型 数组名[] = {值 1, 值 2, 值3, ...};
    int score3[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};

    for (int i = 0; i < 10; i++)
    {
        cout << score3[i] << endl;
    }

    /*
        100
        99
        85
        100
        90
        80
        70
        60
        50
        40
        30
        0
        0
        100
        90
        80
        70
        60
        50
        40
        30
        20
        10
    */

    return 0;
}
```

> 总结 1：数组名的命名规范与变量名命名规范一致，不要和变量重名

> 总结 2：数组中下标是从 0 开始索引

### 一维数组数组名

一维数组名称的 **用途**：

* 可以统计整个数组在内存中的长度
* 可以获取数组在内存中的首地址

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    // 数组名用途
    // 1、可以获取整个数组占用内存空间大小
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "整个数组所占内存空间为： " << sizeof(arr) << endl;
    cout << "每个元素所占内存空间为： " << sizeof(arr[0]) << endl;
    cout << "数组的元素个数为： " << sizeof(arr) / sizeof(arr[0]) << endl;

    // 2、可以通过数组名获取到数组首地址，用 (long long) 转成十进制地址
    cout << "数组首地址为： " << &arr << endl;
    cout << "数组中第一个元素地址为： " << &arr[0] << endl;
    cout << "数组中第二个元素地址为： " << &arr[1] << endl;

    // arr = 100; 错误，数组名是常量，因此不可以赋值

    /*
        整个数组所占内存空间为： 40
        每个元素所占内存空间为： 4
        数组的元素个数为： 10
        数组首地址为： 0x7ffe8773a460
        数组中第一个元素地址为： 0x7ffe8773a460
        数组中第二个元素地址为： 0x7ffe8773a464
    */

    return 0;
}
```

> 注意：数组名是常量，不可以赋值

> 总结 1：直接打印数组名(也可以加上 `&`)，可以查看数组所占内存的首地址

> 总结 2：对数组名进行 `sizeof`，可以获取整个数组占内存空间的大小

**练习案例 1**：五只小猪称体重

**案例描述**：

在一个数组中记录了五只小猪的体重，如：`int arr[5] = {300, 350, 200, 400, 250};`

找出并打印最重的小猪体重

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    int arr[5] = {300, 350, 200, 400, 250};
    int max_value = arr[0];

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }
    cout << "max = " << max_value << endl;

    /*
        max = 400
    */

    return 0;
}
```

**练习案例 2**：数组元素逆置

**案例描述**：请声明一个 5 个元素的数组，并且将元素逆置

(如原数组元素为：1, 3, 2, 5, 4，逆置后输出结果为：4, 5, 2, 3, 1)

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    int arr[5] = {1, 3, 2, 5, 4};
    int len = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < len / 2; i++)
    {
        swap(arr[i], arr[len - i - 1]);
    }
    cout << "After swap" << endl;

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    /*
        1 3 2 5 4
        After swap
        4 5 2 3 1
    */

    return 0;
}
```

### 冒泡排序

**作用**：最常用的排序算法，对数组内元素进行排序

* 比较相邻的元素。如果第一个比第二个大，就交换他们两个
* 对每一对相邻元素做同样的工作，执行完毕后，找到第一个最大值
* 重复以上的步骤，每次比较次数 -1，直到不需要比较

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    int arr[] = {4, 2, 8, 0, 5, 7, 1, 3, 9};
    int len = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    cout << "After sort" << endl;

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    /*
        4 2 8 0 5 7 1 3 9
        After sort
        0 1 2 3 4 5 7 8 9
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

int main()
{
    int arr[9] = {4, 2, 8, 0, 5, 7, 1, 3, 9};

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 9 - 1; i++)
    {
        for (int j = 0; j < 9 - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "After sort" << endl;

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    /*
        4 2 8 0 5 7 1 3 9
        After sort
        0 1 2 3 4 5 7 8 9
    */

    return 0;
}
```

---

## 二维数组

二维数组就是在一维数组上，多加一个维度

![](../photos/part5/5_3.png)

### 二维数组定义方式

二维数组定义的四种方式：

* `数据类型 数组名[行数][列数];`
* `数据类型 数组名[行数][列数] = {{数据 1, 数据 2}, {数据 3, 数据 4}};`
* `数据类型 数组名[行数][列数] = {数据 1, 数据 2, 数据 3, 数据 4};`
* `数据类型 数组名[][列数] = {数据 1, 数据 2, 数据 3, 数据 4};`

> 建议：以上 4 种定义方式，利用第二种更加直观，提高代码的可读性

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    // 方式 1
    // 数组类型 数组名 [行数][列数]
    int arr[2][3];
    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[0][2] = 3;
    arr[1][0] = 4;
    arr[1][1] = 5;
    arr[1][2] = 6;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // 方式 2
    // 数据类型 数组名[行数][列数] = {{数据 1, 数据 2}, {数据 3, 数据 4}};
    int arr2[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // 方式 3
    // 数据类型 数组名[行数][列数] = {数据 1, 数据 2, 数据 3, 数据 4};
    int arr3[2][3] = {1, 2, 3, 4, 5, 6};

    // 方式 4
    // 数据类型 数组名[][列数] = {数据 1, 数据 2, 数据 3, 数据 4};
    int arr4[][3] = {1, 2, 3, 4, 5, 6};

    /*
        1 2 3
        4 5 6
    */

    return 0;
}
```

> 总结：在定义二维数组时，如果初始化了数据，可以省略行数

### 二维数组数组名

* 查看二维数组所占内存空间
* 获取二维数组首地址

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{

    // 二维数组数组名
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

    cout << "二维数组大小：" << sizeof(arr) << endl;
    cout << "二维数组一行大小：" << sizeof(arr[0]) << endl;
    cout << "二维数组元素大小：" << sizeof(arr[0][0]) << endl;

    cout << "二维数组行数：" << sizeof(arr) / sizeof(arr[0]) << endl;
    cout << "二维数组列数：" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

    // 地址
    cout << "二维数组首地址：" << &arr << endl;
    cout << "二维数组第一行地址：" << &arr[0] << endl;
    cout << "二维数组第二行地址：" << &arr[1] << endl;

    cout << "二维数组第一个元素地址：" << &arr[0][0] << endl;
    cout << "二维数组第二个元素地址：" << &arr[0][1] << endl;

    /*
        二维数组大小：24
        二维数组一行大小：12
        二维数组元素大小：4
        二维数组行数：2
        二维数组列数：3
        二维数组首地址：0x7ffc900ef150
        二维数组第一行地址：0x7ffc900ef150
        二维数组第二行地址：0x7ffc900ef15c
        二维数组第一个元素地址：0x7ffc900ef150
        二维数组第二个元素地址：0x7ffc900ef154
    */

    return 0;
}
```

> 总结 1：二维数组名就是这个数组的首地址，多维数组的本质依然是一维数组，每个成员的地址是连续

> 总结 2：对二维数组名进行 `sizeof` 时，可以获取整个二维数组占用的内存空间大小，进而可以获得数组的行数列数

###  二维数组应用案例

**考试成绩统计：**

案例描述：有三名同学(张三，李四，王五)，在一次考试中的成绩分别如下表，**请分别输出三名同学的总成绩**

|  | 语文 | 数学 | 英语 |
|:----:|:----:|:----:|:----:|
| 张三 | 100 | 100 | 100 |
| 李四 | 90 | 50 | 100 |
| 王五 | 60 | 70 | 80 |

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{

    int scores[3][3] =
        {
            {100, 100, 100},
            {90, 50, 100},
            {60, 70, 80},
        };
    string names[3] = {"张三", "李四", "王五"};

    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += scores[i][j];
        }
        cout << names[i] << " 的分数是 " << sum << endl;
    }

    /*
        张三 的分数是 300
        李四 的分数是 240
        王五 的分数是 210
    */

    return 0;
}
```

---
