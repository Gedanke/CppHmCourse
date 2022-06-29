#include <iostream>

using namespace std;

int main()
{
    // 1、在 switch 语句中使用 break
    cout << "请选择您挑战副本的难度：" << endl;
    cout << "1、普通" << endl;
    cout << "2、中等" << endl;
    cout << "3、困难" << endl;

    int num = 0;
    cin >> num;

    switch (num)
    {
    case 1:
        cout << "您选择的是普通难度" << endl;
        break;
    case 2:
        cout << "您选择的是中等难度" << endl;
        break;
    case 3:
        cout << "您选择的是困难难度" << endl;
        break;
    }

    /*
        请选择您挑战副本的难度：
        1、普通
        2、中等
        3、困难
        2
        您选择的是中等难度
    */

    return 0;
}