# 友元

生活中你的家有客厅(`public`)，有你的卧室(`private`)

客厅所有来的客人都可以进去，但是你的卧室是私有的，也就是说只有你能进去

但是呢，你也可以允许你的好友进去

在程序里，有些私有属性也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术

友元的目的就是让一个函数或者类访问另一个类中私有成员

友元的关键字为 `friend`

友元的三种实现

* 全局函数做友元
* 类做友元
* 成员函数做友元

---

## 全局函数做友元

demo:

```cpp
#include <iostream>

using namespace std;

class Building
{
public:
    string sittingRoom; // 客厅

private:
    string bedRoom; // 卧室

private:
    // 告诉编译器 goodFriend 全局函数是 Building 类的朋友，可以访问类中的私有内容
    friend void goodFriend(const Building &building);

public:
    Building()
    {
        this->sittingRoom = "客厅";
        this->bedRoom = "卧室";
    }
};

void goodFriend(const Building &building)
{
    cout << "好友正在访问： " << building.sittingRoom << endl;
    cout << "好友正在访问： " << building.bedRoom << endl;
}

void test1()
{
    Building b;
    goodFriend(b);
}

int main()
{
    test1();

    /*
        好友正在访问： 客厅
        好友正在访问： 卧室
    */

    return 0;
}
```

---

## 类做友元

demo:

```cpp
#include <iostream>

using namespace std;

class Building;
class GoodFriend
{
private:
    Building *building;

public:
    GoodFriend();
    void visit();
};

class Building
{
public:
    string sittingRoom; // 客厅

private:
    string bedRoom; // 卧室
    // 告诉编译器 GoodFriend 类是 Building 类的好朋友，可以访问到 Building 类中私有内容
    friend class GoodFriend;

public:
    Building();
};

Building::Building()
{
    this->sittingRoom = "客厅";
    this->bedRoom = "卧室";
}

GoodFriend::GoodFriend()
{
    building = new Building;
}

void GoodFriend::visit()
{
    cout << "好友正在访问" << building->sittingRoom << endl;
    cout << "好友正在访问" << building->bedRoom << endl;
}

void test1()
{
    GoodFriend g;
    g.visit();
}

int main()
{
    test1();

    /*
        好友正在访问客厅
        好友正在访问卧室
    */

    return 0;
}
```

---

## 成员函数做友元

demo:

```cpp
#include <iostream>

using namespace std;

class Building;
class GoodFriend
{
private:
    Building *building;

public:
    GoodFriend();
    void visit(); // 只让 visit 函数作为 Building 的好朋友，可以发访问 Building 中私有内容
    void visit2();
};

class Building
{
public:
    string sittingRoom; // 客厅

private:
    string bedRoom; // 卧室

    // 告诉编译器 GoodFriend 类中的 visit 成员函数是 Building 好朋友，可以访问私有内容
    friend void GoodFriend::visit();

public:
    Building();
};

Building::Building()
{
    this->sittingRoom = "客厅";
    this->bedRoom = "卧室";
}

GoodFriend::GoodFriend()
{
    building = new Building;
}

void GoodFriend::visit()
{
    cout << "好友正在访问" << building->sittingRoom << endl;
    cout << "好友正在访问" << building->bedRoom << endl;
}

void GoodFriend::visit2()
{
    cout << "好友正在访问" << building->sittingRoom << endl;
    // cout << "好友正在访问" << building->bedRoom << endl;
}

void test1()
{
    GoodFriend g;
    g.visit();
}

int main()
{
    test1();

    /*
        好友正在访问客厅
        好友正在访问卧室
    */

    return 0;
}
```

---
