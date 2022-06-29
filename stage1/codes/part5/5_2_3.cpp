#include <iostream>

using namespace std;

int main()
{
    int arr[5] = {300, 350, 200, 400, 250};
    int max_value = arr[0];

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }
    cout << "max = " << max_value << endl;

    /*
        max = 400
    */

    return 0;
}