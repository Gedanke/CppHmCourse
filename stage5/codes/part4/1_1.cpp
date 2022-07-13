#include <iostream>

using namespace std;

// 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

void test1()
{
    MyAdd myAdd;
    cout << myAdd(10, 10) << endl;
}

// 函数对象可以有自己的状态
class MyPrint
{
public:
    // 内部自己的状态
    int count;

public:
    MyPrint()
    {
        this->count = 0;
    }

    void operator()(string test)
    {
        cout << test << endl;
        // 统计使用次数
        this->count++;
    }
};

void test2()
{
    MyPrint myPrint;
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    cout << "myPrint 调用次数为：" << myPrint.count << endl;
}

// 函数对象可以作为参数传递
void doPrint(MyPrint &mp, string test)
{
    mp(test);
}

void test3()
{
    MyPrint myPrint;
    doPrint(myPrint, "Hello C++");
}

int main()
{
    test1();
    test2();
    test3();

    /*
        20
        hello world
        hello world
        hello world
        myPrint 调用次数为：3
        Hello C++
    */

    return 0;
}