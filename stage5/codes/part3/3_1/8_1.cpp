#include <iostream>

using namespace std;

// 字符串插入和删除
void test1()
{
    string str = "hello";
    str.insert(1, "111");
    str.insert(1, 3, '1');
    cout << str << endl;

    // 从 1 号位置开始 3 个字符
    str.erase(1, 6);
    cout << str << endl;
}

int main()
{
    test1();

    /*
        h111111ello
        hello
    */

    return 0;
}