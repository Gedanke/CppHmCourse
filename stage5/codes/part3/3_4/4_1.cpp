#include <iostream>
#include <stack>

using namespace std;

// 栈容器常用接口
void test1()
{
    // 创建栈容器 栈容器必须符合先进后出
    stack<int> s;

    // 向栈中添加元素，叫做 压栈 入栈
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "栈的大小为：" << s.size() << endl;

    while (!s.empty())
    {
        // 输出栈顶元素
        cout << "栈顶元素为：" << s.top() << endl;
        // 弹出栈顶元素
        s.pop();
    }
    cout << "栈的大小为：" << s.size() << endl;
}

int main()
{
    test1();

    /*
        栈的大小为：3
        栈顶元素为：30
        栈顶元素为：20
        栈顶元素为：10
        栈的大小为：0
    */

    return 0;
}