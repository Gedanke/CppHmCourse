#include "employee.h"

// 构造函数
Employee::Employee(int mId, string name, int dId)
{
    this->mId = mId;
    this->name = name;
    this->deptId = dId;
}

// 显示个人信息
void Employee::showInfo()
{
    cout << "职工编号: " << this->mId
         << " \t职工姓名: " << this->name
         << " \t岗位: " << this->getDeptName()
         << " \t岗位职责: 完成经理交给的任务" << endl;
}

// 获取岗位名称
string Employee::getDeptName()
{
    return string("员工");
}