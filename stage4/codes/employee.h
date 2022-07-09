#pragma once
#include <iostream>
#include "worker.h"

using namespace std;

// 员工类

class Employee : public Worker
{
public:
    // 构造函数
    Employee(int mId, string name, int dId);

    // 显示个人信息
    virtual void showInfo();

    // 获取岗位名称
    virtual string getDeptName();
};
