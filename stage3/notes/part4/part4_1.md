# 封装

---

## 封装的意义

封装是 C++ 面向对象三大特性之一

封装的意义:

* 将属性和行为作为一个整体，表现生活中的事物
* 将属性和行为加以权限控制

**封装意义一**:

​在设计类的时候，属性和行为写在一起，表现事物

**语法**:
 
```cpp
class 类名
{   
访问权限:
    属性;

访问权限:
    行为;  
};
```

**示例 1**：设计一个圆类，求圆的周长

```cpp
#include <iostream>

using namespace std;

// 圆周率
const double PI = 3.14;

// 封装的意义
// 将属性和行为作为一个整体，用来表现生活中的事物

// 封装一个圆类，求圆的周长
// class 代表设计一个类，后面跟着的是类名

class Circle
{
    // 访问权限  公共的权限
public:
    // 属性
    // 半径
    int m_r;

    // 行为
    // 获取到圆的周长
    double calculateZC()
    {
        // 2 * pi  * r
        // 获取圆的周长
        return 2 * PI * m_r;
    }
};

int main()
{
    // 通过圆类，创建圆的对象
    // c1 就是一个具体的圆，通过类创建一个对象，是实例化的过程
    Circle c1;
    c1.m_r = 10; // 给圆对象的半径进行赋值操作

    // 2 * pi * 10 = = 62.8
    cout << "圆的周长为： " << c1.calculateZC() << endl;

    /*
        圆的周长为： 62.8
    */

    return 0;
}
```

**示例 2**：设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号

```cpp
#include <iostream>

using namespace std;

// 学生类
class Student
{
public:
    void setName(string name)
    {
        m_name = name;
    }
    void setID(int id)
    {
        m_id = id;
    }

    void showStudent()
    {
        cout << "name: " << m_name << " ID: " << m_id << endl;
    }

public:
    string m_name;
    int m_id;
};

int main()
{
    Student stu;
    stu.setName("Jacker");
    stu.setID(25);
    stu.showStudent();

    /*
        name: Jacker ID: 25
    */

    return 0;
}
```

> 类中的属性和行为统一称为成员。属性也可称为成员属性，成员变量；学位也可称为成员函数，成员方法

**封装意义二**:

类在设计时，可以把属性和行为放在不同的权限下，加以控制

访问权限有三种:

* `public` 公共权限: 类内可以访问，子类可以访问，类外可以访问
* `protected` 保护权限: 类内可以访问，子类可以访问，类外不可以访问
* `private` 私有权限: 类内可以访问，子类不可以访问，类外不可以访问

demo:

```cpp
#include <iostream>

using namespace std;

// 三种权限
// 公共权限  public     类内可以访问  类外可以访问
// 保护权限  protected  类内可以访问  类外不可以访问
// 私有权限  private    类内可以访问  类外不可以访问

class Person
{
public:
    string m_Name; // 姓名  公共权限

protected:
    string m_Car; // 汽车  保护权限

private:
    int m_Password; // 银行卡密码  私有权限

public:
    void func()
    {
        m_Name = "张三";
        m_Car = "拖拉机";
        m_Password = 123456;
    }
};

int main()
{
    Person p;
    p.m_Name = "李四";
    // p.m_Car = "奔驰";  // 保护权限类外访问不到
    // p.m_Password = 123; // 私有权限类外访问不到

    return 0;
}
```

---

## struct 和 class 区别

在 C++ 中 `struct` 和 `class` 唯一的区别就在于 **默认的访问权限不同**

区别：

* `struct` 默认权限为公共
* `class` 默认权限为私有

demo:

```cpp
#include <iostream>

using namespace std;

class C1
{
    int m_A; // 默认是私有权限
};

struct C2
{
    int m_A; // 默认是公共权限
};

int main()
{
    C1 c1;
    // c1.m_A = 10; // 错误，访问权限是私有

    C2 c2;
    c2.m_A = 10; // 正确，访问权限是公共

    return 0;
}
```

---

## 成员属性设置为私有

成员属性为私有权限的优点有:

* **优点 1**：将所有成员属性设置为私有，可以自己控制读写权限
* **优点 2**：对于写权限，我们可以检测数据的有效性

demo:

```cpp
#include <iostream>

using namespace std;

class Person
{
private:
    string m_Name;  // 可读可写  姓名
    int m_Age;      // 只读  年龄
    string m_Lover; // 只写  爱人

public:
    // 姓名设置可读可写
    void setName(string name)
    {
        m_Name = name;
    }
    string getName()
    {
        return m_Name;
    }

    // 获取年龄
    int getAge()
    {
        return m_Age;
    }

    // 设置年龄
    void setAge(int age)
    {
        if (age < 0 || age > 150)
        {
            cout << "你个老妖精!" << endl;
            return;
        }
        m_Age = age;
    }

    // 爱人设置为只写
    void setLover(string lover)
    {
        m_Lover = lover;
    }
};

int main()
{
    Person p;
    // 姓名设置
    p.setName("张三");
    cout << "姓名： " << p.getName() << endl;

    // 年龄设置
    p.setAge(50);
    cout << "年龄： " << p.getAge() << endl;

    // 爱人设置
    p.setLover("李四");
    // cout << "爱人： " << p.m_Lover << endl;  // 只写属性，不可以读取

    /*
        姓名： 张三
        年龄： 50
    */

    return 0;
}
```

**练习案例 1：设计立方体类**

设计立方体类(Cube)

* 求出立方体的面积和体积
* 分别用全局函数和成员函数判断两个立方体是否相等

![](../../photos/part4/4_1.png)

code:

```cpp
#include <iostream>

using namespace std;

class Cube
{
private:
    double a;
    double b;
    double c;

public:
    void init(double a_, double b_, double c_)
    {
        a = a_;
        b = b_;
        c = c_;
    }

    double getA()
    {
        return a;
    }

    double getB()
    {
        return b;
    }

    double getC()
    {
        return c;
    }

    double getArea()
    {
        return 2 * a * b + 2 * a * c + 2 * b * c;
    }
    double getVolume()
    {
        return a * b * c;
    }
    bool isEqual(Cube &cube)
    {
        return a == cube.getA() && b == cube.getB() && c == cube.getC();
    }
};

bool isEqualG(Cube &c1, Cube &c2)
{
    return c1.getA() == c2.getA() && c1.getB() == c2.getB() && c1.getC() == c2.getC();
}

int main()
{
    Cube c1, c2, c3;

    c1.init(1, 2, 3);
    c2.init(1, 2, 3);
    c3.init(1, 3, 4);

    cout << "c1 的表面积: " << c1.getArea() << endl;
    cout << "c1 的体积: " << c1.getVolume() << endl;

    cout << "c2 的表面积: " << c2.getArea() << endl;
    cout << "c2 的体积: " << c2.getVolume() << endl;

    cout << "c3 的表面积: " << c3.getArea() << endl;
    cout << "c3 的体积: " << c3.getVolume() << endl;

    cout << "c1 与 c2 是否相等: " << c1.isEqual(c2) << endl;
    cout << "c1 与 c2 是否相等: " << isEqualG(c1, c2) << endl;

    cout << "c1 与 c3 是否相等: " << c1.isEqual(c3) << endl;
    cout << "c1 与 c3 是否相等: " << isEqualG(c1, c3) << endl;

    /*
        c1 的表面积: 22
        c1 的体积: 6
        c2 的表面积: 22
        c2 的体积: 6
        c3 的表面积: 38
        c3 的体积: 12
        c1 与 c2 是否相等: 1
        c1 与 c2 是否相等: 1
        c1 与 c3 是否相等: 0
        c1 与 c3 是否相等: 0
    */

    return 0;
}
```

**练习案例 2：点和圆的关系**

设计一个圆形类(Circle)，和一个点类(Point)，计算点和圆的关系

![](../../photos/part4/4_2.png)

```cpp
#include <iostream>

using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    void init(int x_, int y_)
    {
        x = x_;
        y = y_;
    }
    void setX(int x_)
    {
        x = x_;
    }
    int getX()
    {
        return x;
    }
    void setY(int y_)
    {
        y = y_;
    }
    int getY()
    {
        return y;
    }
};

class Circle
{
private:
    Point p;
    int r;

public:
    void init(int x_, int y_, int r_)
    {
        p.setX(x_);
        p.setY(y_);
        r = r_;
    }
    void setR(int r_)
    {
        r = r_;
    }
    int getR()
    {
        return r;
    }
    void setP(int x_, int y_)
    {
        p.setX(x_);
        p.setY(y_);
    }
    Point getP()
    {
        return p;
    }
};

void fun(Circle c, Point p)
{
    int dis = (c.getP().getX() - p.getX()) * (c.getP().getX() - p.getX()) + (c.getP().getY() - p.getY()) * (c.getP().getY() - p.getY());
    int rr = c.getR() * c.getR();

    if (dis > rr)
    {
        cout << "点在圆外" << endl;
    }
    else if (dis == rr)
    {
        cout << "点在圆上" << endl;
    }
    else
    {
        cout << "点在圆内" << endl;
    }
}

int main()
{
    Circle c;

    c.init(0, 0, 5);

    Point p1;
    p1.init(5, 5);

    Point p2;
    p2.init(3, 4);

    Point p3;
    p3.init(1, 1);

    fun(c, p1);
    fun(c, p2);
    fun(c, p3);

    /*
        点在圆外
        点在圆上
        点在圆内
     */

    return 0;
}
```

---
