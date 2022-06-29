#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    // 随机种子
    srand((unsigned)time(NULL));
    // [0, 100] 的随机数
    int res = (rand() % (100 - 1 + 1)) + 1;
    cout << "res = " << res << endl;

    int c = -1;
    while (c != res)
    {
        cout << "输入你的答案:" << endl;
        cin >> c;
        if (c > res)
        {
            cout << "你的答案过大" << endl;
        }
        else if (c < res)
        {
            cout << "你的答案过小" << endl;
        }
        else
        {
            cout << "你的答案正确" << endl;
        }
    }

    /*
        res = 43
        输入你的答案:
        50
        你的答案过大
        输入你的答案:
        25
        你的答案过小
        输入你的答案:
        37
        你的答案过小
        输入你的答案:
        42
        你的答案过小
        输入你的答案:
        47
        你的答案过大
        输入你的答案:
        45
        你的答案过大
        输入你的答案:
        44
        你的答案过大
        输入你的答案:
        43
        你的答案正确
    */

    return 0;
}