#include <iostream>

using namespace std;

// 字符串拼接
void test1()
{
    string str1 = "我";
    str1 += "爱玩游戏";
    cout << "str1 = " << str1 << endl;

    str1 += ':';
    cout << "str1 = " << str1 << endl;

    string str2 = " MC GTA5";
    str1 += str2;
    cout << "str1 = " << str1 << endl;

    string str3 = "I";
    str3.append(" love ");
    str3.append("game abcde", 5);
    // str3.append(str2);
    str3.append(str2, 4, 4); // 从下标 4 位置开始，截取 4 个字符，拼接到字符串末尾
    cout << "str3 = " << str3 << endl;
}

int main()
{
    test1();

    /*
        str1 = 我爱玩游戏
        str1 = 我爱玩游戏:
        str1 = 我爱玩游戏: MC GTA5
        str3 = I love game GTA5
    */

    return 0;
}