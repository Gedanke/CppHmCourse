#include <iostream>
#include <set>

using namespace std;

void printSet(set<int> &s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 构造和赋值
void test1()
{
    set<int> s1;

    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(20);
    s1.insert(40);
    printSet(s1);

    // 拷贝构造
    set<int> s2(s1);
    printSet(s2);

    // 赋值
    set<int> s3;
    s3 = s2;
    printSet(s3);

    set<int> s4{10, 20, 30, 40, 10};
    printSet(s4);
}

int main()
{
    test1();

    /*
        10 20 30 40
        10 20 30 40
        10 20 30 40
        10 20 30 40
    */

    return 0;
}