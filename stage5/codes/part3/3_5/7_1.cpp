#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void printList(const list<int> &L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

bool myCompare(int val1, int val2)
{
    return val1 > val2;
}

// 反转和排序
void test1()
{
    list<int> L;
    L.push_back(90);
    L.push_back(30);
    L.push_back(20);
    L.push_back(70);
    printList(L);

    // 反转容器的元素
    L.reverse();
    printList(L);

    // 排序
    L.sort(); // 默认的排序规则 从小到大
    printList(L);

    L.sort(myCompare); // 指定规则，从大到小
    printList(L);

    // sort(L.begin(), L.end()); // error
}

int main()
{
    test1();

    /*
        90 30 20 70
        70 20 30 90
        20 30 70 90
        90 70 30 20
    */

    return 0;
}