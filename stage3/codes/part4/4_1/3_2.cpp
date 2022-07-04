#include <iostream>

using namespace std;

class Cube
{
private:
    double a;
    double b;
    double c;

public:
    void init(double a_, double b_, double c_)
    {
        a = a_;
        b = b_;
        c = c_;
    }

    double getA()
    {
        return a;
    }

    double getB()
    {
        return b;
    }

    double getC()
    {
        return c;
    }

    double getArea()
    {
        return 2 * a * b + 2 * a * c + 2 * b * c;
    }
    double getVolume()
    {
        return a * b * c;
    }
    bool isEqual(Cube &cube)
    {
        return a == cube.getA() && b == cube.getB() && c == cube.getC();
    }
};

bool isEqualG(Cube &c1, Cube &c2)
{
    return c1.getA() == c2.getA() && c1.getB() == c2.getB() && c1.getC() == c2.getC();
}

int main()
{
    Cube c1, c2, c3;

    c1.init(1, 2, 3);
    c2.init(1, 2, 3);
    c3.init(1, 3, 4);

    cout << "c1 的表面积: " << c1.getArea() << endl;
    cout << "c1 的体积: " << c1.getVolume() << endl;

    cout << "c2 的表面积: " << c2.getArea() << endl;
    cout << "c2 的体积: " << c2.getVolume() << endl;

    cout << "c3 的表面积: " << c3.getArea() << endl;
    cout << "c3 的体积: " << c3.getVolume() << endl;

    cout << "c1 与 c2 是否相等: " << c1.isEqual(c2) << endl;
    cout << "c1 与 c2 是否相等: " << isEqualG(c1, c2) << endl;

    cout << "c1 与 c3 是否相等: " << c1.isEqual(c3) << endl;
    cout << "c1 与 c3 是否相等: " << isEqualG(c1, c3) << endl;

    /*
        c1 的表面积: 22
        c1 的体积: 6
        c2 的表面积: 22
        c2 的体积: 6
        c3 的表面积: 38
        c3 的体积: 12
        c1 与 c2 是否相等: 1
        c1 与 c2 是否相等: 1
        c1 与 c3 是否相等: 0
        c1 与 c3 是否相等: 0
    */

    return 0;
}
