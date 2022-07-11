#include <iostream>
#include "myArray.hpp"

using namespace std;

void printIntArray(MyArray<int> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 测试内置数据类型
void test1()
{
    MyArray<int> array1(10);
    for (int i = 0; i < 10; i++)
    {
        array1.push_back(i);
    }
    cout << "array1 打印输出：" << endl;
    printIntArray(array1);
    cout << "array1 的大小：" << array1.getSize() << endl;
    cout << "array1 的容量：" << array1.getCapacity() << endl;

    cout << "--------------------------" << endl;

    MyArray<int> array2(array1);
    array2.pop_back();
    cout << "array2 打印输出：" << endl;
    printIntArray(array2);
    cout << "array2 的大小：" << array2.getSize() << endl;
    cout << "array2 的容量：" << array2.getCapacity() << endl;
}

// 测试自定义数据类型
class Person
{
public:
    string name;
    int age;

public:
    Person()
    {
    }

    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};

void printPersonArray(MyArray<Person> &personArr)
{
    for (int i = 0; i < personArr.getSize(); i++)
    {
        cout << "姓名：" << personArr[i].name << " 年龄： " << personArr[i].age << endl;
    }
}

void test2()
{
    // 创建数组
    MyArray<Person> pArray(10);
    Person p1("Jar", 30);
    Person p2("Anna", 20);
    Person p3("Cory", 18);
    Person p4("Sam", 15);
    Person p5("Frank", 24);

    // 插入数据
    pArray.push_back(p1);
    pArray.push_back(p2);
    pArray.push_back(p3);
    pArray.push_back(p4);
    pArray.push_back(p5);

    printPersonArray(pArray);

    cout << "pArray 的大小：" << pArray.getSize() << endl;
    cout << "pArray 的容量：" << pArray.getCapacity() << endl;
}

int main()
{
    test1();
    cout << "======" << endl;
    test2();

    /*
        array1 打印输出：
        0 1 2 3 4 5 6 7 8 9
        array1 的大小：10
        array1 的容量：10
        --------------------------
        array2 打印输出：
        0 1 2 3 4 5 6 7 8
        array2 的大小：9
        array2 的容量：10
        ======
        姓名：Jar 年龄： 30
        姓名：Anna 年龄： 20
        姓名：Cory 年龄： 18
        姓名：Sam 年龄： 15
        姓名：Frank 年龄： 24
        pArray 的大小：5
        pArray 的容量：10
    */

    return 0;
}