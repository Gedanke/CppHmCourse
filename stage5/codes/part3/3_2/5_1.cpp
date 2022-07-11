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

// 插入和删除
void test1()
{
    vector<int> v1;
    // 尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    printVector(v1);
    // 尾删
    v1.pop_back();
    printVector(v1);
    // 插入
    v1.insert(v1.begin(), 100);
    printVector(v1);

    v1.insert(v1.begin(), 2, 1000);
    printVector(v1);

    // 删除
    v1.erase(v1.begin());
    printVector(v1);

    // 部分清空
    v1.erase(v1.begin() + 1, v1.end() - 1);
    printVector(v1);

    // 清空
    v1.clear();
    printVector(v1);
}

int main()
{
    test1();

    /*
        10 20 30 40 50
        10 20 30 40
        100 10 20 30 40
        1000 1000 100 10 20 30 40
        1000 100 10 20 30 40
        1000 40

    */

    return 0;
}
