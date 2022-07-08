#include <iostream>

using namespace std;

class Building;
class GoodFriend
{
private:
    Building *building;

public:
    GoodFriend();
    void visit(); // 只让 visit 函数作为 Building 的好朋友，可以发访问 Building 中私有内容
    void visit2();
};

class Building
{
public:
    string sittingRoom; // 客厅

private:
    string bedRoom; // 卧室

    // 告诉编译器 GoodFriend 类中的 visit 成员函数是 Building 好朋友，可以访问私有内容
    friend void GoodFriend::visit();

public:
    Building();
};

Building::Building()
{
    this->sittingRoom = "客厅";
    this->bedRoom = "卧室";
}

GoodFriend::GoodFriend()
{
    building = new Building;
}

void GoodFriend::visit()
{
    cout << "好友正在访问" << building->sittingRoom << endl;
    cout << "好友正在访问" << building->bedRoom << endl;
}

void GoodFriend::visit2()
{
    cout << "好友正在访问" << building->sittingRoom << endl;
    // cout << "好友正在访问" << building->bedRoom << endl;
}

void test1()
{
    GoodFriend g;
    g.visit();
}

int main()
{
    test1();

    /*
        好友正在访问客厅
        好友正在访问卧室
    */

    return 0;
}