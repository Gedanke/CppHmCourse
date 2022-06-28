#include <iostream>

using namespace std;

int main()
{
    // 不加 f，编译器默认为 double，会进行类型转换，损失精度
    float f1 = 3.14f;
    double d1 = 3.14;

    cout << "f1 = " << f1 << endl;
    cout << "d1 = " << d1 << endl;

    f1 = 3.1415926f;
    d1 = 3.1415926;

    // 默认显示 6 位有效数字
    cout << "f1 = " << f1 << endl;
    cout << "d1 = " << d1 << endl;

    cout << "float  sizeof = " << sizeof(f1) << endl;
    cout << "double sizeof = " << sizeof(d1) << endl;

    // 科学计数法
    float f2 = 3e2; // 3 * 10 ^ 2
    cout << "f2 = " << f2 << endl;

    float f3 = 3e-2; // 3 * 0.1 ^ 2
    cout << "f3 = " << f3 << endl;

    /*
        f1 = 3.14
        d1 = 3.14
        f1 = 3.14159
        d1 = 3.14159
        float  sizeof = 4
        double sizeof = 8
        f2 = 300
        f3 = 0.03
    */

    return 0;
}