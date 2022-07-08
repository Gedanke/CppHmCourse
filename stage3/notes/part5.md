# 文件操作

程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放

通过 **文件可以将数据持久化**

C++ 中对文件操作需要包含头文件 `<fstream>`

文件类型分为两种：

* **文本文件** - 文件以文本的 **ASCII 码** 形式存储在计算机中
* **二进制文件** - 文件以文本的 **二进制** 形式存储在计算机中，用户一般不能直接读懂它们

操作文件的三大类:

* `ofstream`：写操作
* `ifstream`：读操作
* `fstream`：读写操作

---

## 文本文件

### 写文件

写文件步骤如下：

* 包含头文件   

```cpp
#include <fstream>
```

* 创建流对象  

```cpp
ofstream ofs;
```

* 打开文件

```cpp
ofs.open("文件路径", 打开方式);
```

* 写数据

```cpp
ofs << "写入的数据";
```

* 关闭文件

```cpp
ofs.close();
```

* 文件打开方式：

|||
|:----:|:----:|
| 打开方式 | 解释 |
| `ios::in` | 为读文件而打开文件 |
| `ios::out` | 为写文件而打开文件 |
| `ios::ate` | 初始位置：文件尾 |
| `ios::app` | 追加方式写文件 |
| `ios::trunc` | 如果文件存在先删除，再创建 |
| `ios::binary` | 二进制方式 |

**注意**： 

文件打开方式可以配合使用，利用 `|` 操作符

**例如**：

用二进制方式写文件 `ios::binary | ios::out`

demo:

```cpp
#include <iostream>
#include <fstream>

using namespace std;

void test01()
{
    ofstream ofs;
    ofs.open("test.txt", ios::out);

    ofs << "姓名：张三" << endl;
    ofs << "性别：男" << endl;
    ofs << "年龄：18" << endl;

    ofs.close();
}

int main()
{
    test01();

    return 0;
}
```

总结：

* 文件操作必须包含头文件 `fstream`
* 读文件可以利用 `ofstream`，或者 `fstream` 类
* 打开文件时候需要指定操作文件的路径，以及打开方式
* 利用 `<<` 可以向文件中写数据
* 操作完毕，要关闭文件

### 读文件

读文件与写文件步骤相似，但是读取方式相对于比较多

读文件步骤如下：

* 包含头文件   

```cpp
#include <fstream>
```

* 创建流对象  

```cpp
ifstream ifs;
```

* 打开文件并判断文件是否打开成功

```cpp
ifs.open("文件路径", 打开方式);
```

* 读数据

```cpp
四种方式读取
```

* 关闭文件

```cpp
ifs.close();
```

demo:

```cpp
#include <iostream>
#include <fstream>

using namespace std;

void test1()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    // 第一种
    cout << "第一种" << endl;
    char buf[100] = {0};
    // char buf[5] = {0};
    // 字符数组的 size 要大，如果太小，则
    // *** stack smashing detected ***: terminated Aborted
    while (ifs >> buf)
    {
        cout << buf << endl;
    }

    ifs.close();
}

void test2()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    // 第二种
    cout << "第二种" << endl;
    char buf[1024] = {0};
    // char buf[10] = {0};
    // 字符数组的 size 要大，如果太小，则无法读出数据
    while (ifs.getline(buf, sizeof(buf)))
    {
        cout << buf << endl;
    }

    ifs.close();
}

void test3()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    cout << "第三种" << endl;
    // 第三种，由于不是字符数组，则没有第一二种情况
    string buf;
    while (getline(ifs, buf))
    {
        cout << buf << endl;
    }

    ifs.close();
}

void test4()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    cout << "第四种" << endl;
    // 第四种
    char c;
    while ((c = ifs.get()) != EOF)
    {
        cout << c;
    }

    ifs.close();
}

int main()
{
    test1();
    test2();
    test3();
    test4();

    /*
        第一种
        姓名：张三
        性别：男
        年龄：18
        第二种
        姓名：张三
        性别：男
        年龄：18
        第三种
        姓名：张三
        性别：男
        年龄：18
        第四种
        姓名：张三
        性别：男
        年龄：18
    */

    return 0;
}
```

总结：

- 读文件可以利用 `ifstream`，或者 `fstream` 类
- 利用 `is_open` 函数可以判断文件是否打开成功
- `close` 关闭文件 

---

## 二进制文件

以二进制的方式对文件进行读写操作

打开方式要指定为 `ios::binary`

### 写文件

二进制方式写文件主要利用流对象调用成员函数 `write`

函数原型：

```cpp
ostream& write(const char *buffer, int len);
````

参数解释：

字符指针 `buffer` 指向内存中一段存储空间，`len` 是读写的字节数

demo:

```cpp
#include <iostream>
#include <fstream>

using namespace std;

class Person
{
public:
    char name[64];
    int age;
};

class People
{
public:
    string name;
    int age;
};

// 二进制文件，写文件
void test1()
{
    // 包含头文件

    // 创建输出流对象
    ofstream ofs("person.txt", ios::out | ios::binary);

    // 打开文件
    // ofs.open("person.txt", ios::out | ios::binary);

    Person p = {"张三", 18};

    // 写文件
    ofs.write((const char *)&p, sizeof(p));

    // 关闭文件
    ofs.close();
}

// 二进制文件，写文件，此时不建议用 string 作为成员属性来进行二进制读写，会造成内存方面的问题
void test2()
{
    // 包含头文件

    // 创建输出流对象
    ofstream ofs("people.txt", ios::out | ios::binary);

    // 打开文件
    // ofs.open("person.txt", ios::out | ios::binary);

    Person p = {"张三", 18};

    // 写文件
    ofs.write((const char *)&p, sizeof(p));

    // 关闭文件
    ofs.close();
}

int main()
{
    test1();
    // test2();

    return 0;
}
```

总结：

* 文件输出流对象 可以通过 `write` 函数，以二进制方式写数据

### 读文件

二进制方式读文件主要利用流对象调用成员函数 `read`

函数原型：

```cpp
istream& read(char *buffer, int len);
```

参数解释：字符指针 `buffer` 指向内存中一段存储空间，`len` 是读写的字节数

demo:

```cpp
#include <iostream>
#include <fstream>

using namespace std;

class Person
{
public:
    char name[64];
    int age;
};

class People
{
public:
    string name;
    int age;
};

void test1()
{
    ifstream ifs("person.txt", ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
    }

    Person p;
    ifs.read((char *)&p, sizeof(p));

    cout << "姓名： " << p.name << " 年龄： " << p.age << endl;
}

void test2()
{
    // 使用 string 作为成员属性的类对象在进行二进制读写时，会发生内存错误
    ifstream ifs("people.txt", ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
    }

    People p;
    ifs.read((char *)&p, sizeof(p));

    cout << "姓名： " << p.name << " 年龄： " << p.age << endl;
}

int main()
{
    test1();
    cout << "======" << endl;
    test2();

    /*
        姓名： 张三 年龄： 18
        ======
        姓名：  年龄： 0
        Segmentation fault
    */

    return 0;
}
```

> 文件输入流对象可以通过 `read` 函数，以二进制方式读数据

类成员如果是 `string` 类型，不要使用二进制方式进行读写，因为 `string` 并没有像 `char[]` 那样实际存储了所有的字符数据，`string` 其大小固定为 32 字节

进行二进制读写时，写入的是一个指针，32 个字节，里面的内容不是 `string` 成员实际的字符数据；当该类的对象被销毁后，`string` 成员的地址已经被回收，再访问原有的地址就会造成内存错误，因此最好使用 `char[]`

---
