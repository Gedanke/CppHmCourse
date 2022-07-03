#include <iostream>

using namespace std;

int main()
{
    int *arr = new int[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 100;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 释放数组 delete 后加 []
    delete[] arr;

    /*
        100 101 102 103 104 105 106 107 108 109
    */

    return 0;
}