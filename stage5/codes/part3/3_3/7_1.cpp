#include <iostream>
#include <deque>

using namespace std;

void show(const deque<int> &d)
{
    for (auto it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    deque<int> d1{1, 2, 3};
    deque<int> d2{4, 5, 6};
    show(d1);
    show(d2);

    cout << "d1.swap(d2)" << endl;
    d1.swap(d2);
    show(d1);
    show(d2);

    cout << "swap(d1, d2)" << endl;
    swap(d1, d2);
    show(d1);
    show(d2);

    /*
        1 2 3
        4 5 6
        d1.swap(d2)
        4 5 6
        1 2 3
        swap(d1, d2)
        1 2 3
        4 5 6
    */

    return 0;
}