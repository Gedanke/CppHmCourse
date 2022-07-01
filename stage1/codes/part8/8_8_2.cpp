#include <iostream>

using namespace std;

// 英雄结构体
struct hero
{
    string name;
    int age;
    string sex;
};

// 冒泡排序
void bubbleSort(hero arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j].age > arr[j + 1].age)
            {
                hero temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 打印数组
void printHeros(hero arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "姓名： " << arr[i].name << " 性别： " << arr[i].sex << " 年龄： " << arr[i].age << endl;
    }
}

int main()
{
    struct hero arr[5] =
        {
            {"刘备", 23, "男"},
            {"关羽", 22, "男"},
            {"张飞", 20, "男"},
            {"赵云", 21, "男"},
            {"貂蝉", 19, "女"},
        };

    int len = sizeof(arr) / sizeof(hero); // 获取数组元素个数

    bubbleSort(arr, len); // 排序
    printHeros(arr, len); // 打印

    /*
        姓名： 貂蝉 性别： 女 年龄： 19
        姓名： 张飞 性别： 男 年龄： 20
        姓名： 赵云 性别： 男 年龄： 21
        姓名： 关羽 性别： 男 年龄： 22
        姓名： 刘备 性别： 男 年龄： 23
    */

    return 0;
}