#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

class Person
{
public:
    string name;
    int score;

public:
    Person(string name, int score)
    {
        this->name = name;
        this->score = score;
    }
};

void showVector(const vector<Person> &v)
{
    for (vector<Person>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << it->name << " 平均分：" << it->score << endl;
    }
}

void createPerson(vector<Person> &v)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < nameSeed.size(); i++)
    {
        string name = "选手";
        name += nameSeed[i];

        int score = 0;
        Person p(name, score);

        v.push_back(p);
    }
}

void setScore(vector<Person> &v)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        // 放入分数
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            d.push_back(
                rand() % 41 + 60);
        }

        // 排序
        sort(d.begin(), d.end());

        d.pop_back();
        d.pop_front();

        // 平均分
        int sum = 0;
        for (auto p = d.begin(); p != d.end(); p++)
        {
            sum += *p;
        }
        int avg = sum / d.size();

        it->score = avg;
    }
}

int main()
{
    // 随机数种子
    srand((unsigned int)time(NULL));

    // 创建 5 名选手
    vector<Person> v; // 存放选手容器
    createPerson(v);

    // 给 5 名选手打分
    setScore(v);

    // 显示最后得分
    showVector(v);

    /*
        姓名：选手A 平均分：76
        姓名：选手B 平均分：80
        姓名：选手C 平均分：74
        姓名：选手D 平均分：84
        姓名：选手E 平均分：77
    */

    return 0;
}