#include <iostream>

using namespace std;

class MyInteger
{
private:
    int num;

    friend ostream &operator<<(ostream &out, MyInteger myint);

public:
    MyInteger()
    {
        this->num = 0;
    }
    // 前置++
    MyInteger &operator++()
    {
        // 先++
        this->num++;
        // 再返回，返回自身引用，如果返回类型不是引用，则只是递增后的一个副本，不是调用前置++ 的当前对象本身
        return *this;
    }

    // 后置++，int 是占位参数，用于区分前置还是后置递增或者递减
    MyInteger operator++(int)
    {
        // 先返回
        MyInteger temp = *this; // 记录当前本身的值，然后让本身的值加 1，但是返回的是以前的值，达到先返回后 ++
        ++this->num;
        // 后置引用要返回值，而不是引用，因为 temp 是临时变量
        return temp;
    }
};

ostream &operator<<(ostream &out, MyInteger myint)
{
    out << myint.num;
    return out;
}

// 前置++，先 ++，再返回
void test1()
{
    MyInteger myInt;
    cout << ++myInt << endl;
    cout << myInt << endl;
    cout << ++myInt << endl;
    cout << myInt << endl;
}

// 后置++，先返回，再 ++
void test2()
{
    MyInteger myInt;
    cout << myInt++ << endl;
    cout << myInt << endl;
    cout << myInt++ << endl;
    cout << myInt << endl;
}

int main()
{
    test1();
    cout << "======" << endl;
    test2();

    /*
        1
        1
        2
        2
        ======
        0
        1
        1
        2
    */

    return 0;
}