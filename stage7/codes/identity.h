#pragma once
#include <iostream>

using namespace std;

class Identity
{
public:
    // 用户名
    string name;
    // 密码
    string password;

public:
    // 不同的用户有着不同的操作菜单
    virtual void operMenu() = 0;
};