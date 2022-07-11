#include <iostream>

using namespace std;

void test1()
{
    string str = "hello world";

    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i];
    }
    cout << endl;

    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i);
    }
    cout << endl;

    // 字符修改
    str[0] = 'x';
    str.at(1) = 'x';
    cout << str << endl;

    // 字符修改，可以越界
    str[14] = 'a';
    cout << str << endl;

    // 字符修改，不可以越界
    str.at(12) = 'a';
    cout << str << endl;
}

int main()
{
    test1();

    /*
        hello world
        hello world
        xxllo world
        xxllo world
        terminate called after throwing an instance of 'std::out_of_range'
            what():  basic_string::at: __n (which is 12) >= this->size() (which is 11)
        Aborted
    */

    return 0;
}