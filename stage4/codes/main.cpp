#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

void start();
void test();

int main()
{
    start();
    // test();

    /*
        g++ -o main boss.cpp employee.cpp manager.cpp workerManager.cpp main.cpp && ./main
     */

    return 0;
}

void test()
{
    Worker *worker = NULL;

    worker = new Employee(1, "张三", 1);
    worker->showInfo();
    delete worker;

    worker = new Manager(2, "李四", 2);
    worker->showInfo();
    delete worker;

    worker = new Boss(3, "王五", 3);
    worker->showInfo();
    delete worker;
}

void start()
{
    WorkerManager wm;
    int choice = 1;
    while (true)
    {
        // 展示菜单
        wm.showMenu();
        cout << "请输入您的选择:" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            // 退出系统
            wm.exitSystem();
            break;
        case 1:
            // 添加职工
            wm.addWorker();
            break;
        case 2:
            // 显示职工
            wm.showWorker();
            break;
        case 3:
            // 删除职工
            wm.deleteWorker();
            break;
        case 4:
            // 修改职工
            wm.modWorker();
            break;
        case 5:
            // 查找职工
            wm.findWorker();
            break;
        case 6:
            // 排序职工
            wm.sortWorker();
            break;
        case 7:
            // 清空文件
            wm.clearFile();
            break;
        default:
            system("clear");
            break;
        }
    }
}