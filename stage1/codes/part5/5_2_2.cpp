#include <iostream>

using namespace std;

int main()
{
    // 数组名用途
    // 1、可以获取整个数组占用内存空间大小
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "整个数组所占内存空间为： " << sizeof(arr) << endl;
    cout << "每个元素所占内存空间为： " << sizeof(arr[0]) << endl;
    cout << "数组的元素个数为： " << sizeof(arr) / sizeof(arr[0]) << endl;

    // 2、可以通过数组名获取到数组首地址，用 (long long) 转成十进制地址
    cout << "数组首地址为： " << &arr << endl;
    cout << "数组中第一个元素地址为： " << &arr[0] << endl;
    cout << "数组中第二个元素地址为： " << &arr[1] << endl;

    // arr = 100; 错误，数组名是常量，因此不可以赋值

    /*
        整个数组所占内存空间为： 40
        每个元素所占内存空间为： 4
        数组的元素个数为： 10
        数组首地址为： 0x7ffe8773a460
        数组中第一个元素地址为： 0x7ffe8773a460
        数组中第二个元素地址为： 0x7ffe8773a464
    */

    return 0;
}