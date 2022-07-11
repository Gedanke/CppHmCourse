#include <iostream>
#include <vector>

using namespace std;

void test1()
{
    vector<int> v;

    // 预留空间
    v.reserve(100000);

    int num = 0;
    int *p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }

    cout << "num: " << num << endl;
}

void test2()
{
    vector<int> v;

    // 不预留空间

    int num = 0;
    int *p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        // vector 每次扩容，数组的地址都会发生变化
        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }

    cout << "num: " << num << endl;
}

int main()
{
    test1();
    test2();

    /*
        num: 1
        num: 18
    */

    return 0;
}
