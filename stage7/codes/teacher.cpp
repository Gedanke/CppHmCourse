#include "teacher.h"

// 无参构造
Teacher::Teacher()
{
}

// 有参构造
Teacher::Teacher(int teacherId, string name, string password)
{
    // 初始化属性
    this->teacherId = teacherId;
    this->name = name;
    this->password = password;
}

// teacherId 的 get 的方法
int Teacher::getTeacherId()
{
    return this->teacherId;
}

// teacherId 的 set 的方法
void Teacher::setTeacherId(int teacherId)
{
    this->teacherId = teacherId;
}

// 菜单界面
void Teacher::operMenu()
{
    cout << "欢迎教师：" << this->name << "登录！" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          1.查看所有预约          |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          2.审核预约              |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          0.注销登录              |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t ----------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

// 查看所有预约
void Teacher::showAllOrder()
{
    OrderFile of;
    if (of.size == 0)
    {
        cout << "无预约记录" << endl;
        system("pause");
        system("cls");
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

// 审核预约
void Teacher::validOrder()
{
    OrderFile of;
    if (of.size == 0)
    {
        cout << "无预约记录" << endl;
        return;
    }
    cout << "待审核的预约记录如下：" << endl;

    vector<int> v;
    int index = 0;
    for (int i = 0; i < of.size; i++)
    {
        if (of.orderData[i]["status"] == "1")
        {
            v.push_back(i);
            cout << ++index << "、 ";
            cout << "预约日期： 周" << of.orderData[i]["date"];
            cout << " 时段：" << (of.orderData[i]["interval"] == "1" ? "上午" : "下午");
            cout << " 机房：" << of.orderData[i]["roomId"];

            // 0 取消的预约，1 审核中，2 已预约，-1 预约失败
            string status = " 状态： ";
            if (of.orderData[i]["status"] == "1")
            {
                status += "审核中";
            }
            cout << status << endl;
        }
    }
    cout << "请输入审核的预约记录，0 代表返回" << endl;

    int select = 0;
    int ret = 0;
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
                cout << "请输入审核结果" << endl;
                cout << "1、通过" << endl;
                cout << "2、不通过" << endl;
                cin >> ret;

                if (ret == 1)
                {
                    of.orderData[v[select - 1]]["status"] = "2";
                }
                else
                {
                    of.orderData[v[select - 1]]["status"] = "-1";
                }
                of.updateOrder();
                cout << "审核完毕！" << endl;
                break;
            }
        }
        cout << "输入有误，请重新输入" << endl;
    }
}