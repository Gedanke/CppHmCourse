#include <iostream>
#include <list>

using namespace std;

void printList(const list<int> &L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 大小操作
void test1()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    if (L1.empty())
    {
        cout << "L1 为空" << endl;
    }
    else
    {
        cout << "L1 不为空" << endl;
        cout << "L1 的大小为：" << L1.size() << endl;
    }

    // 重新指定大小
    L1.resize(10);
    printList(L1);

    L1.resize(2);
    printList(L1);
}

int main()
{
    test1();

    /*
        L1 不为空
        L1 的大小为：4
        10 20 30 40 0 0 0 0 0 0
        10 20
    */

    return 0;
}