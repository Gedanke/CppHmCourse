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

// 插入和删除
void test1()
{
    set<int> s1{10, 20, 30, 60, 50, 40};

    s1.insert(40);
    printSet(s1);

    // 删除
    s1.erase(s1.begin());
    printSet(s1);

    s1.erase(30);
    printSet(s1);

    // 清空
    s1.erase(++s1.begin(), --s1.end());
    printSet(s1);

    s1.clear();
    printSet(s1);
}

int main()
{
    test1();

    /*
        10 20 30 40 50 60
        20 30 40 50 60
        20 40 50 60
        20 60

    */

    return 0;
}