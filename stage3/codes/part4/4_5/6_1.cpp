#include <iostream>

using namespace std;

class MyPrint
{
public:
    void operator()(string text)
    {
        cout << text << endl;
    }
};

void test1()
{
    // 重载的 () 操作符也称为仿函数
    MyPrint myFunc;
    myFunc("hello world");
}

class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

void test2()
{
    MyAdd add;
    int ret = add(10, 10);
    cout << "ret = " << ret << endl;

    // 匿名对象调用
    cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
}

int main()
{
    test1();
    test2();

    /*
        hello world
        ret = 20
        MyAdd()(100,100) = 200
    */

    return 0;
}