#include <iostream>
#include <set>

using namespace std;

// set 和 multiset 区别
void test1()
{
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);
    if (ret.second)
    {
        cout << "第一次插入成功!" << endl;
    }
    else
    {
        cout << "第一次插入失败!" << endl;
    }

    ret = s.insert(10);
    if (ret.second)
    {
        cout << "第二次插入成功!" << endl;
    }
    else
    {
        cout << "第二次插入失败!" << endl;
    }

    // multiset
    multiset<int> ms;
    ms.insert(10);
    auto p = ms.insert(10);
    cout << *p << endl;

    for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    test1();

    /*
        第一次插入成功!
        第二次插入失败!
        10
        10 10
    */

    return 0;
}