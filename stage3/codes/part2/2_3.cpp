#include <iostream>

using namespace std;

// 值传递
void mySwap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 地址传递
void mySwap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 引用传递
void mySwap3(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10;
    int b = 20;

    mySwap1(a, b);
    cout << "a:" << a << " b:" << b << endl;

    mySwap2(&a, &b);
    cout << "a:" << a << " b:" << b << endl;

    mySwap3(a, b);
    cout << "a:" << a << " b:" << b << endl;

    /*
        a:10 b:20
        a:20 b:10
        a:10 b:20
    */

    return 0;
}