#include <iostream>

using namespace std;

// 学生结构体定义
struct student
{
    // 成员列表
    string name; // 姓名
    int age;     // 年龄
    int score;   // 分数
};

// const 使用场景
void printStudent(const student *stu) // 加 const 防止函数体中的误操作
{
    // stu->age = 100; // 操作失败，因为加了 const 修饰
    cout << "姓名：" << stu->name << " 年龄：" << stu->age << " 分数：" << stu->score << endl;
}

int main()
{
    student stu = {"张三", 18, 100};
    printStudent(&stu);

    /*
        姓名：张三 年龄：18 分数：100
    */

    return 0;
}