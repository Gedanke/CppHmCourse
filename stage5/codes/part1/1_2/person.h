#pragma once
#include <iostream>

using namespace std;

template <class T1, class T2>
class Person
{
public:
    T1 name;
    T2 age;

public:
    // 成员函数类内声明
    Person(T1 name, T2 age);
    void showPerson();
};