#include <iostream>

using namespace std;

class Building
{
public:
    string sittingRoom; // 客厅

private:
    string bedRoom; // 卧室

private:
    // 告诉编译器 goodFriend 全局函数是 Building 类的朋友，可以访问类中的私有内容
    friend void goodFriend(const Building &building);

public:
    Building()
    {
        this->sittingRoom = "客厅";
        this->bedRoom = "卧室";
    }
};

void goodFriend(const Building &building)
{
    cout << "好友正在访问： " << building.sittingRoom << endl;
    cout << "好友正在访问： " << building.bedRoom << endl;
}

void test1()
{
    Building b;
    goodFriend(b);
}

int main()
{
    test1();

    /*
        好友正在访问： 客厅
        好友正在访问： 卧室
    */

    return 0;
}