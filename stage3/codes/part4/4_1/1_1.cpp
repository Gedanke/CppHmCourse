#include <iostream>

using namespace std;

// 圆周率
const double PI = 3.14;

// 封装的意义
// 将属性和行为作为一个整体，用来表现生活中的事物

// 封装一个圆类，求圆的周长
// class 代表设计一个类，后面跟着的是类名

class Circle
{
    // 访问权限  公共的权限
public:
    // 属性
    // 半径
    int m_r;

    // 行为
    // 获取到圆的周长
    double calculateZC()
    {
        // 2 * pi  * r
        // 获取圆的周长
        return 2 * PI * m_r;
    }
};

int main()
{
    // 通过圆类，创建圆的对象
    // c1 就是一个具体的圆，通过类创建一个对象，是实例化的过程
    Circle c1;
    c1.m_r = 10; // 给圆对象的半径进行赋值操作

    // 2 * pi * 10 = = 62.8
    cout << "圆的周长为： " << c1.calculateZC() << endl;

    /*
        圆的周长为： 62.8
    */

    return 0;
}
