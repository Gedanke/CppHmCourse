#include <iostream>

using namespace std;

int main()
{
    // 定义方式 1
    // 数据类型 数组名[元素个数];
    int score[10];

    // 利用下标赋值
    score[0] = 100;
    score[1] = 99;
    score[2] = 85;

    // 利用下标输出
    cout << score[0] << endl;
    cout << score[1] << endl;
    cout << score[2] << endl;

    // 定义方式 2
    // 数据类型 数组名[元素个数] = {值 1, 值 2, 值 3, ...};
    // 如果 {} 内不足 10 个数据，剩余数据用 0 补全
    int score2[10] = {100, 90, 80, 70, 60, 50, 40, 30};

    // 逐个输出
    // cout << score2[0] << endl;
    // cout << score2[1] << endl;

    // 一个一个输出太麻烦，因此可以利用循环进行输出
    for (int i = 0; i < 10; i++)
    {
        cout << score2[i] << endl;
    }

    // 定义方式 3
    // 数据类型 数组名[] = {值 1, 值 2, 值 3, ...};
    int score3[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};

    for (int i = 0; i < 10; i++)
    {
        cout << score3[i] << endl;
    }

    /*
        100
        99
        85
        100
        90
        80
        70
        60
        50
        40
        30
        0
        0
        100
        90
        80
        70
        60
        50
        40
        30
        20
        10
    */

    return 0;
}