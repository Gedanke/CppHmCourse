#include <iostream>
#include "speechManager.h"

using namespace std;

void test();

int main()
{
	SpeechManager sp;
	// test
	// for (auto it = sp.speakers.begin(); it != sp.speakers.end(); it++)
	// {
	// 	cout << "选手编号：" << it->first
	// 		 << " 姓名： " << it->second.name
	// 		 << " 成绩： " << it->second.score[0] << endl;
	// }

	// 用来存储用户的选项
	int choice = 0;
	while (true)
	{
		sp.showMenu();
		cout << "请输入您的选择： " << endl;
		// 接受用户的选项
		cin >> choice;

		switch (choice)
		{
		case 1:
			// 开始比赛
			sp.startSpeech();
			break;
		case 2:
			// 查看记录
			sp.showRecord();
			break;
		case 3:
			// 清空记录
			sp.clearRecord();
			break;
		case 0:
			// 退出系统
			sp.exitSystem();
			break;
		default:
			// 清屏
			break;
		}
	}

	/*
	 */

	return 0;
}
