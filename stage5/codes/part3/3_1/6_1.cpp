#include <iostream>

using namespace std;

// 字符串比较
void test1()
{
    string s1 = "hello";
    string s2 = "aello";

    int ret = s1.compare(s2);

    if (ret == 0)
    {
        cout << "s1 等于 s2" << endl;
    }
    else if (ret > 0)
    {
        cout << "s1 大于 s2" << endl;
    }
    else
    {
        cout << "s1 小于 s2" << endl;
    }
}

int main()
{
    test1();

    /*
        s1 大于 s2
    */

    return 0;
}