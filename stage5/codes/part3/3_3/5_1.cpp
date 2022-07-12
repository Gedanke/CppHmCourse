#include <iostream>
#include <deque>

using namespace std;

void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 两端操作
void test1()
{
    deque<int> d;
    // 尾插
    d.push_back(10);
    d.push_back(20);
    // 头插
    d.push_front(100);
    d.push_front(200);

    printDeque(d);

    // 尾删
    d.pop_back();
    // 头删
    d.pop_front();
    printDeque(d);
}

// 插入
void test2()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);
    printDeque(d);

    d.insert(d.begin(), 1000);
    printDeque(d);

    d.insert(d.begin(), 2, 10000);
    printDeque(d);

    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d.insert(d.begin() + 1, d2.begin(), d2.end());
    printDeque(d);
}

// 删除
void test3()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);
    printDeque(d);

    d.erase(d.begin());
    printDeque(d);

    d.erase(d.begin(), d.end() - 1);
    printDeque(d);

    d.clear();
    printDeque(d);
}

int main()
{
    test1();
    cout << "=========" << endl;
    test2();
    cout << "=========" << endl;
    test3();

    /*
        200 100 10 20
        100 10
        =========
        200 100 10 20
        1000 200 100 10 20
        10000 10000 1000 200 100 10 20
        10000 1 2 3 10000 1000 200 100 10 20
        =========
        200 100 10 20
        100 10 20
        20

    */

    return 0;
}