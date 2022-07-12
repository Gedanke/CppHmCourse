#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test1()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);

    printDeque(d);
    sort(d.begin(), d.end());
    printDeque(d);
}

int main()
{
    test1();

    /*
        200 100 10 20
        10 20 100 200
    */

    return 0;
}