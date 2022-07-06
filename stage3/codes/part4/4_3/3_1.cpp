#include <iostream>

using namespace std;

// 空指针访问成员函数
class Person
{
public:
    int mAge;

public:
    void ShowClassName()
    {
        cout << "我是 Person 类!" << endl;
    }

    void ShowPerson()
    {
        if (this == NULL)
        {
            return;
        }
        cout << mAge << endl;
    }
};

void test1()
{
    Person *p = NULL;
    // cout << p->mAge << endl; // Segmentation fault
    p->ShowClassName(); // 空指针，可以调用成员函数
    p->ShowPerson();    // 但是如果成员函数中用到了 this 指针，就不可以了，Segmentation fault
}

int main()
{
    test1();

    /*
        我是 Person 类!
    */

    return 0;
}