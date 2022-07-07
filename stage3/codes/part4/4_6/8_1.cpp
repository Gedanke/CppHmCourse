#include <iostream>

using namespace std;

class Animal
{
public:
    int age;
};

class Sheep : public Animal
{
};

class Tuo : public Animal
{
};

class SheepTuo : public Sheep, public Tuo
{
};

// 继承前加 virtual 关键字后，变为虚继承
// 此时公共的父类 Animal 称为虚基类
class Sheep1 : virtual public Animal
{
};

class Tuo1 : virtual public Animal
{
};

class SheepTuo1 : public Sheep1, public Tuo1
{
};

void test1()
{
    SheepTuo st;
    st.Sheep::age = 18;
    st.Tuo::age = 21;

    cout << "sizeof(SheepTuo) = " << sizeof(SheepTuo) << endl;
    cout << "st.Sheep::age = " << st.Sheep::age << endl;
    cout << "st.Tuo::age = " << st.Tuo::age << endl;
}

void test2()
{
    SheepTuo1 st;
    st.Sheep1::age = 18;
    st.Tuo1::age = 21;

    cout << "sizeof(Animal) = " << sizeof(Animal) << endl;
    cout << "sizeof(Sheep1) = " << sizeof(Sheep1) << endl;
    cout << "sizeof(Tuo1) = " << sizeof(Tuo1) << endl;
    cout << "sizeof(SheepTuo1) = " << sizeof(SheepTuo1) << endl;
    cout << "st.Sheep1::age = " << st.Sheep1::age << endl;
    cout << "st.Tuo1::age = " << st.Tuo1::age << endl;
    cout << "st.age = " << st.age << endl;
}

int main()
{
    test1();
    cout << "======" << endl;
    test2();

    /*
        sizeof(SheepTuo) = 8
        st.Sheep::age = 18
        st.Tuo::age = 21
        ======
        sizeof(Animal) = 4
        sizeof(Sheep1) = 16
        sizeof(Tuo1) = 16
        sizeof(SheepTuo1) = 24
        st.Sheep1::age = 21
        st.Tuo1::age = 21
        st.age = 21
    */

    return 0;
}