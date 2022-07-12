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

// 数据存取
void test1()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);

    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < d.size(); i++)
    {
        cout << d.at(i) << " ";
    }
    cout << endl;

    cout << d[4] << endl; // 越界不会报错
    // cout << d.at(4) << endl;

    cout << "front: " << d.front() << endl;
    cout << "back: " << d.back() << endl;
}

int main()
{
    test1();

    /*
        200 100 10 20
        200 100 10 20
        0
        front: 200
        back: 20
    */

    return 0;
}