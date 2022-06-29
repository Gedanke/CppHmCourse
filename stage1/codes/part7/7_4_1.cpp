#include <iostream>

using namespace std;

int main()
{
    // 指针变量 p 指向内存地址编号为 0 的空间
    int *p = NULL;
    int *pp;

    // 访问空指针报错
    // 内存编号 0 ~ 255 为系统占用内存，不允许用户访问
    cout << *p << endl;
    cout << p << endl;
    cout << *pp << endl;
    cout << pp << endl;

    // Segmentation fault

    return 0;
}