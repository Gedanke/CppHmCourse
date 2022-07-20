#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"

using namespace std;

class Manager : public Identity
{
private:
    // 学生容器
    vector<Student> vecStu;

    // 教师容器
    vector<Teacher> vecTea;

    // 机房容器
    vector<ComputerRoom> vecRoom;

public:
    // 无参构造
    Manager();

    // 有参构造
    Manager(string name, string password);

    // vecStu 的 get 方法
    vector<Student> getVecStu();

    // vecStu 的 set 方法
    void setVecStu(vector<Student> &stu);

    // vecTea 的 get 方法
    vector<Teacher> getVecTea();

    // vecTea 的 set 方法
    void setVecTea(vector<Teacher> &tea);

    // vecRoom 的 get 方法
    vector<ComputerRoom> getVecRoom();

    // vecRoom 的 set 方法
    void setVecRoom(vector<ComputerRoom> &room);

    // 初始化容器
    void initVector();

    // 检测重复。参数: (传入 id，传入类型)。返回值: (true 代表有重复，false 代表没有重复)
    bool checkRepeat(int id, int type);

    // 菜单界面
    virtual void operMenu();

    // 添加账号
    void addAccount();

    // 查看账号
    void showAccount();

    // 查看机房信息
    void showComputer();

    // 清除纪录
    void cleanRecord();
};
