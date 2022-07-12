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

// 插入和删除
void test1()
{
    list<int> L;
    // 尾插
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    // 头插
    L.push_front(100);
    L.push_front(200);
    L.push_front(300);

    printList(L);

    // 尾删
    L.pop_back();
    printList(L);

    // 头删
    L.pop_front();
    printList(L);

    // 插入
    list<int>::iterator it = L.begin();
    ++it;
    auto postion = L.insert(it, 1000);
    cout << *postion << endl;
    printList(L);

    // 删除
    it = L.begin();
    // it = it + 1; // 没有与这些操作数匹配的 "+" 运算符
    it++;
    L.erase(it);
    printList(L);

    // 移除
    L.push_back(10000);
    L.push_back(10000);
    L.push_back(10000);
    printList(L);
    L.remove(10000);
    printList(L);

    // 清空
    L.clear();
    printList(L);
}

int main()
{
    test1();

    /*
        300 200 100 10 20 30
        300 200 100 10 20
        200 100 10 20
        1000
        200 1000 100 10 20
        200 100 10 20
        200 100 10 20 10000 10000 10000
        200 100 10 20

    */

    return 0;
}