#include <iostream>
#include <map>

using namespace std;

void printMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    cout << "=======" << endl;
}

void test1()
{
    // 插入
    map<int, int> m{{0, 0}};

    // 第一种插入方式
    m.insert(pair<int, int>(1, 10));

    // 第二种插入方式
    m.insert(make_pair(2, 20));

    // 第三种插入方式
    m.insert(map<int, int>::value_type(3, 30));

    // 第四种插入方式
    m[4] = 40;
    // cout << m[5] << endl; // [] 不建议插入，可以用 key 访问到 value
    cout << m[4] << endl;

    printMap(m);

    // 删除
    m.erase(m.begin());
    printMap(m);

    m.erase(3);
    printMap(m);

    m.erase(++m.begin(), --m.end());
    printMap(m);

    // 清空
    m.clear();
    printMap(m);
}

int main()
{
    test1();

    /*
        40
        key = 0 value = 0
        key = 1 value = 10
        key = 2 value = 20
        key = 3 value = 30
        key = 4 value = 40
        =======
        key = 1 value = 10
        key = 2 value = 20
        key = 3 value = 30
        key = 4 value = 40
        =======
        key = 1 value = 10
        key = 2 value = 20
        key = 4 value = 40
        =======
        key = 1 value = 10
        key = 4 value = 40
        =======
        =======
    */

    return 0;
}