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