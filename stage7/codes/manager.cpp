#include "manager.h"

// 无参构造
Manager::Manager()
{
}

// 有参构造
Manager::Manager(string name, string password)
{
    this->name = name;
    this->password = password;

    // 初始化容器
    this->initVector();

    // 获取机房信息
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    ComputerRoom c;

    while (ifs >> c.comId && ifs >> c.maxNum)
    {
        this->vecRoom.push_back(c);
    }
    cout << "当前机房数量为： " << this->vecRoom.size() << endl;

    ifs.close();
}

// vecStu 的 get 方法
vector<Student> Manager::getVecStu()
{
    return this->vecStu;
}

// vecStu 的 set 方法
void Manager::setVecStu(vector<Student> &stu)
{
    this->vecStu = stu;
}

// vecTea 的 get 方法
vector<Teacher> Manager::getVecTea()
{
    return this->vecTea;
}

// vecTea 的 set 方法
void Manager::setVecTea(vector<Teacher> &tea)
{
    this->vecTea = tea;
}

// vecRoom 的 get 方法
vector<ComputerRoom> Manager::getVecRoom()
{
    return this->vecRoom;
}

// vecRoom 的 set 方法
void Manager::setVecRoom(vector<ComputerRoom> &room)
{
    this->vecRoom = room;
}

// 初始化容器
void Manager::initVector()
{
    this->vecStu.clear();
    this->vecTea.clear();

    // 得到学生文件中的信息
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);

    if (!ifs.is_open())
    {
        cout << "文件读取失败!" << endl;
        return;
    }

    int id;
    string name;
    string pwd;

    Student s;
    while (ifs >> id && ifs >> name && ifs >> pwd)
    {
        s.setStudentId(id);
        s.name = name;
        s.password = pwd;
        this->vecStu.push_back(s);
    }
    cout << "当前学生数量为: " << this->vecStu.size() << endl;
    ifs.close();

    /// 得到老师文件中的信息
    ifs.open(TEACHER_FILE, ios::in);

    Teacher t;
    while (ifs >> id && ifs >> name && ifs >> pwd)
    {
        t.setTeacherId(id);
        t.name = name;
        t.password = pwd;
        this->vecTea.push_back(t);
    }
    cout << "当前教师数量为: " << this->vecTea.size() << endl;
    ifs.close();
}

// 检测重复。参数: (传入 id，传入类型)。返回值: (true 代表有重复，false 代表没有重复)
bool Manager::checkRepeat(int id, int type)
{
    if (type == 1)
    {
        for (vector<Student>::iterator it = this->vecStu.begin(); it != this->vecStu.end(); it++)
        {
            if (id == it->getStudentId())
            {
                return true;
            }
        }
    }
    else
    {
        for (vector<Teacher>::iterator it = this->vecTea.begin(); it != this->vecTea.end(); it++)
        {
            if (id == it->getTeacherId())
            {
                return true;
            }
        }
    }
    return false;
}

// 菜单界面
void Manager::operMenu()
{
    cout << "欢迎管理员：" << this->name << "登录！" << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          1.添加账号            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          2.查看账号            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          3.查看机房            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          4.清空预约            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          0.注销登录            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

// 添加账号
void Manager::addAccount()
{
    cout << "请输入添加账号的类型" << endl;
    cout << "1、添加学生" << endl;
    cout << "2、添加老师" << endl;

    string fileName;
    string tip;
    string errorTip;
    ofstream ofs;

    int select;
    cin >> select;

    if (select == 1)
    {
        fileName = STUDENT_FILE;
        tip = "请输入学号: ";
        errorTip = "学号重复，请重新输入";
    }
    else if (select == 2)
    {
        fileName = TEACHER_FILE;
        tip = "请输入教职工号: ";
        errorTip = "教职工重复，请重新输入";
    }
    else
    {
        cout << "请输入 1 或者 2" << endl;
        return;
    }

    ofs.open(fileName, ios::out | ios::app);

    int id;
    string name;
    string pwd;

    cout << tip << endl;
    while (true)
    {
        cin >> id;

        bool ret = this->checkRepeat(id, select);

        if (ret)
        {
            cout << errorTip << endl;
        }
        else
        {
            break;
        }
    }

    cout << "请输入姓名: " << endl;
    cin >> name;

    cout << "请输入密码: " << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "添加成功" << endl;

    ofs.close();

    // 初始化容器
    this->initVector();
}

// 查看账号
void Manager::showAccount()
{
    cout << "请选择查看内容：" << endl;
    cout << "1、查看所有学生" << endl;
    cout << "2、查看所有老师" << endl;

    int select = -1;
    cin >> select;

    if (select == 1)
    {
        cout << "所有学生的信息如下:" << endl;
        for_each(this->vecStu.begin(), this->vecStu.end(), [](Student &s)
                 { cout << "学号： " << s.getStudentId() << " 姓名： " << s.name << " 密码：" << s.password << endl; });
    }
    else
    {
        cout << "所有教师的信息如下:" << endl;
        for_each(this->vecTea.begin(), this->vecTea.end(), [](Teacher &t)
                 { cout << "教职工号： " << t.getTeacherId() << " 姓名： " << t.name << " 密码：" << t.password << endl; });
    }
}

// 查看机房信息
void Manager::showComputer()
{
    cout << "机房信息如下: " << endl;
    for (vector<ComputerRoom>::iterator it = this->vecRoom.begin(); it != this->vecRoom.end(); it++)
    {
        cout << "机房编号： " << it->comId << " 机房最大容量： " << it->maxNum << endl;
    }
}

// 清除纪录
void Manager::cleanRecord()
{
    ofstream ofs;
    ofs.open(ORDER_FILE, ios::trunc);

    cout << "清空成功!" << endl;
}