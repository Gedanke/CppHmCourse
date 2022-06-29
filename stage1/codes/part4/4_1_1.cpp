#include <iostream>

using namespace std;

int main()
{

    // 选择结构-单行 if 语句
    // 输入一个分数，如果分数大于 600 分，视为考上好大学，并在屏幕上打印

    int score = 0;
    cout << "请输入一个分数：" << endl;
    cin >> score;

    cout << "您输入的分数为： " << score << endl;

    // if 语句
    // 注意事项，在 if 判断语句后面，不要加分号
    if (score > 600)
    {
        cout << "我考上了好大学！！！" << endl;
    }

    /*
        请输入一个分数：
        598
        您输入的分数为： 598

        请输入一个分数：
        601
        您输入的分数为： 601
        我考上了好大学！！！
    */

    return 0;
}