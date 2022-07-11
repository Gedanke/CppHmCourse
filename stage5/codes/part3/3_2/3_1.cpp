#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &v)
{

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 赋值操作
void test1()
{
    // 无参构造
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;
    v2 = v1;
    printVector(v2);

    vector<int> v3;
    v3.assign(v1.begin() + 1, v1.end() - 1);
    printVector(v3);

    vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);
}

int main()
{
    test1();

    /*
        0 1 2 3 4 5 6 7 8 9
        0 1 2 3 4 5 6 7 8 9
        1 2 3 4 5 6 7 8
        100 100 100 100 100 100 100 100 100 100
    */

    return 0;
}
