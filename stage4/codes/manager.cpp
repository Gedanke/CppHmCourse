#include "manager.h"

// 构造函数
Manager::Manager(int mId, string name, int dId)
{
    this->mId = mId;
    this->name = name;
    this->deptId = dId;
}

// 显示个人信息
void Manager::showInfo()
{
    cout << "职工编号: " << this->mId
         << " \t职工姓名: " << this->name
         << " \t岗位: " << this->getDeptName()
         << " \t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}

// 获取岗位名称
string Manager::getDeptName()
{
    return string("经理");
}