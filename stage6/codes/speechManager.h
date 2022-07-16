#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "speaker.h"

using namespace std;

// 演讲管理类
class SpeechManager
{
public:
    // 比赛选手容器，12 人
    vector<int> player;

    // 第一轮晋级容器，6 人
    vector<int> playerRound;

    // 胜利前三名容器，3 人
    vector<int> playerVictory;

    // 存放编号以及对应的具体选手容器
    map<int, Speaker> speakers;

    // 比赛轮数
    int round;

public:
    // 构造函数
    SpeechManager();

    // 展示菜单
    void showMenu();

    // 初始化属性
    void initSpeech();

    // 初始化创建 12 名选手
    void createSpeaker();

    // 开始比赛 - 比赛流程控制
    void startSpeech();

    // 抽签
    void speechDraw();

    // 比赛
    void speechContest();

    // 显示比赛结果
    void showScore();

    // 退出系统
    void exitSystem();

    // 析构函数
    ~SpeechManager();
};