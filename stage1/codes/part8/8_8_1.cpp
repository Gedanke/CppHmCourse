#include <iostream>

using namespace std;

struct Student
{
    string name;
    int score;
};

struct Teacher
{
    string name;
    Student sArray[5];
};

void allocateSpace(Teacher tArray[], int len)
{
    string tName = "教师";
    string sName = "学生";
    string nameSeed = "ABCDE";
    for (int i = 0; i < len; i++)
    {
        tArray[i].name = tName + nameSeed[i];
        for (int j = 0; j < 5; j++)
        {
            tArray[i].sArray[j].name = sName + nameSeed[j];
            tArray[i].sArray[j].score = rand() % 61 + 40;
        }
    }
}

void printTeachers(Teacher tArray[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << tArray[i].name << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "\t姓名：" << tArray[i].sArray[j].name << " 分数：" << tArray[i].sArray[j].score << endl;
        }
    }
}

int main()
{
    srand((unsigned int)time(NULL)); // 随机数种子 头文件 #include<ctime>

    Teacher tArray[3]; // 老师数组
    int len = sizeof(tArray) / sizeof(Teacher);
    allocateSpace(tArray, len); // 创建数据
    printTeachers(tArray, len); // 打印数据

    /*
        教师A
                姓名：学生A 分数：47
                姓名：学生B 分数：90
                姓名：学生C 分数：69
                姓名：学生D 分数：56
                姓名：学生E 分数：43
        教师B
                姓名：学生A 分数：88
                姓名：学生B 分数：40
                姓名：学生C 分数：55
                姓名：学生D 分数：57
                姓名：学生E 分数：84
        教师C
                姓名：学生A 分数：58
                姓名：学生B 分数：79
                姓名：学生C 分数：47
                姓名：学生D 分数：94
                姓名：学生E 分数：70
    */

    return 0;
}