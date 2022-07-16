#include "speechManager.h"
#include <algorithm>
#include <deque>
#include <numeric>

// 构造函数
SpeechManager::SpeechManager()
{
    // 初始化属性
    this->initSpeech();
    // 创建选手
    this->createSpeaker();
}

// 展示菜单
void SpeechManager::showMenu()
{
    cout << "********************************************" << endl;
    cout << "*************  欢迎参加演讲比赛 ************" << endl;
    cout << "*************  1.开始演讲比赛  *************" << endl;
    cout << "*************  2.查看往届记录  *************" << endl;
    cout << "*************  3.清空比赛记录  *************" << endl;
    cout << "*************  0.退出比赛程序  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

// 初始化属性
void SpeechManager::initSpeech()
{
    // 清空所有容器
    this->player.clear();
    this->playerRound.clear();
    this->playerVictory.clear();
    this->speakers.clear();
    this->round = 1;
}

// 初始化创建 12 名选手
void SpeechManager::createSpeaker()
{
    string nameStr = "ABCDEFGHIJKL";
    for (int i = 0; i < nameStr.size(); i++)
    {
        string name = "选手";
        name += nameStr[i];

        Speaker speaker;
        speaker.name = name;
        for (int j = 0; j < 2; j++)
        {
            speaker.score[j] = 0;
        }

        // 选手编号
        int id = i + 10001;
        this->player.push_back(id);

        // 选手编号以及对应的选手存放到 map 容器中
        this->speakers.insert(make_pair(id, speaker));
    }
}

// 开始比赛 - 比赛流程控制
void SpeechManager::startSpeech()
{
    // 第一轮比赛
    // 抽签
    this->speechDraw();

    // 比赛
    this->speechContest();

    // 显示晋级结果
    this->showScore();

    // 第二轮比赛
    this->round++;

    // 抽签
    this->speechDraw();

    // 比赛
    this->speechContest();

    // 显示最终结果
    this->showScore();

    // 保存分数
}

// 抽签
void SpeechManager::speechDraw()
{
    cout << "第 << " << this->round << " >> 轮比赛选手正在抽签" << endl;
    cout << "---------------------" << endl;
    cout << "抽签后演讲顺序如下：" << endl;
    if (this->round == 1)
    {
        // 第一轮
        random_shuffle(this->player.begin(), this->player.end());
        for (vector<int>::iterator it = this->player.begin(); it != this->player.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        // 第二轮
        random_shuffle(this->playerRound.begin(), this->playerRound.end());
        for (vector<int>::iterator it = this->playerRound.begin(); it != this->playerRound.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "---------------------" << endl;
    cout << endl;
}

// 比赛
void SpeechManager::speechContest()
{
    // 随机数种子
    srand((unsigned int)time(NULL));

    cout << "------------- 第" << this->round << "轮正式比赛开始：------------- " << endl;
    // 临时容器，保存 key 分数 value 选手编号
    multimap<double, int, greater<int>> groupScore;
    // 记录人员数，6 个为 1 组
    int num = 0;
    // 比赛人员容器
    vector<int> vScore;

    if (this->round == 1)
    {
        vScore = this->player;
    }
    else
    {
        vScore = this->playerRound;
    }

    // 遍历所有参赛选手
    for (vector<int>::iterator it = vScore.begin(); it != vScore.end(); it++)
    {
        num++;

        // 打分
        deque<double> d;
        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.f;
            d.push_back(score);
        }

        // 排序
        sort(d.begin(), d.end(), greater<double>());
        // 去掉最高分与最低分
        d.pop_front();
        d.pop_back();

        double sum = accumulate(d.begin(), d.end(), 0.0f);
        double avg = sum / (double)d.size();

        // 每个人的平均分
        this->speakers[*it].score[this->round - 1] = avg;

        // 6 个人一组，用临时容器保存
        groupScore.insert(make_pair(avg, *it));

        if (num % 6 == 0)
        {
            cout << "第" << num / 6 << "小组比赛名次：" << endl;
            for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
            {
                cout << "编号: " << it->second << " 姓名： " << this->speakers[it->second].name << " 成绩： " << this->speakers[it->second].score[this->round - 1] << endl;
            }

            int count = 0;
            // 取前三名
            for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
            {
                if (this->round == 1)
                {
                    this->playerRound.push_back((*it).second);
                }
                else
                {
                    this->playerVictory.push_back((*it).second);
                }
            }

            groupScore.clear();
            cout << endl;
        }
    }
    cout << "------------- 第" << this->round << "轮比赛完毕  ------------- " << endl;
}

// 显示比赛结果
void SpeechManager::showScore()
{
    cout << "---------第" << this->round << "轮晋级选手信息如下：-----------" << endl;
    vector<int> v;

    if (this->round == 1)
    {
        v = playerRound;
    }
    else
    {
        v = playerVictory;
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "选手编号：" << *it << " 姓名： " << this->speakers[*it].name << " 得分： " << this->speakers[*it].score[this->round - 1] << endl;
    }
    cout << endl;

    this->showMenu();
}

// 退出系统
void SpeechManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}

// 析构函数
SpeechManager::~SpeechManager()
{
}