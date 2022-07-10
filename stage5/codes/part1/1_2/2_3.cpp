#include <iostream>

using namespace std;

class Person1
{
public:
    void showPerson1()
    {
        cout << "Person1 show" << endl;
    }
};

class Person2
{
public:
    void showPerson2()
    {
        cout << "Person2 show" << endl;
    }
};

template <class T>
class MyClass
{
public:
    T obj;

public:
    // 类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成
    void fun1()
    {
        obj.showPerson1();
    }

    void fun2()
    {
        obj.showPerson2();
    }
};

void test()
{
    MyClass<Person1> m1;
    m1.fun1();
    // m1.fun2();

    /*
        main.cpp: In instantiation of ‘void MyClass<T>::fun2() [with T = Person1]’:
        main.cpp:44:13:   required from here
        main.cpp:37:13: error: ‘class Person1’ has no member named ‘showPerson2’; did you mean ‘showPerson1’?
           37 |         obj.showPerson2();
              |         ~~~~^~~~~~~~~~~
              |         showPerson1
    */

    MyClass<Person2> m2;
    m2.fun2();
}

int main()
{
    test();

    /*
        Person1 show
        Person2 show
    */

    return 0;
}
