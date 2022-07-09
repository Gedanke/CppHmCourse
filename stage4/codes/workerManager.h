#pragma once
#include <iostream>
#include "worker.h"
#include <fstream>
#define FILENAME "empFile.txt"

using namespace std;

class WorkerManager
{
public:
    // 记录文件中的人数个数
    int num;
    // 员工数组的指针
    Worker **workerArray;
    // 标志文件是否为空
    bool fileIsEmpty;

public:
    // 构造函数
    WorkerManager();

    // 展示菜单
    void showMenu();

    // 增加职工
    void addWorker();

    // 保存文件
    void save();

    // 统计人数
    int getWorkerNum();

    // 初始化员工
    void initWorker();

    // 显示职工
    void showWorker();

    // 按照职工编号判断职工是否存在，若存在返回职工在数组中位置，不存在返回 -1
    int isExist(int id);

    // 删除职工
    void deleteWorker();

    // 修改职工
    void modWorker();

    // 查找职工
    void findWorker();

    // 排序职工
    void sortWorker();

    // 清空文件
    void clearFile();

    // 退出系统
    void exitSystem();

    // 析构函数
    ~WorkerManager();
};
