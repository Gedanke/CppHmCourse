#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "computerRoom.h"
#include "identity.h"
#include "globalFile.h"
#include "orderFile.h"

using namespace std;

// 学生类
class Student : public Identity
{
private:
    int studentId;

    // 机房容器
    vector<ComputerRoom> vecCom;

public:
    // 无参构造
    Student();

    // 有参构造
    Student(int studentId, string name, string password);

    // studentId 的 get 的方法
    int getStudentId();

    // studentId 的 set 的方法
    void setStudentId(int studentId);

    // vecCom 的 get 的方法
    vector<ComputerRoom> getVecCom();

    // vecCom 的 set 的方法
    void setVecCom(vector<ComputerRoom> &vecCom);

    // 菜单界面
    virtual void operMenu();

    // 申请预约
    void applyOrder();

    // 查看我的预约
    void showMyOrder();

    // 查看所有预约
    void showAllOrder();

    // 取消预约
    void canceOrder();
};
