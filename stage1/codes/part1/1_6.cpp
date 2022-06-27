#include <iostream>

using namespace std;

/*
    标识符不能是关键字
    标识符只能由字母、数字、下划线组成
    第一个字符必须为字母或下划线
    标识符中字母区分大小写
*/

int main()
{
    // 标识符不能是关键字
    // int int = 10; // 类型说明符的组合无效

    // 标识符只能由字母、数字、下划线组成
    int a = 1;
    int _a = 2;
    int _a1 = 3;

    // 第一个字符必须为字母或下划线
    // int 1a = 2; // 应输入标识符

    // 标识符中字母区分大小写
    int aa = 1;
    cout << aa << endl;
    // 1
    // cout << AA << endl; // 未定义标识符 "AA"

    // 给标识符命名时，争取做到见名知意的效果，方便自己和他人的阅读
    int num1 = 1;
    int num2 = 2;
    int sum = num1 + num2;
    cout << sum << endl;
    // 3
    return 0;
}