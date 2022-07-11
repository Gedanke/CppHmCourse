#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test1()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    if (v1.empty())
    {
        cout << "v1 为空" << endl;
    }
    else
    {
        cout << "v1 不为空" << endl;
        cout << "v1 的容量 = " << v1.capacity() << endl;
        cout << "v1 的大小 = " << v1.size() << endl;
    }

    // resize 重新指定大小，若指定的更大，默认用 0 填充新位置，可以利用重载版本替换默认填充
    v1.resize(15, 10);
    printVector(v1);

    // resize 重新指定大小，若指定的更小，超出部分元素被删除
    v1.resize(5);
    printVector(v1);
}

int main()
{
    test1();

    /*
        0 1 2 3 4 5 6 7 8 9
        v1 不为空
        v1 的容量 = 16
        v1 的大小 = 10
        0 1 2 3 4 5 6 7 8 9 10 10 10 10 10
        0 1 2 3 4
    */

    return 0;
}
