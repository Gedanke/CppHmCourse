#include <iostream>
#include <map>

using namespace std;

void printMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
}

void test1()
{
    // 默认构造
    map<int, int> m{{1, 10}, {2, 20}};
    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(3, 30));
    printMap(m);

    // 拷贝构造
    map<int, int> m2(m);
    printMap(m2);

    map<int, int> m3;
    // 赋值
    m3 = m2;
    printMap(m3);
}

int main()
{
    test1();

    /*
        key = 1 value = 10
        key = 2 value = 20
        key = 3 value = 30
        key = 4 value = 40
        key = 1 value = 10
        key = 2 value = 20
        key = 3 value = 30
        key = 4 value = 40
        key = 1 value = 10
        key = 2 value = 20
        key = 3 value = 30
        key = 4 value = 40
    */

    return 0;
}