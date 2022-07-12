#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

// 按 key
bool compareKey(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return p1.first > p2.first;
}

// 按 value
bool compareValue(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return p1.second > p2.second;
}

void test1()
{
    // 默认从小到大排序
    // 利用仿函数实现从大到小排序
    map<int, int, MyCompare> m;

    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));
    m.insert(make_pair(4, 40));
    m.insert(make_pair(5, 50));

    for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key: " << it->first << " value: " << it->second << endl;
    }

    cout << "=========" << endl;

    cout << "对现有的 map 进行按 key 或者 value 排序" << endl;

    map<int, int> mine{{1, 50}, {2, 40}, {3, 30}, {4, 20}, {5, 10}};
    vector<pair<int, int>> v(mine.begin(), mine.end());

    sort(v.begin(), v.end(), compareKey);
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << "key: " << it->first << " value: " << it->second << endl;
    }

    cout << "=========" << endl;

    sort(v.begin(), v.end(), compareValue);

    map<int, int> mm(v.begin(), v.end());
    for (auto it = mm.begin(); it != mm.end(); it++)
    {
        cout << "key: " << it->first << " value: " << it->second << endl;
    }
}

int main()
{
    test1();

    /*
        key: 5 value: 50
        key: 4 value: 40
        key: 3 value: 30
        key: 2 value: 20
        key: 1 value: 10
        =========
        对现有的 map 进行按 key 或者 value 排序
        key: 5 value: 10
        key: 4 value: 20
        key: 3 value: 30
        key: 2 value: 40
        key: 1 value: 50
        =========
        key: 1 value: 50
        key: 2 value: 40
        key: 3 value: 30
        key: 4 value: 20
        key: 5 value: 10
    */

    return 0;
}