#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include "globalFile.h"

using namespace std;

class OrderFile
{
public:
    // 预约纪录条数
    int size;

    // 记录的容器，key --- 记录的条数，value --- 具体记录的键值对信息
    map<int, map<string, string>> orderData;

public:
    // 构造函数
    OrderFile();

    // 更新预约记录
    void updateOrder();
};