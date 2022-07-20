#include "student.h"

// 无参构造
Student::Student()
{
}

// 有参构造
Student::Student(int studentId, string name, string password)
{
    // 初始化属性
    this->studentId = studentId;
    this->name = name;
    this->password = password;

    // 获取机房信息
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    ComputerRoom c;
    while (ifs >> c.comId && ifs >> c.maxNum)
    {
        this->vecCom.push_back(c);
    }
    ifs.close();
}

// studentId 的 get 的方法
int Student::getStudentId()
{
    return this->studentId;
}

// studentId 的 set 的方法
void Student::setStudentId(int studentId)
{
    this->studentId = studentId;
}

// vecCom 的 get 的方法
vector<ComputerRoom> Student::getVecCom()
{
    return this->vecCom;
}

// vecCom 的 set 的方法
void Student::setVecCom(vector<ComputerRoom> &vecCom)
{
    this->vecCom = vecCom;
}

// 菜单界面
void Student::operMenu()
{
    cout << "欢迎学生代表：" << this->name << "登录！" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          1.申请预约              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          2.查看我的预约          |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          3.查看所有预约          |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          4.取消预约              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          0.注销登录              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t ----------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

// 申请预约
void Student::applyOrder()
{
    cout << "机房开放时间为周一至周五！" << endl;
    cout << "请输入申请预约的时间：" << endl;
    cout << "1、周一" << endl;
    cout << "2、周二" << endl;
    cout << "3、周三" << endl;
    cout << "4、周四" << endl;
    cout << "5、周五" << endl;

    int date = 0;
    int interval = 0;
    int room = 0;

    while (true)
    {
        cin >> date;
        if (date >= 1 && date <= 5)
        {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "请输入申请预约的时间段：" << endl;
    cout << "1、上午" << endl;
    cout << "2、下午" << endl;

    while (true)
    {
        cin >> interval;
        if (interval >= 1 && interval <= 2)
        {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "请选择机房：" << endl;
    cout << "1 号机房容量：" << this->vecCom[0].maxNum << endl;
    cout << "2 号机房容量：" << this->vecCom[1].maxNum << endl;
    cout << "3 号机房容量：" << this->vecCom[2].maxNum << endl;

    while (true)
    {
        cin >> room;
        if (room >= 1 && room <= 3)
        {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "预约成功！审核中" << endl;

    ofstream ofs(ORDER_FILE, ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->studentId << " ";
    ofs << "stuName:" << this->name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << endl;

    ofs.close();
}

// 查看我的预约
void Student::showMyOrder()
{
    OrderFile of;
    if (of.size == 0)
    {
        cout << "无预约记录" << endl;
        return;
    }

    for (int i = 0; i < of.size; i++)
    {
        if (atoi(of.orderData[i]["stuId"].c_str()) == this->studentId)
        {
            cout << "预约日期： 周" << of.orderData[i]["date"];
            cout << " 时段：" << (of.orderData[i]["interval"] == "1" ? "上午" : "下午");
            cout << " 机房：" << of.orderData[i]["roomId"];

            // 0 取消的预约，1 审核中，2 已预约，-1 预约失败
            string status = " 状态： ";
            if (of.orderData[i]["status"] == "1")
            {
                status += "审核中";
            }
            else if (of.orderData[i]["status"] == "2")
            {
                status += "预约成功";
            }
            else if (of.orderData[i]["status"] == "-1")
            {
                status += "审核未通过，预约失败";
            }
            else
            {
                status += "预约已取消";
            }
            cout << status << endl;
        }
    }
}

// 查看所有预约
void Student::showAllOrder()
{
    OrderFile of;
    if (of.size == 0)
    {
        cout << "无预约记录" << endl;
        return;
    }

    for (int i = 0; i < of.size; i++)
    {
        cout << i + 1 << "、 ";
        cout << "预约日期： 周" << of.orderData[i]["date"];
        cout << " 时段：" << (of.orderData[i]["interval"] == "1" ? "上午" : "下午");
        cout << " 学号：" << of.orderData[i]["stuId"];
        cout << " 姓名：" << of.orderData[i]["stuName"];
        cout << " 机房：" << of.orderData[i]["roomId"];

        // 0 取消的预约，1 审核中，2 已预约，-1 预约失败
        string status = " 状态： ";
        if (of.orderData[i]["status"] == "1")
        {
            status += "审核中";
        }
        else if (of.orderData[i]["status"] == "2")
        {
            status += "预约成功";
        }
        else if (of.orderData[i]["status"] == "-1")
        {
            status += "审核未通过，预约失败";
        }
        else
        {
            status += "预约已取消";
        }
        cout << status << endl;
    }
}

// 取消预约
void Student::canceOrder()
{
    OrderFile of;
    if (of.size == 0)
    {
        cout << "无预约记录" << endl;
        return;
    }
    cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;

    vector<int> v;
    int index = 1;
    for (int i = 0; i < of.size; i++)
    {
        if (atoi(of.orderData[i]["stuId"].c_str()) == this->studentId)
        {
            if (of.orderData[i]["status"] == "1" || of.orderData[i]["status"] == "2")
            {
                v.push_back(i);
                cout << index++ << "、 ";
                cout << "预约日期： 周" << of.orderData[i]["date"];
                cout << " 时段：" << (of.orderData[i]["interval"] == "1" ? "上午" : "下午");
                cout << " 机房：" << of.orderData[i]["roomId"];

                // 0 取消的预约，1 审核中，2 已预约，-1 预约失败
                string status = " 状态： ";
                if (of.orderData[i]["status"] == "1")
                {
                    status += "审核中";
                }
                else if (of.orderData[i]["status"] == "2")
                {
                    status += "预约成功";
                }
                cout << status << endl;
            }
        }
    }

    cout << "请输入取消的记录，0 代表返回" << endl;
    int select = 0;
    while (true)
    {
        cin >> select;
        if (select >= 0 && select <= v.size())
        {
            if (select == 0)
            {
                break;
            }
            else
            {
                // cout << "记录所在位置： " << v[select - 1] << endl;
                of.orderData[v[select - 1]]["status"] = "0";
                of.updateOrder();
                cout << "已取消预约" << endl;
                break;
            }
        }
        cout << "输入有误，请重新输入" << endl;
    }
}