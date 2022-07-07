#include <iostream>

using namespace std;

// 抽象制作饮品
class AbstractDrinking
{
public:
    // 烧水
    virtual void Boil() = 0;
    // 冲泡
    virtual void Brew() = 0;
    // 倒入杯中
    virtual void PourInCup() = 0;
    // 加入辅料
    virtual void PutSomething() = 0;
    // 规定流程
    void MakeDrink()
    {
        this->Boil();
        this->Brew();
        this->PourInCup();
        this->PutSomething();
    }
};

// 制作咖啡
class Coffee : public AbstractDrinking
{
public:
    // 烧水
    virtual void Boil()
    {
        cout << "煮农夫山泉!" << endl;
    }
    // 冲泡
    virtual void Brew()
    {
        cout << "冲泡咖啡!" << endl;
    }
    // 倒入杯中
    virtual void PourInCup()
    {
        cout << "将咖啡倒入杯中!" << endl;
    }
    // 加入辅料
    virtual void PutSomething()
    {
        cout << "加入牛奶!" << endl;
    }
};

// 制作茶水
class Tea : public AbstractDrinking
{
public:
    // 烧水
    virtual void Boil()
    {
        cout << "煮自来水!" << endl;
    }
    // 冲泡
    virtual void Brew()
    {
        cout << "冲泡茶叶!" << endl;
    }
    // 倒入杯中
    virtual void PourInCup()
    {
        cout << "将茶水倒入杯中!" << endl;
    }
    // 加入辅料
    virtual void PutSomething()
    {
        cout << "加入枸杞!" << endl;
    }
};

// 业务函数
void DoWork(AbstractDrinking *drink)
{
    drink->MakeDrink();
    delete drink;
}

void test1()
{
    DoWork(new Coffee);
    cout << "--------------" << endl;
    DoWork(new Tea);
}

int main()
{
    test1();

    /*
        煮农夫山泉!
        冲泡咖啡!
        将咖啡倒入杯中!
        加入牛奶!
        --------------
        煮自来水!
        冲泡茶叶!
        将茶水倒入杯中!
        加入枸杞!
    */

    return 0;
}