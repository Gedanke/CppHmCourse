#include <iostream>

using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    void init(int x_, int y_)
    {
        x = x_;
        y = y_;
    }
    void setX(int x_)
    {
        x = x_;
    }
    int getX()
    {
        return x;
    }
    void setY(int y_)
    {
        y = y_;
    }
    int getY()
    {
        return y;
    }
};

class Circle
{
private:
    Point p;
    int r;

public:
    void init(int x_, int y_, int r_)
    {
        p.setX(x_);
        p.setY(y_);
        r = r_;
    }
    void setR(int r_)
    {
        r = r_;
    }
    int getR()
    {
        return r;
    }
    void setP(int x_, int y_)
    {
        p.setX(x_);
        p.setY(y_);
    }
    Point getP()
    {
        return p;
    }
};

void fun(Circle c, Point p)
{
    int dis = (c.getP().getX() - p.getX()) * (c.getP().getX() - p.getX()) + (c.getP().getY() - p.getY()) * (c.getP().getY() - p.getY());
    int rr = c.getR() * c.getR();

    if (dis > rr)
    {
        cout << "点在圆外" << endl;
    }
    else if (dis == rr)
    {
        cout << "点在圆上" << endl;
    }
    else
    {
        cout << "点在圆内" << endl;
    }
}

int main()
{
    Circle c;

    c.init(0, 0, 5);

    Point p1;
    p1.init(5, 5);

    Point p2;
    p2.init(3, 4);

    Point p3;
    p3.init(1, 1);

    fun(c, p1);
    fun(c, p2);
    fun(c, p3);

    /*
        点在圆外
        点在圆上
        点在圆内
     */

    return 0;
}
