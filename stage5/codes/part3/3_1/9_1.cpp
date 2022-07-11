#include <iostream>

using namespace std;

// 子串
void test1()
{

    string str = "abcdefg";
    string subStr = str.substr(1, 3);
    cout << "subStr = " << subStr << endl;

    string email = "hello@sina.com";
    int pos = email.find("@");
    cout << pos << endl;
    string username = email.substr(0, pos);
    cout << "username: " << username << endl;
}

int main()
{
    test1();

    /*
        subStr = bcd
        5
        username: hello
    */

    return 0;
}