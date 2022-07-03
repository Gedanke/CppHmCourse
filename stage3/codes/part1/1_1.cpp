#include <iostream>

using namespace std;

// 全局变量
int g_a = 10;
int g_b = 10;

// 全局常量
const int c_g_a = 10;
const int c_g_b = 10;

int main()
{
    // 局部变量
    int a = 10;
    int b = 10;

    // 打印地址
    cout << "局部变量存放在栈区:" << endl;
    cout << "局部变量 a 地址为： " << &a << endl;
    cout << "局部变量 b 地址为： " << &b << endl;

    cout << "全局变量，静态变量与全局常量(全局常量，字符串常量)存放在全局区:" << endl;
    cout << "全局变量 g_a 地址为： " << &g_a << endl;
    cout << "全局变量 g_b 地址为： " << &g_b << endl;

    // 静态变量
    static int s_a = 10;
    static int s_b = 10;

    cout << "静态变量 s_a 地址为： " << &s_a << endl;
    cout << "静态变量 s_b 地址为： " << &s_b << endl;

    cout << "字符串常量地址为： " << &"hello world" << endl;
    cout << "字符串常量地址为： " << &"hello world1" << endl;

    cout << "全局常量 c_g_a 地址为： " << &c_g_a << endl;
    cout << "全局常量 c_g_b 地址为： " << &c_g_b << endl;

    const int c_l_a = 10;
    const int c_l_b = 10;

    cout << "局部常量存放在栈区:" << endl;
    cout << "局部常量 c_l_a 地址为： " << &c_l_a << endl;
    cout << "局部常量 c_l_b 地址为： " << &c_l_b << endl;

    /*
        局部变量存放在栈区:
        局部变量 a 地址为： 0x7fff332e0908
        局部变量 b 地址为： 0x7fff332e090c
        全局变量，静态变量与常量(全局常量，字符串常量)存放在全局区:
        全局变量 g_a 地址为： 0x555e1db7f010
        全局变量 g_b 地址为： 0x555e1db7f014
        静态变量 s_a 地址为： 0x555e1db7f018
        静态变量 s_b 地址为： 0x555e1db7f01c
        字符串常量地址为： 0x555e1db7d144
        字符串常量地址为： 0x555e1db7d150
        全局常量 c_g_a 地址为： 0x555e1db7d00c
        全局常量 c_g_b 地址为： 0x555e1db7d010
        局部常量存放在栈区:
        局部常量 c_l_a 地址为： 0x7fff332e0910
        局部常量 c_l_b 地址为： 0x7fff332e0914
    */

    return 0;
}