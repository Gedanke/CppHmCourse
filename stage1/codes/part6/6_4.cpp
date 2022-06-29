#include <iostream>

using namespace std;

void swap(int num1, int num2)
{
    cout << "交换前：" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "交换后：" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    // return ; // 当函数声明时候，不需要返回值，可以不写 return
}

int main()
{
    int a = 10;
    int b = 20;

    swap(a, b);

    cout << "main中的 a = " << a << endl;
    cout << "main中的 b = " << b << endl;

    /*
        交换前：
        num1 = 10
        num2 = 20
        交换后：
        num1 = 20
        num2 = 10
        main 中的 a = 10
        main 中的 b = 20
    */

    return 0;
}