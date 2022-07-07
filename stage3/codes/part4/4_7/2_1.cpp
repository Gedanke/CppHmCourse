#include <iostream>

using namespace std;

// 普通实现
class Calculator
{
public:
    int m_Num1;
    int m_Num2;

public:
    int getResult(string oper)
    {
        if (oper == "+")
        {
            return m_Num1 + m_Num2;
        }
        else if (oper == "-")
        {
            return m_Num1 - m_Num2;
        }
        else if (oper == "*")
        {
            return m_Num1 * m_Num2;
        }
        else
        {
            return -1;
        }
        // 如果要提供新的运算，需要修改源码
    }
};

void test1()
{
    // 普通实现测试
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;

    cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
    cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
    cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}

// 多态实现
// 抽象计算器类
// 多态优点：代码组织结构清晰，可读性强，利于前期和后期的扩展以及维护
class AbstractCalculator
{
public:
    int m_Num1;
    int m_Num2;

public:
    virtual int getResult()
    {
        return 0;
    }
};

// 加法计算器
class AddCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 + m_Num2;
    }
};

// 减法计算器
class SubCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 - m_Num2;
    }
};

// 乘法计算器
class MulCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 * m_Num2;
    }
};

void test2()
{
    AbstractCalculator *abc;
    // 创建加法计算器
    abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc; // 用完了记得销毁

    // 创建减法计算器
    abc = new SubCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc;

    // 创建乘法计算器
    abc = new MulCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc;
}

int main()
{
    test1();

    cout << "======" << endl;

    test2();

    /*
        10 + 10 = 20
        10 - 10 = 0
        10 * 10 = 100
        ======
        10 + 10 = 20
        10 - 10 = 0
        10 * 10 = 100
    */

    return 0;
}