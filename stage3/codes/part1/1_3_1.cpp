#include <iostream>

using namespace std;

int *func()
{
    int *a = new int(10);
    cout << "&a = " << a << endl;
    return a;
}

int main()
{
    int *p = func();

    cout << *p << endl;
    cout << *p << endl;
    cout << "&p = " << p << endl;

    // 利用 delete 释放堆区数据
    delete p;

    // cout << *p << endl; // 报错，释放的空间不可访问

    /*
        &a = 0x556c6fb68eb0
        10
        10
        &a = 0x556c6fb68eb0
    */

    return 0;
}