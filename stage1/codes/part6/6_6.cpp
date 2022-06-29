#include <iostream>

using namespace std;

// 声明可以多次，定义只能一次
// 声明
int max(int a, int b);
int max(int a, int b);

int main()
{
    int a = 100;
    int b = 200;

    cout << max(a, b) << endl;

    // 200

    return 0;
}

// 定义
int max(int a, int b)
{
    return a > b ? a : b;
}