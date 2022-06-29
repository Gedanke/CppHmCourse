#include <iostream>

using namespace std;

bool fun(int n)
{
    int num = n;
    int num_ = n;
    int res = 0;
    while (num != 0)
    {
        res += (num % 10) * (num % 10) * (num % 10);
        num /= 10;
    }
    return num_ == res;
}

int main()
{
    int num = 100;
    do
    {
        if (fun(num))
        {
            cout << num << endl;
        }
        num++;
    } while (num < 1000);

    /*
        153
        370
        371
        407
    */

    return 0;
}