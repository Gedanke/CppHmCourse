#include <iostream>

using namespace std;

int main()
{
    int arr[] = {4, 2, 8, 0, 5, 7, 1, 3, 9};
    int len = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    cout << "After sort" << endl;

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    /*
        4 2 8 0 5 7 1 3 9
        After sort
        0 1 2 3 4 5 7 8 9
    */

    return 0;
}