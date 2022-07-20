#include <iostream>
#include <fstream>
#include "globalFile.h"
#include "identity.h"
#include "manager.h"
#include "student.h"
#include "teacher.h"

using namespace std;

// 主界面
void showMain();
// 登录功能
void loginIn(string fileName, int type);
// 管理员菜单
void managerMenu(Identity *&manager);
// 学生菜单
void studentMenu(Identity *&student);
// 教师菜单
void teacherMenu(Identity *&teacher);

int main()
{
	int select = 0;

	while (true)
	{
		showMain();

		cin >> select;

		switch (select)
		{
		case 0:
		{
			// 退出系统
			cout << "欢迎下次使用!" << endl;
			return 0;
		}
		case 1:
		{
			// 学生身份
			loginIn(STUDENT_FILE, 1);
			break;
		}
		case 2:
		{
			// 教师身份
			loginIn(TEACHER_FILE, 2);
			break;
		}
		case 3:
		{
			// 管理员身份
			loginIn(ADMIN_FILE, 3);
			break;
		}
		default:
		{
			cout << "输入有误，请重新输入!" << endl;
			// system("clear");
			break;
		}
		}
	}

	/*
	 */

	return 0;
}

void showMain()
{
	cout << "=====================  欢迎来到机房预约系统  ====================" << endl;
	cout << endl;
	cout << "请输入您的身份" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.学生代表           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.老    师           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.管 理 员           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.退    出           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "输入您的选择: " << endl;
}

void loginIn(string fileName, int type)
{
	Identity *person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	// 文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string password;

	if (type == 1)
	{
		// 学生
		cout << "请输入学生学号:" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		// 教师
		cout << "请输入教职工号:" << endl;
		cin >> id;
	}
	else
	{
	}

	cout << "请输入用户名:" << endl;
	cin >> name;
	cout << "请输入密码:" << endl;
	cin >> password;

	if (type == 1)
	{
		// 学生登陆验证
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && password == fPwd)
			{
				cout << "学生登陆验证成功!" << endl;
				person = new Student(id, name, password);
				// 进入学生子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		// 教师登陆验证
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && password == fPwd)
			{
				cout << "教师登陆验证成功!" << endl;
				person = new Teacher(id, name, password);

				// 进入教师子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else
	{
		// 管理员登陆验证
		string fName;
		string fPwd;

		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && password == fPwd)
			{
				cout << "管理员登陆验证成功!" << endl;
				person = new Manager(name, password);
				// 进入管理员子菜单
				managerMenu(person);
				return;
			}
		}
	}

	ifs.close();
	cout << "验证登录失败!" << endl;
}

// 管理员菜单
void managerMenu(Identity *&manager)
{
	while (true)
	{
		// 管理员菜单
		manager->operMenu();

		Manager *man = (Manager *)manager;
		int select = -1;
		cin >> select;

		if (select == 1)
		{
			// 添加账号
			cout << "添加账号" << endl;
			man->addAccount();
		}
		else if (select == 2)
		{
			// 查看账号
			cout << "查看账号" << endl;
			man->showAccount();
		}
		else if (select == 3)
		{
			// 查看机房
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			// 清空预约
			cout << "清空预约" << endl;
			man->cleanRecord();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			return;
		}
	}
}

// 学生菜单
void studentMenu(Identity *&student)
{
	while (true)
	{
		// 学生菜单
		student->operMenu();

		Student *stu = (Student *)student;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			// 申请预约
			stu->applyOrder();
		}
		else if (select == 2)
		{
			// 查看自身预约
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			// 查看所有预约
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			// 取消预约
			stu->canceOrder();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			return;
		}
	}
}

// 教师菜单
void teacherMenu(Identity *&teacher)
{
	while (true)
	{
		// 教师菜单
		teacher->operMenu();

		Teacher *tea = (Teacher *)teacher;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			// 查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			// 审核预约
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			return;
		}
	}
}

//