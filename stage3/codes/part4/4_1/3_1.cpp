#include <iostream>

using namespace std;

class Person
{
private:
    string m_Name;  // 可读可写  姓名
    int m_Age;      // 只读  年龄
    string m_Lover; // 只写  爱人

public:
    // 姓名设置可读可写
    void setName(string name)
    {
        m_Name = name;
    }
    string getName()
    {
        return m_Name;
    }

    // 获取年龄
    int getAge()
    {
        return m_Age;
    }
    
    // 设置年龄
    void setAge(int age)
    {
        if (age < 0 || age > 150)
        {
            cout << "你个老妖精!" << endl;
            return;
        }
        m_Age = age;
    }

    // 爱人设置为只写
    void setLover(string lover)
    {
        m_Lover = lover;
    }
};

int main()
{
    Person p;
    // 姓名设置
    p.setName("张三");
    cout << "姓名： " << p.getName() << endl;

    // 年龄设置
    p.setAge(50);
    cout << "年龄： " << p.getAge() << endl;

    // 爱人设置
    p.setLover("李四");
    // cout << "爱人： " << p.m_Lover << endl;  // 只写属性，不可以读取

    /*
        姓名： 张三
        年龄： 50
    */

    return 0;
}
