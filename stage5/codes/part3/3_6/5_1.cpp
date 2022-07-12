#include <iostream>
#include <set>

using namespace std;

// 查找和统计
void test1()
{
    set<int> s1{10, 20, 30, 30, 30, 50, 40};

    // 查找
    set<int>::iterator pos = s1.find(30);

    if (pos != s1.end())
    {
        cout << "找到了元素：" << *pos << endl;
    }
    else
    {
        cout << "未找到元素" << endl;
    }

    // 统计
    int num = s1.count(30);
    cout << "num = " << num << endl;
}

int main()
{
    test1();

    /*
        找到了元素：30
        num = 1
    */

    return 0;
}