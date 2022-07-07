#include <iostream>

using namespace std;

class Base
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

// 公共继承
class Son1 : public Base
{
public:
    void func()
    {
        m_A; // 可访问 public 权限
        m_B; // 可访问 protected 权限
        // m_C; // 不可访问
    }
};

void myClass()
{
    Son1 s1;
    s1.m_A; // 其他类只能访问到公共权限
}

// 保护继承
class Son2 : protected Base
{
public:
    void func()
    {
        m_A; // 可访问 protected 权限
        m_B; // 可访问 protected 权限
        // m_C; // 不可访问
    }
};

void myClass2()
{
    Son2 s;
    // s.m_A; // 不可访问
}

// 私有继承
class Son3 : private Base
{
public:
    void func()
    {
        m_A; // 可访问 private 权限
        m_B; // 可访问 private 权限
        // m_C; // 不可访问
    }
};

class GrandSon3 : public Son3
{
public:
    void func()
    {
        // Son3 是私有继承，所以继承 Son3 的属性在 GrandSon3 中都无法访问到
        // m_A;
        // m_B;
        // m_C;
    }
};

int main()
{

    /*
     */

    return 0;
}