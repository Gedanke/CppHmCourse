#include <iostream>

using namespace std;

int main()
{

    int score = 0;
    cout << "请输入考试分数：" << endl;
    cin >> score;

    if (score > 600)
    {
        cout << "我考上了好大学" << endl;
    }
    else
    {
        cout << "我未考上好大学" << endl;
    }

    /*
        请输入考试分数：
        589
        我未考上好大学
        请输入考试分数：
        602
        我考上了好大学
    */

    return 0;
}