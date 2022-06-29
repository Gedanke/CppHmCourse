#include <iostream>

using namespace std;

int main()
{
    // 指针变量 p 指向内存地址编号为 0x1100 的空间
    int *p = (int *)0x1100;

    // 访问野指针报错
    cout << *p << endl;

    // Segmentation fault

    return 0;
}