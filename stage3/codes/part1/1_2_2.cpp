#include <iostream>

using namespace std;

int *func()
{
    // a 在栈区
    // new int(10) 返回的地址是在堆上
    int *a = new int(10);
    return a;
}

int main()
{
    // 栈区
    int *p = func();

    cout << *p << endl;
    cout << *p << endl;

    /*
        10
        10
    */

    return 0;
}