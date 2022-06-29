#include <iostream>

using namespace std;

int main()
{
    int arr[5] = {1, 3, 2, 5, 4};
    int len = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < len / 2; i++)
    {
        swap(arr[i], arr[len - i - 1]);
    }
    cout << "After swap" << endl;

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    /*
        1 3 2 5 4
        After swap
        4 5 2 3 1
    */

    return 0;
}