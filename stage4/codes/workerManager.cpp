#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

// 构造函数
WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    // 文件不存在
    if (!ifs.is_open())
    {
        // 测试输出
        // cout << "文件不存在" << endl;
        // 初始化人数
        this->num = 0;
        // 初始化数组指针
        this->workerArray = NULL;
        // 初始化文件为空标志
        this->fileIsEmpty = true;
        // 关闭文件
        ifs.close();
        return;
    }

    // 文件存在，并且没有记录
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        // cout << "文件为空!" << endl;
        // 初始化人数
        this->num = 0;
        // 初始化数组指针
        this->workerArray = NULL;
        // 初始化文件为空标志
        this->fileIsEmpty = true;
        // 关闭文件
        ifs.close();
        return;
    }

    int num = this->getWorkerNum();
    // 测试代码
    // cout << "职工个数为：" << num << endl;
    // 更新成员属性
    this->num = num;

    // 根据职工数创建数组
    this->workerArray = new Worker *[this->num];
    // 初始化职工
    this->initWorker();
    // 文件不为空且存在数据
    this->fileIsEmpty = false;

    // 测试代码
    // for (int i = 0; i < this->num; i++)
    // {
    //     cout << "职工号： " << this->workerArray[i]->mId
    //          << " 职工姓名： " << this->workerArray[i]->name
    //          << " 部门编号： " << this->workerArray[i]->deptId << endl;
    // }

    // 关闭文件
    ifs.close();
}

// 展示菜单
void WorkerManager::showMenu()
{
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

// 增加职工
void WorkerManager::addWorker()
{
    cout << "请输入增加职工数量： " << endl;

    int num = 0;
    cin >> num;

    if (num > 0)
    {
        // 计算新开辟的内存空间大小
        int size = this->num + num;
        // 开辟新的空间
        Worker **newSpace = new Worker *[size];

        // 将原空间下内容存放到新空间下
        if (this->workerArray != NULL)
        {
            for (int i = 0; i < this->num; i++)
            {
                newSpace[i] = this->workerArray[i];
            }
        }

        // 输入新的数据
        for (int i = 0; i < num; i++)
        {
            int id;
            string name;
            int dSelect;

            cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
            cin >> id;

            cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
            cin >> name;

            cout << "请选择该职工的岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
            {
                // 普通员工
                worker = new Employee(id, name, 1);
                break;
            }
            case 2:
            {
                // 经理
                worker = new Manager(id, name, 2);
                break;
            }
            case 3:
            {
                // 老板
                worker = new Boss(id, name, 3);
                break;
            }
            default:
            {
                break;
            }
            }
            newSpace[this->num + i] = worker;
        }

        // 释放原有空间
        delete[] this->workerArray;
        // 更改指针指向
        this->workerArray = newSpace;
        // 更新个数
        this->num = size;
        // 更新职工不为空标志
        this->fileIsEmpty = false;
        // 提示信息
        cout << "成功添加" << num << "名新职工！" << endl;

        // 保存到文件中
        this->save();
    }
    else
    {
        cout << "输入有误" << endl;
    }
}

// 保存文件
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->num; i++)
    {
        ofs << this->workerArray[i]->mId << " "
            << this->workerArray[i]->name << " "
            << this->workerArray[i]->deptId << endl;
    }

    ofs.close();
}

// 统计人数
int WorkerManager::getWorkerNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int num = 0;

    int id;
    string name;
    int dId;

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        // 纪录人数
        num++;
    }
    ifs.close();
    return num;
}

// 初始化员工
void WorkerManager::initWorker()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int idx = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker *worker = NULL;
        // 根据不同的部门 id 创建不同对象
        if (dId == 1)
        {
            // 1 普通员工
            worker = new Employee(id, name, dId);
        }
        else if (dId == 2)
        {
            // 2 经理
            worker = new Manager(id, name, dId);
        }
        else
        {
            // 3 总裁
            worker = new Boss(id, name, dId);
        }
        // 存放在数组中
        this->workerArray[idx] = worker;
        idx++;
    }

    // 关闭文件
    ifs.close();
}

// 显示职工
void WorkerManager::showWorker()
{
    if (this->fileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        for (int i = 0; i < num; i++)
        {
            // 利用多态调用接口
            this->workerArray[i]->showInfo();
        }
    }
}

// 按照职工编号判断职工是否存在，若存在返回职工在数组中位置，不存在返回 -1
int WorkerManager::isExist(int id)
{
    int idx = -1;
    for (int i = 0; i < this->num; i++)
    {
        if (this->workerArray[i]->mId == id)
        {
            idx = i;
            break;
        }
    }
    return idx;
}

// 删除职工
void WorkerManager::deleteWorker()
{
    if (this->fileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        // 按职工编号删除
        cout << "请输入想要删除的职工号：" << endl;
        int id = 0;
        cin >> id;

        int index = this->isExist(id);
        if (index != -1)
        {
            for (int i = index; i < this->num; i++)
            {
                this->workerArray[i] = this->workerArray[i + 1];
            }
            this->num--;

            // 同步数据到文件中
            this->save();
            cout << "删除成功！" << endl;
        }
        else
        {
            cout << "删除失败，未找到该职工" << endl;
        }
    }
}

// 修改职工
void WorkerManager::modWorker()
{
    if (this->fileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        cout << "请输入修改职工的编号：" << endl;

        int id;
        cin >> id;

        int ret = this->isExist(id);
        if (ret != -1)
        {
            // 查找到编号的职工
            delete this->workerArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
            cin >> newId;

            cout << "请输入新姓名： " << endl;
            cin >> newName;

            cout << "请输入岗位： " << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(newId, newName, dSelect);
                break;
            case 2:
                worker = new Manager(newId, newName, dSelect);
                break;
            case 3:
                worker = new Boss(newId, newName, dSelect);
                break;
            default:
                break;
            }

            // 更改数据到数组中
            this->workerArray[ret] = worker;
            cout << "修改成功！" << endl;

            // 保存到文件中
            this->save();
        }
        else
        {
            cout << "修改失败，查无此人" << endl;
        }
    }
}

// 查找职工
void WorkerManager::findWorker()
{
    if (this->fileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        cout << "请输入查找的方式：" << endl;
        cout << "1、按职工编号查找" << endl;
        cout << "2、按姓名查找" << endl;

        int select = 0;
        cin >> select;

        // 按职工号查找
        if (select == 1)
        {
            int id;
            cout << "请输入查找的职工编号：" << endl;
            cin >> id;

            int ret = this->isExist(id);
            if (ret != -1)
            {
                cout << "查找成功！该职工信息如下：" << endl;
                this->workerArray[ret]->showInfo();
            }
            else
            {
                cout << "查找失败，查无此人" << endl;
            }
        }
        // 按姓名查找
        else if (select == 2)
        {
            string name;
            cout << "请输入查找的姓名：" << endl;
            cin >> name;

            // 查找到的标志
            bool flag = false;
            for (int i = 0; i < this->num; i++)
            {
                if (this->workerArray[i]->name == name)
                {
                    cout << "查找成功,职工编号为："
                         << this->workerArray[i]->mId
                         << " 号的信息如下：" << endl;
                    flag = true;
                    this->workerArray[i]->showInfo();
                }
            }
            if (flag == false)
            {
                // 查无此人
                cout << "查找失败，查无此人" << endl;
            }
        }
        else
        {
            cout << "输入选项有误" << endl;
        }
    }
}

// 排序职工
void WorkerManager::sortWorker()
{
    if (this->fileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        cout << "请选择排序方式： " << endl;
        cout << "1、按职工号进行升序" << endl;
        cout << "2、按职工号进行降序" << endl;

        int select = 0;
        cin >> select;

        for (int i = 0; i < this->num; i++)
        {
            int minOrMax = i;
            for (int j = i + 1; j < this->num; j++)
            {
                // 升序
                if (select == 1)
                {
                    if (this->workerArray[minOrMax]->mId > this->workerArray[j]->mId)
                    {
                        minOrMax = j;
                    }
                }
                // 降序
                else
                {
                    if (this->workerArray[minOrMax]->mId < this->workerArray[j]->mId)
                    {
                        minOrMax = j;
                    }
                }
            }

            if (i != minOrMax)
            {
                Worker *temp = this->workerArray[i];
                this->workerArray[i] = this->workerArray[minOrMax];
                this->workerArray[minOrMax] = temp;
            }
        }

        cout << "排序成功,排序后结果为：" << endl;
        this->save();
        this->showWorker();
    }
}

// 清空文件
void WorkerManager::clearFile()
{
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        // 打开模式 ios::trunc 如果存在删除文件并重新创建
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if (this->workerArray != NULL)
        {
            for (int i = 0; i < this->num; i++)
            {
                if (this->workerArray[i] != NULL)
                {
                    delete this->workerArray[i];
                }
            }
            this->num = 0;
            delete[] this->workerArray;
            this->workerArray = NULL;
            this->fileIsEmpty = true;
        }
        cout << "清空成功！" << endl;
    }
}

// 退出系统
void WorkerManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}

// 析构函数
WorkerManager::~WorkerManager()
{
    if (this->workerArray != NULL)
    {
        delete[] this->workerArray;
    }
}
