#include <iostream>

using namespace std;

int main()
{
    char ch = 'a';
    cout << ch << endl;
    cout << sizeof(char) << endl;

    // ch = "abcde"; // 错误，不可以用双引号
    // ch = 'abcde'; // 错误，单引号内只能引用一个字符

    cout << (int)ch << endl; // 查看字符 a 对应的 ASCII 码
    ch = 97;                 // 可以直接用 ASCII 给字符型变量赋值
    // a - 97，A - 65
    cout << ch << endl;

    /*
        a
        1
        97
        a
    */

    return 0;
}