#include <iostream>
// #include "person.h" // 只包含 .h 的文件是不行的
#include "person.cpp" // 解决方式 1，包含 cpp 源文件

// 解决方式 2，将声明和实现写到一起，文件后缀名改为 .hpp
// #include "person.hpp"

using namespace std;

void test1()
{
    Person<string, int> p("Tom", 22);
    p.showPerson();
}

int main()
{
    test1();

    /*
        姓名: Tom 年龄: 22
     */

    return 0;
}
