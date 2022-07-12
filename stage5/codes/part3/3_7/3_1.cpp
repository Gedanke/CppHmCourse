#include <iostream>
#include <map>

using namespace std;

void printMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
}

void test1()
{
    map<int, int> m{{0, 0}};
    m[4] = 40;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    if (m.empty())
    {
        cout << "m 为空" << endl;
    }
    else
    {
        cout << "m 不为空" << endl;
        cout << "m 的大小为：" << m.size() << endl;
    }
}

// 交换
void test2()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    map<int, int> m2;
    m2.insert(pair<int, int>(4, 100));
    m2.insert(pair<int, int>(5, 200));
    m2.insert(pair<int, int>(6, 300));

    cout << "交换前" << endl;
    printMap(m);
    printMap(m2);

    cout << "交换后" << endl;
    m.swap(m2);
    printMap(m);
    printMap(m2);
}

int main()
{
    test1();
    cout << "=========" << endl;
    test2();

    /*
        m 不为空
        m 的大小为：5
        =========
        交换前
        key = 1 value = 10
        key = 2 value = 20
        key = 3 value = 30
        key = 4 value = 100
        key = 5 value = 200
        key = 6 value = 300
        交换后
        key = 4 value = 100
        key = 5 value = 200
        key = 6 value = 300
        key = 1 value = 10
        key = 2 value = 20
        key = 3 value = 30
    */

    return 0;
}