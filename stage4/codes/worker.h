#pragma once
#include <iostream>

using namespace std;

// Worker 抽象类
class Worker
{
public:
    // 职工编号
    int mId;
    // 职工姓名
    string name;
    // 职工所在部门名称编号
    int deptId;

public:
    // 显示个人信息
    virtual void showInfo() = 0;

    // 获取岗位名称
    virtual string getDeptName() = 0;
};
