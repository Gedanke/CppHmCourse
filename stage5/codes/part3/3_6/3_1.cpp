#include <iostream>
#include <set>

using namespace std;

void printSet(set<int> &s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 大小
void test1()
{
    set<int> s1;

    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    if (s1.empty())
    {
        cout << "s1 为空" << endl;
    }
    else
    {
        cout << "s1 不为空" << endl;
        cout << "s1 的大小为：" << s1.size() << endl;
    }
}

// 交换
void test2()
{
    set<int> s1;

    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    set<int> s2;

    s2.insert(100);
    s2.insert(300);
    s2.insert(200);
    s2.insert(400);

    cout << "交换前" << endl;
    printSet(s1);
    printSet(s2);

    cout << "交换后" << endl;
    s1.swap(s2);
    printSet(s1);
    printSet(s2);
}

int main()
{
    test1();
    test2();

    /*
        s1 不为空
        s1 的大小为：4
        交换前
        10 20 30 40
        100 200 300 400
        交换后
        100 200 300 400
        10 20 30 40
    */

    return 0;
}