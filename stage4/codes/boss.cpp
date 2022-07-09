#include "boss.h"

// 构造函数
Boss::Boss(int mId, string name, int dId)
{
    this->mId = mId;
    this->name = name;
    this->deptId = dId;
}

// 显示个人信息
void Boss::showInfo()
{
    cout << "职工编号: " << this->mId
         << " \t职工姓名: " << this->name
         << " \t岗位: " << this->getDeptName()
         << " \t岗位职责：管理公司所有事务" << endl;
}

// 获取岗位名称
string Boss::getDeptName()
{
    return string("总裁");
}