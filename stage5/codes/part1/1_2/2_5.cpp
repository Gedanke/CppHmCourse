#include <iostream>

using namespace std;

template <class T>
class Base
{
public:
    T base;
};

// class Son:public Base {}; // 错误，c++ 编译需要给子类分配内存，必须知道父类中 T 的类型才可以向下继承。缺少类模板 "Base" 的参数列表
// 必须指定一个类型
class Son : public Base<int>
{
};

void test1()
{
    Son c;
}

// 类模板继承类模板，可以用 T2 指定父类中的 T 类型
template <class T1, class T2>
class Son2 : public Base<T2>
{
public:
    T1 son2;

public:
    Son2()
    {
        cout << typeid(T1).name() << endl;
        cout << typeid(T2).name() << endl;
    }
};

void test2()
{
    Son2<int, char> child1;
}

int main()
{
    test1();
    test2();

    /*
        i
        c
    */

    return 0;
}
