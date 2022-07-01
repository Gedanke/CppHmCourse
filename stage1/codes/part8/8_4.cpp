#include <iostream>

using namespace std;

// 结构体定义
struct student
{
    // 成员列表
    string name; // 姓名
    int age;     // 年龄
    int score;   // 分数
};

int main()
{
    struct student stu = {
        "张三",
        18,
        100,
    };
    struct student *p = &stu;

    p->score = 80; // 指针通过 -> 操作符可以访问成员
    cout << "姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;

    /*
        姓名：张三 年龄：18 分数：80
    */

    return 0;
}