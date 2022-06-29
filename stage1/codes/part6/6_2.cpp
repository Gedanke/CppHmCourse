#include <iostream>

using namespace std;

int sum(int num1, int num2)
{
    int sum = num1 + num2;
    return sum;
}

int main()
{
    cout << sum(1, 2) << endl;
    // 3
    return 0;
}