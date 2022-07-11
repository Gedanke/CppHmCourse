#include <iostream>

using namespace std;

// 查找和替换
void test1()
{
    // 查找
    string str1 = "abcdefgde";
    int pos = str1.find("de");

    if (pos == -1)
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "pos = " << pos << endl;
    }

    pos = str1.rfind("de");

    cout << "pos = " << pos << endl;
}

void test2()
{
    // 替换
    string str1 = "abcdefgde";
    str1.replace(1, 3, "1111");

    cout << "str1 = " << str1 << endl;
}

int main()
{
    test1();
    test2();

    /*
        pos = 3
        pos = 7
        str1 = a1111efgde
    */

    return 0;
}