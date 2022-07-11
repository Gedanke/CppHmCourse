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

    vector<int> v2;
    for (int i = 10; i > 0; i--)
    {
        v2.push_back(i);
    }
    printVector(v2);

    // 互换容器
    cout << "互换后" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

void test2()
{
    vector<int> v;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }

    cout << "v 的容量为：" << v.capacity() << endl;
    cout << "v 的大小为：" << v.size() << endl;

    v.resize(3);

    cout << "v 的容量为：" << v.capacity() << endl;
    cout << "v 的大小为：" << v.size() << endl;

    vector<int> vv(v);
    // 可以看出，拷贝构造是以 v 的实际大小进行初始化 vv 的大小和容量
    cout << "vv 的容量为：" << vv.capacity() << endl;
    cout << "vv 的大小为：" << vv.size() << endl;

    // 收缩内存
    vector<int>(v).swap(v); // 匿名对象

    cout << "v 的容量为：" << v.capacity() << endl;
    cout << "v 的大小为：" << v.size() << endl;
}

int main()
{
    test1();
    cout << "=========" << endl;
    test2();

    /*
        0 1 2 3 4 5 6 7 8 9
        10 9 8 7 6 5 4 3 2 1
        互换后
        10 9 8 7 6 5 4 3 2 1
        0 1 2 3 4 5 6 7 8 9
        =========
        v 的容量为：131072
        v 的大小为：100000
        v 的容量为：131072
        v 的大小为：3
        vv 的容量为：3
        vv 的大小为：3
        v 的容量为：3
        v 的大小为：3
    */

    return 0;
}
