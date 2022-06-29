#include <iostream>

using namespace std;

// 函数常见样式
// 1、无参无返
void test1()
{
    // void a = 10; // 无类型不可以创建变量，原因无法分配内存
    cout << "this is test1" << endl;
}

// 2、有参无返
void test2(int a)
{
    cout << "this is test2" << endl;
    cout << "a = " << a << endl;
}

// 3、无参有返
int test3()
{
    cout << "this is test3 " << endl;
    return 10;
}

// 4、有参有返
int test4(int a, int b)
{
    cout << "this is test4 " << endl;
    int sum = a + b;
    return sum;
}

int main()
{
    test1();
    test2(1);
    cout << test3() << endl;
    cout << test4(1, 2) << endl;

    /*
        this is test1
        this is test2
        a = 1
        this is test3
        10
        this is test4
        3
    */

    return 0;
}