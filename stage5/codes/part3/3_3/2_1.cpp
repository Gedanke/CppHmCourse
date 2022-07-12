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

// deque 构造
void test1()
{
    // 无参构造函数
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int> d2(d1.begin() + 1, d1.end() - 1);
    printDeque(d2);

    deque<int> d3(10, 100);
    printDeque(d3);

    deque<int> d4 = d3;
    printDeque(d4);
}

int main()
{
    test1();

    /*
        0 1 2 3 4 5 6 7 8 9
        1 2 3 4 5 6 7 8
        100 100 100 100 100 100 100 100 100 100
        100 100 100 100 100 100 100 100 100 100
    */

    return 0;
}
