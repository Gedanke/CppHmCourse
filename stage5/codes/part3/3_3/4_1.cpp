#include <iostream>
#include <deque>

using namespace std;

void printDeque(const deque<int> &d)
{
    for (auto it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 大小操作
void test1()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    // 判断容器是否为空
    if (d1.empty())
    {
        cout << "d1 为空!" << endl;
    }
    else
    {
        cout << "d1 不为空!" << endl;
        // 统计大小
        cout << "d1 的大小为：" << d1.size() << endl;
    }

    // 重新指定大小
    d1.resize(15, 1);
    printDeque(d1);

    d1.resize(5);
    printDeque(d1);
}

int main()
{
    test1();

    /*
        0 1 2 3 4 5 6 7 8 9
        d1 不为空!
        d1 的大小为：10
        0 1 2 3 4 5 6 7 8 9 1 1 1 1 1
        0 1 2 3 4
    */

    return 0;
}
