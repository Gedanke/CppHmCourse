#include <iostream>

using namespace std;

// Java 页面
class Java
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...(公共头部)" << endl;
    }
    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
    }
    void left()
    {
        cout << "Java，Python，C++...(公共分类列表)" << endl;
    }
    void content()
    {
        cout << "JAVA 学科视频" << endl;
    }
};

// Python 页面
class Python
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...(公共头部)" << endl;
    }
    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
    }
    void left()
    {
        cout << "Java，Python，C++...(公共分类列表)" << endl;
    }
    void content()
    {
        cout << "Python 学科视频" << endl;
    }
};

// C++ 页面
class CPP
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...(公共头部)" << endl;
    }
    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
    }
    void left()
    {
        cout << "Java，Python，C++...(公共分类列表)" << endl;
    }
    void content()
    {
        cout << "C++ 学科视频" << endl;
    }
};

void test01()
{
    // Java 页面
    cout << "Java 下载视频页面如下： " << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout << "--------------------" << endl;

    // Python 页面
    cout << "Python 下载视频页面如下： " << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "--------------------" << endl;

    // C++ 页面
    cout << "C++ 下载视频页面如下： " << endl;
    CPP cp;
    cp.header();
    cp.footer();
    cp.left();
    cp.content();
}

int main()
{
    test01();

    /*
        Java 下载视频页面如下：
        首页、公开课、登录、注册...(公共头部)
        帮助中心、交流合作、站内地图...(公共底部)
        Java，Python，C++...(公共分类列表)
        JAVA 学科视频
        --------------------
        Python 下载视频页面如下：
        首页、公开课、登录、注册...(公共头部)
        帮助中心、交流合作、站内地图...(公共底部)
        Java，Python，C++...(公共分类列表)
        Python 学科视频
        --------------------
        C++ 下载视频页面如下：
        首页、公开课、登录、注册...(公共头部)
        帮助中心、交流合作、站内地图...(公共底部)
        Java，Python，C++...(公共分类列表)
        C++ 学科视频
    */

    return 0;
}