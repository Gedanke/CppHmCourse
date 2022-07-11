#pragma once
#include <iostream>

using namespace std;

template <class T>
class MyArray
{
private:
    // 指向一个堆空间，这个空间存储真正的数据
    T *address;
    // 容量
    int capacity;
    // 大小
    int size;

public:
    // 构造函数
    MyArray(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->address = new T[this->capacity];
    }

    // 拷贝构造
    MyArray(const MyArray &arr)
    {
        this->capacity = arr.capacity;
        this->size = arr.size;
        this->address = new T[this->capacity];
        for (int i = 0; i < this->size; i++)
        {
            // 如果 T 为对象，而且还包含指针，必须需要重载 = 操作符，因为这个等号不是构造而是赋值
            // 普通类型可以直接 = 但是指针类型需要深拷贝
            this->address[i] = arr.address[i];
        }
    }

    // 重载 = 操作符  防止浅拷贝问题
    MyArray &operator=(const MyArray &myarray)
    {

        if (this->address != NULL)
        {
            delete[] this->address;
            this->capacity = 0;
            this->size = 0;
        }

        this->capacity = myarray.capacity;
        this->size = myarray.size;
        this->address = new T[this->capacity];
        for (int i = 0; i < this->size; i++)
        {
            this->address[i] = myarray[i];
        }
        return *this;
    }

    // 重载 [] 操作符 arr[0]
    T &operator[](int index)
    {
        // 不考虑越界，用户自己去处理
        return this->address[index];
    }

    // 尾插法
    void push_back(const T &val)
    {
        if (this->capacity == this->size)
        {
            return;
        }
        this->address[this->size] = val;
        this->size++;
    }

    // 尾删法
    void pop_back()
    {
        if (this->size == 0)
        {
            return;
        }
        this->size--;
    }

    // 获取数组容量
    int getCapacity()
    {
        return this->capacity;
    }

    // 获取数组大小
    int getSize()
    {
        return this->size;
    }

    // 析构
    ~MyArray()
    {
        if (this->address != NULL)
        {
            delete[] this->address;
            this->address = NULL;
            this->capacity = 0;
            this->size = 0;
        }
    }
};