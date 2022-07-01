#include <iostream>

using namespace std;

// 结构体定义
struct student
{
    // 成员列表
    string name; // 姓名
    int age;     // 年龄
    int score;   // 分数
} stu3;          // 结构体变量创建方式 3

int main()
{
    // 结构体变量创建方式 1
    struct student stu1; // struct 关键字可以省略

    stu1.name = "张三";
    stu1.age = 18;
    stu1.score = 100;

    cout << "姓名：" << stu1.name << " 年龄：" << stu1.age << " 分数：" << stu1.score << endl;

    // 结构体变量创建方式 2
    struct student stu2 = {"李四", 19, 60};

    cout << "姓名：" << stu2.name << " 年龄：" << stu2.age << " 分数：" << stu2.score << endl;

    stu3.name = "王五";
    stu3.age = 18;
    stu3.score = 80;

    cout << "姓名：" << stu3.name << " 年龄：" << stu3.age << " 分数：" << stu3.score << endl;

    /*
        姓名：张三 年龄：18 分数：100
        姓名：李四 年龄：19 分数：60
        姓名：王五 年龄：18 分数：80
    */

    return 0;
}