#pragma once
#include <iostream>
#include "worker.h"

using namespace std;

class Boss : public Worker
{
public:
    // 构造函数
    Boss(int mId, string name, int dId);

    // 显示个人信息
    virtual void showInfo();

    // 获取岗位名称
    virtual string getDeptName();
};