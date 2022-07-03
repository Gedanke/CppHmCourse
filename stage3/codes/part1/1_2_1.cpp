#include <iostream>

using namespace std;

int *func(int i)
{
    // 栈区
    i = 1;
    int a = 10;
    return &a;
}

int main()
{
    // 栈区
    int *p = func(0);

    cout << *p << endl;

    /*
        main.cpp: In function ‘int* func()’:
        main.cpp:10:12: warning: address of local variable ‘a’ returned [-Wreturn-local-addr]
            10 |     return &a;
              |            ^~
        main.cpp:9:9: note: declared here
            9 |     int a = 10;
              |         ^
        Segmentation fault
    */

    return 0;
}