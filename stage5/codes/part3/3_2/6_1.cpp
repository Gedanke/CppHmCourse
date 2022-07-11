#include <iostream>
#include <vector>

using namespace std;

void test1()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << " ";
    }
    cout << endl;

    cout << v1.capacity() << endl;
    cout << v1[10] << endl;
    cout << v1[16] << endl; // 可以越界，也不会报错，但不要这样做
    // cout<<v1.at(10)<<endl; // std::out_of_range，越界

    cout << "v1 的第一个元素为：" << v1.front() << endl;
    cout << "v1 的最后一个元素为：" << v1.back() << endl;
}

int main()
{
    test1();

    /*
        0 1 2 3 4 5 6 7 8 9
        0 1 2 3 4 5 6 7 8 9
        16
        0
        0
        v1 的第一个元素为：0
        v1 的最后一个元素为：9
    */

    return 0;
}
