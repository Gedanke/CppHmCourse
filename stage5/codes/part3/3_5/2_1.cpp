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

void test1()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    printList(L1);

    // list<int>L2(L1.begin() + 1, L1.end() - 1); // 没有与这些操作数匹配的 "+" 运算符C/C++(349)
    list<int> L2(L1.begin(), L1.end());
    printList(L2);

    list<int> L3(L2);
    printList(L3);

    list<int> L4(10, 1000);
    printList(L4);
}

int main()
{
    test1();

    /*
        10 20 30 40
        10 20 30 40
        10 20 30 40
        1000 1000 1000 1000 1000 1000 1000 1000 1000 1000
    */

    return 0;
}