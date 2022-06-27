#include <iostream>

using namespace std;

// #define 宏常量
#define day 7

int main()
{
    cout << "一周里总共有 " << day << " 天" << endl;
    // day = 8;  // 报错，扩展到: 7，表达式必须是可修改的左值

    // const 修饰变量
    const int month = 12;
    cout << "一年里总共有 " << month << " 个月份" << endl;
    // month = 24; // 报错，const 修饰变量，表达式必须是可修改的左值

    /*
        一周里总共有 7 天
        一年里总共有 12 个月份
    */

    return 0;
}