#include <iostream>

using namespace std;

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " x " << i << " = " << i * j << "\t";
        }
        cout << endl;
    }

    /*
        1 x 1 = 1
        1 x 2 = 2       2 x 2 = 4
        1 x 3 = 3       2 x 3 = 6       3 x 3 = 9
        1 x 4 = 4       2 x 4 = 8       3 x 4 = 12      4 x 4 = 16
        1 x 5 = 5       2 x 5 = 10      3 x 5 = 15      4 x 5 = 20      5 x 5 = 25
        1 x 6 = 6       2 x 6 = 12      3 x 6 = 18      4 x 6 = 24      5 x 6 = 30      6 x 6 = 36
        1 x 7 = 7       2 x 7 = 14      3 x 7 = 21      4 x 7 = 28      5 x 7 = 35      6 x 7 = 42      7 x 7 = 49
        1 x 8 = 8       2 x 8 = 16      3 x 8 = 24      4 x 8 = 32      5 x 8 = 40      6 x 8 = 48      7 x 8 = 56      8 x 8 = 64
        1 x 9 = 9       2 x 9 = 18      3 x 9 = 27      4 x 9 = 36      5 x 9 = 45      6 x 9 = 54      7 x 9 = 63      8 x 9 = 72      9 x 9 = 81
    */

    return 0;
}