#include <iostream>

using namespace std;

void printArray(int *arr, int len);
void sortArray(int arr[], int len);

int main()
{
    int arr[10] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};
    int len = sizeof(arr) / sizeof(int);

    printArray(arr, len);
    sortArray(arr, len);
    printArray(arr, len);

    /*
        4 3 6 9 1 2 10 8 7 5
        1 2 3 4 5 6 7 8 9 10
    */

    return 0;
}

void printArray(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortArray(int arr[], int len)
{
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
}