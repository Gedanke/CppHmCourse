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

// 赋值和交换
void test1()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);

    // 赋值
    list<int> L2;
    L2 = L1;
    printList(L2);

    list<int> L3;
    L3.assign(L2.begin(), L2.end());
    printList(L3);

    list<int> L4;
    L4.assign(10, 100);
    printList(L4);
}

// 交换
void test2()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    list<int> L2;
    L2.assign(10, 100);
    cout << "交换前：" << endl;
    printList(L1);
    printList(L2);

    L1.swap(L2);
    cout << "交换后：" << endl;
    printList(L1);
    printList(L2);
}

int main()
{
    test1();
    cout << "=========" << endl;
    test2();

    /*
        10 20 30 40
        10 20 30 40
        10 20 30 40
        100 100 100 100 100 100 100 100 100 100
        =========
        交换前：
        10 20 30 40
        100 100 100 100 100 100 100 100 100 100
        交换后：
        100 100 100 100 100 100 100 100 100 100
        10 20 30 40
    */

    return 0;
}