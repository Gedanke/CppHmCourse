#include <iostream>

using namespace std;

class Building;
class GoodFriend
{
private:
    Building *building;

public:
    GoodFriend();
    void visit();
};

class Building
{
public:
    string sittingRoom; // 客厅

private:
    string bedRoom; // 卧室
    // 告诉编译器 GoodFriend 类是 Building 类的好朋友，可以访问到 Building 类中私有内容
    friend class GoodFriend;

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