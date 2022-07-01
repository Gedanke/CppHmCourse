# 结构体

---

## 结构体基本概念

结构体属于用户 **自定义的数据类型**，允许用户存储不同的数据类型

---

##  结构体定义和使用

**语法**：

```cpp
struct 结构体名 
{ 
    结构体成员列表 
};
```

通过结构体创建变量的方式有三种：

* `struct 结构体名 变量名`
* `struct 结构体名 变量名 = {成员 1 值, 成员 2 值, ...}`
* `定义结构体时顺便创建变量`

demo:

```cpp
#include <iostream>

using namespace std;

// 结构体定义
struct student
{
    // 成员列表
    string name; // 姓名
    int age;     // 年龄
    int score;   // 分数
} stu3;          // 结构体变量创建方式 3

int main()
{
    // 结构体变量创建方式 1
    struct student stu1; // struct 关键字可以省略

    stu1.name = "张三";
    stu1.age = 18;
    stu1.score = 100;

    cout << "姓名：" << stu1.name << " 年龄：" << stu1.age << " 分数：" << stu1.score << endl;

    // 结构体变量创建方式 2
    struct student stu2 = {"李四", 19, 60};

    cout << "姓名：" << stu2.name << " 年龄：" << stu2.age << " 分数：" << stu2.score << endl;

    stu3.name = "王五";
    stu3.age = 18;
    stu3.score = 80;

    cout << "姓名：" << stu3.name << " 年龄：" << stu3.age << " 分数：" << stu3.score << endl;

    /*
        姓名：张三 年龄：18 分数：100
        姓名：李四 年龄：19 分数：60
        姓名：王五 年龄：18 分数：80
    */

    return 0;
}
```

> 总结 1：定义结构体时的关键字是 `struct`，不可省略

> 总结 2：创建结构体变量时，关键字 `struct` 可以省略

> 总结 3：结构体变量利用操作符 `.` 访问成员

---

## 结构体数组

**作用**：将自定义的结构体放入到数组中方便维护

**语法**：

```cpp
struct 结构体名 数组名[元素个数] = {{}, {}, ... {}};
```

demo:

```cpp
#include <iostream>

using namespace std;

// 结构体定义
struct student
{
    // 成员列表
    string name; // 姓名
    int age;     // 年龄
    int score;   // 分数
};

int main()
{
    // 结构体数组
    struct student arr[3] = {{"张三", 18, 80}, {"李四", 19, 60}, {"王五", 20, 70}};

    for (int i = 0; i < 3; i++)
    {
        cout << "姓名：" << arr[i].name << " 年龄：" << arr[i].age << " 分数：" << arr[i].score << endl;
    }

    /*
        姓名：张三 年龄：18 分数：80
        姓名：李四 年龄：19 分数：60
        姓名：王五 年龄：20 分数：70
    */

    return 0;
}
```

---

## 结构体指针

**作用**：通过指针访问结构体中的成员

* 利用操作符 `->` 可以通过结构体指针访问结构体属性

demo:

```cpp
#include <iostream>

using namespace std;

// 结构体定义
struct student
{
    // 成员列表
    string name; // 姓名
    int age;     // 年龄
    int score;   // 分数
};

int main()
{
    struct student stu = {
        "张三",
        18,
        100,
    };
    struct student *p = &stu;

    p->score = 80; // 指针通过 -> 操作符可以访问成员
    cout << "姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;

    /*
        姓名：张三 年龄：18 分数：80
    */

    return 0;
}
```

> 总结：结构体指针可以通过 `->` 操作符来访问结构体中的成员

---

## 结构体嵌套结构体

**作用**：结构体中的成员可以是另一个结构体

**例如**：每个老师辅导一个学员，一个老师的结构体中，记录一个学生的结构体

demo:

```cpp
#include <iostream>

using namespace std;

// 学生结构体定义
struct student
{
    // 成员列表
    string name; // 姓名
    int age;     // 年龄
    int score;   // 分数
};

// 教师结构体定义
struct teacher
{
    // 成员列表
    int id;             // 职工编号
    string name;        // 教师姓名
    int age;            // 教师年龄
    struct student stu; // 子结构体 学生
};

int main()
{
    struct teacher t1;
    t1.id = 10000;
    t1.name = "老王";
    t1.age = 40;

    t1.stu.name = "张三";
    t1.stu.age = 18;
    t1.stu.score = 100;

    cout << "教师 职工编号： " << t1.id << " 姓名： " << t1.name << " 年龄： " << t1.age << endl;
    cout << "辅导学员 姓名： " << t1.stu.name << " 年龄：" << t1.stu.age << " 考试分数： " << t1.stu.score << endl;

    /*
        教师 职工编号： 10000 姓名： 老王 年龄： 40
        辅导学员 姓名： 张三 年龄：18 考试分数： 100
    */

    return 0;
}
```

> 总结：在结构体中可以定义另一个结构体作为成员，用来解决实际问题

---

## 结构体做函数参数 

**作用**：将结构体作为参数向函数中传递

传递方式有两种：
* 值传递
* 地址传递

demo:

```cpp
#include <iostream>

using namespace std;

// 学生结构体定义
struct student
{
    // 成员列表
    string name; // 姓名
    int age;     // 年龄
    int score;   // 分数
};

// 值传递
void printStudent(student stu)
{
    stu.age = 28;
    cout << "子函数中 姓名：" << stu.name << " 年龄： " << stu.age << " 分数：" << stu.score << endl;
}

// 地址传递
void printStudent2(student *stu)
{
    stu->age = 28;
    cout << "子函数中 姓名：" << stu->name << " 年龄： " << stu->age << " 分数：" << stu->score << endl;
}

int main()
{
    student stu = {"张三", 18, 100};
    // 值传递
    printStudent(stu);
    cout << "主函数中 姓名：" << stu.name << " 年龄： " << stu.age << " 分数：" << stu.score << endl;
    cout << endl;

    // 地址传递
    printStudent2(&stu);
    cout << "主函数中 姓名：" << stu.name << " 年龄： " << stu.age << " 分数：" << stu.score << endl;

    /*
        子函数中 姓名：张三 年龄： 28 分数：100
        主函数中 姓名：张三 年龄： 18 分数：100

        子函数中 姓名：张三 年龄： 28 分数：100
        主函数中 姓名：张三 年龄： 28 分数：100
    */

    return 0;
}
```

> 总结：如果不想修改主函数中的数据，用值传递(`.`)，反之用地址传递(`->`)

---

## 结构体中 const 使用场景

**作用**：用 `const` 来防止误操作

demo:

```cpp
#include <iostream>

using namespace std;

// 学生结构体定义
struct student
{
    // 成员列表
    string name; // 姓名
    int age;     // 年龄
    int score;   // 分数
};

// const 使用场景
void printStudent(const student *stu) // 加 const 防止函数体中的误操作
{
    // stu->age = 100; // 操作失败，因为加了 const 修饰
    cout << "姓名：" << stu->name << " 年龄：" << stu->age << " 分数：" << stu->score << endl;
}

int main()
{
    student stu = {"张三", 18, 100};
    printStudent(&stu);

    /*
        姓名：张三 年龄：18 分数：100
    */

    return 0;
}
```

`const` 修饰的结构体的成员不能发生改变。若成员变量是指针，指针的指向(地址)不能变，但指向的值可以发生变化

demo:

```cpp
#include <iostream>

using namespace std;

int num = 10;
int n = 14;

struct Demo
{
    int *p;
};

void fun(const Demo *d)
{
    // 表达式必须是可修改的左值
    // d->p = &n;
    num = 12;
}

void fun1(const Demo *d)
{
    *d->p = n;
}

int main()
{
    Demo d;
    d.p = &num;

    cout << d.p << endl;
    cout << &d.p << endl;
    cout << *d.p << endl;

    fun(&d);
    cout << "===" << endl;

    cout << d.p << endl;
    cout << &d.p << endl;
    cout << *d.p << endl;

    fun1(&d);
    cout << "===" << endl;

    cout << d.p << endl;
    cout << &d.p << endl;
    cout << *d.p << endl;

    /*
        0x5639dedab010
        0x7ffcc8104370
        10
        ===
        0x5639dedab010
        0x7ffcc8104370
        12
        ===
        0x5639dedab010
        0x7ffcc8104370
        14
    */

    return 0;
}
```

---

## 结构体案例

### 案例 1

**案例描述**：

学校正在做毕设项目，每名老师带领 5 个学生，总共有 3 名老师，需求如下

* 设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放 5 名学生的数组作为成员
* 学生的成员有姓名、考试分数，创建数组存放 3 名老师，通过函数给每个老师及所带的学生赋值
* 最终打印出老师数据以及老师所带的学生数据

demo:

```cpp
#include <iostream>

using namespace std;

struct Student
{
    string name;
    int score;
};

struct Teacher
{
    string name;
    Student sArray[5];
};

void allocateSpace(Teacher tArray[], int len)
{
    string tName = "教师";
    string sName = "学生";
    string nameSeed = "ABCDE";
    for (int i = 0; i < len; i++)
    {
        tArray[i].name = tName + nameSeed[i];
        for (int j = 0; j < 5; j++)
        {
            tArray[i].sArray[j].name = sName + nameSeed[j];
            tArray[i].sArray[j].score = rand() % 61 + 40;
        }
    }
}

void printTeachers(Teacher tArray[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << tArray[i].name << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "\t姓名：" << tArray[i].sArray[j].name << " 分数：" << tArray[i].sArray[j].score << endl;
        }
    }
}

int main()
{
    srand((unsigned int)time(NULL)); // 随机数种子 头文件 #include<ctime>

    Teacher tArray[3]; // 老师数组
    int len = sizeof(tArray) / sizeof(Teacher);
    allocateSpace(tArray, len); // 创建数据
    printTeachers(tArray, len); // 打印数据

    /*
        教师A
                姓名：学生A 分数：47
                姓名：学生B 分数：90
                姓名：学生C 分数：69
                姓名：学生D 分数：56
                姓名：学生E 分数：43
        教师B
                姓名：学生A 分数：88
                姓名：学生B 分数：40
                姓名：学生C 分数：55
                姓名：学生D 分数：57
                姓名：学生E 分数：84
        教师C
                姓名：学生A 分数：58
                姓名：学生B 分数：79
                姓名：学生C 分数：47
                姓名：学生D 分数：94
                姓名：学生E 分数：70
    */

    return 0;
}
```

---

### 案例 2

**案例描述**：

设计一个人物的结构体，包括成员姓名，年龄，性别；创建结构体数组，数组中存放 5 名人物

通过冒泡排序的算法，将数组中的人物按照年龄进行升序排序，最终打印排序后的结果

五名人物信息如下：

```cpp
{"刘备", 23, "男"},
{"关羽", 22, "男"},
{"张飞", 20, "男"},
{"赵云", 21, "男"},
{"貂蝉", 19, "女"},
```

demo:

```cpp
#include <iostream>

using namespace std;

// 英雄结构体
struct hero
{
    string name;
    int age;
    string sex;
};

// 冒泡排序
void bubbleSort(hero arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j].age > arr[j + 1].age)
            {
                hero temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 打印数组
void printHeros(hero arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "姓名： " << arr[i].name << " 性别： " << arr[i].sex << " 年龄： " << arr[i].age << endl;
    }
}

int main()
{
    struct hero arr[5] =
        {
            {"刘备", 23, "男"},
            {"关羽", 22, "男"},
            {"张飞", 20, "男"},
            {"赵云", 21, "男"},
            {"貂蝉", 19, "女"},
        };

    int len = sizeof(arr) / sizeof(hero); // 获取数组元素个数

    bubbleSort(arr, len); // 排序
    printHeros(arr, len); // 打印

    /*
        姓名： 貂蝉 性别： 女 年龄： 19
        姓名： 张飞 性别： 男 年龄： 20
        姓名： 赵云 性别： 男 年龄： 21
        姓名： 关羽 性别： 男 年龄： 22
        姓名： 刘备 性别： 男 年龄： 23
    */

    return 0;
}
```

---
