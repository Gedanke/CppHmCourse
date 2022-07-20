#pragma once
#include <iostream>
#include <vector>
#include "identity.h"
#include "orderFile.h"

using namespace std;

class Teacher : public Identity
{
private:
    int teacherId;

public:
    // 无参构造
    Teacher();

    // 有参构造
    Teacher(int teacherId, string name, string password);

    // teacherId 的 get 的方法
    int getTeacherId();

    // teacherId 的 set 的方法
    void setTeacherId(int teacherId);

    // 菜单界面
    virtual void operMenu();

    // 查看所有预约
    void showAllOrder();

    // 审核预约
    void validOrder();
};