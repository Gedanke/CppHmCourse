#include <iostream>

using namespace std;

// string 构造
void test1()
{
    // 创建空字符串，调用无参构造函数
    string s1;
    cout << "str1 = " << s1 << endl;

    const char *str = "hello world";
    // 把 c_string 转换成了 string
    string s2(str);

    cout << "str2 = " << s2 << endl;

    // 调用拷贝构造函数
    string s3(s2);
    cout << "str3 = " << s3 << endl;

    string s4(10, 'a');
    cout << "str4 = " << s4 << endl;
}

int main()
{
    test1();

    /*
        str1 =
        str2 = hello world
        str3 = hello world
        str4 = aaaaaaaaaa
    */

    return 0;
}
