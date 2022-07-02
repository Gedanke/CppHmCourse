#include "mine.h"

// mine.cpp 文件

void showMenu()
{
    cout << "***************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "***************************" << endl;
    cout << "* 请按上述提示输入一个数字 *" << endl;
}

void addPerson(AddressBook *abs)
{
    // 判断电话本是否满了
    if (abs->size >= MAX)
    {
        cout << "通讯录已满，无法添加!" << endl;
        return;
    }
    else
    {
        // 姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[abs->size].name = name;

        cout << "请输入性别：" << endl;
        cout << "1 -- 男" << endl;
        cout << "2 -- 女" << endl;

        // 性别
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->size].sex = sex;
                break;
            }
            cout << "输入有误，请重新输入";
        }

        // 年龄
        cout << "请输入年龄：" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->size].age = age;

        // 联系电话
        cout << "请输入联系电话：" << endl;
        string phone = "";
        cin >> phone;
        abs->personArray[abs->size].phone = phone;

        // 家庭住址
        cout << "请输入家庭住址：" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->size].address = address;

        // 更新通讯录人数
        abs->size++;

        cout << "添加成功" << endl;

        // linux
        // system("clear");
        // windows
        // system("cls");
    }
}

void showPerson(const AddressBook *abs)
{
    if (abs->size <= 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs->size; i++)
        {
            cout << "姓名：" << abs->personArray[i].name << "\t";
            cout << "性别：" << (abs->personArray[i].sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personArray[i].age << "\t";
            cout << "电话：" << abs->personArray[i].phone << "\t";
            cout << "住址：" << abs->personArray[i].address << endl;
        }
    }
}

int isExist(const AddressBook *abs, string name)
{
    for (int i = 0; i < abs->size; i++)
    {
        if (abs->personArray[i].name == name)
        {
            return i;
        }
    }
    return -1;
}

void deletePerson(AddressBook *abs)
{
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        for (int i = ret; i < abs->size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->size--;
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
}

void findPerson(const AddressBook *abs)
{
    cout << "请输入您要查找的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名：" << abs->personArray[ret].name << "\t";
        cout << "性别：" << abs->personArray[ret].sex << "\t";
        cout << "年龄：" << abs->personArray[ret].age << "\t";
        cout << "电话：" << abs->personArray[ret].phone << "\t";
        cout << "住址：" << abs->personArray[ret].address << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
}

void modifyPerson(AddressBook *abs)
{
    cout << "请输入您要修改的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        // 姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[ret].name = name;

        cout << "请输入性别：" << endl;
        cout << "1 -- 男" << endl;
        cout << "2 -- 女" << endl;

        // 性别
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].sex = sex;
                break;
            }
            cout << "输入有误，请重新输入";
        }

        // 年龄
        cout << "请输入年龄：" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[ret].age = age;

        // 联系电话
        cout << "请输入联系电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].phone = phone;

        // 家庭住址
        cout << "请输入家庭住址：" << endl;
        string address;
        cin >> address;
        abs->personArray[ret].address = address;

        cout << "修改成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
}

void cleanPerson(AddressBook *abs)
{
    abs->size = 0;
    cout << "通讯录已清空" << endl;
}

void deal(AddressBook *abs)
{
    int select = -1;
    while (true)
    {
        showMenu();
        cin >> select;
        switch (select)
        {
        case 1:
            // 添加联系人
            addPerson(abs);
            break;
        case 2:
            // 显示联系人
            showPerson(abs);
            break;
        case 3:
            // 删除联系人
            deletePerson(abs);
            break;
        case 4:
            // 查找联系人
            findPerson(abs);
            break;
        case 5:
            // 修改联系人
            modifyPerson(abs);
            break;
        case 6:
            // 清空联系人
            cleanPerson(abs);
            break;
        case 0:
            // 退出通讯录
            cout << "欢迎下次使用!" << endl;
            return;
            break;
        default:
            break;
        }
    }
}