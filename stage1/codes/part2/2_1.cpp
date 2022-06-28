#include <iostream>

using namespace std;

int main()
{
    // 短整型 [-32768, 32767]
    short num1 = 10;
    short num11 = 32768;

    // 整型
    int num2 = 10;

    // 长整型
    long num3 = 10;

    // 长长整型
    long long num4 = 10;

    cout << "num1 = " << num1 << endl;
    cout << "num11 = " << num11 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num3 = " << num3 << endl;
    cout << "num4 = " << num4 << endl;

    /*
        num1 = 10
        num11 = -32768
        num2 = 10
        num3 = 10
        num4 = 10
    */

    return 0;
}