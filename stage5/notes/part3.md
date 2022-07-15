# STL 常用容器

本节介绍 STL 中常用的容器，目录如下:

* [string 容器](./part3/part3_1.md)
* [vector 容器](./part3/part3_2.md)
* [deque 容器](./part3/part3_3.md)
* [stack 与 queue 容器](./part3/part3_4.md)
* [list 容器](./part3/part3_5.md)
* [set 与 multiset 容器](./part3/part3_6.md)
* [map 与 multimap 容器](./part3/part3_7.md)

STL 中的容器也不只有以上几个，每章节里面介绍的容器类型与常见的接口也远不只有这些，更多的细节还需要在实站中进一步学习，熟练运用

---

## 案例 - 评委打分

### 案例描述

有 5 名选手：选手 ABCDE，10 个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分

### 实现步骤

* 创建五名选手，放到 `vector` 中
* 遍历 `vector` 容器，取出来每一个选手，执行 `for` 循环，可以把 10 个评分打分存到 `deque` 容器中
* `sort` 算法对 `deque` 容器中分数排序，去除最高和最低分
* `deque` 容器遍历一遍，累加总分
* 获取平均分

demo:

```cpp
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
```

> 总结：选取不同的容器操作数据，可以提升代码的效率

---

## 案例 - 员工分组

### 案例描述

* 公司今天招聘了 10 个员工(ABCDEFGHIJ)，10 名员工进入公司之后，需要指派员工在那个部门工作
* 员工信息有: 姓名，工资组成；部门分为：策划、美术、研发
* 随机给 10 名员工分配部门和工资
* 通过 `multimap` 进行信息的插入 `key`(部门编号)与 `value`(员工)
* 分部门显示员工信息

### 实现步骤

* 创建 10 名员工，放到 `vector` 中
* 遍历 `vector` 容器，取出每个员工，进行随机分组
* 分组后，将员工部门编号作为 `key`，具体员工作为 `value`，放入到 `multimap` 容器中
* 分部门显示员工信息

demo:

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <ctime>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

using namespace std;

/*
    公司今天招聘了 10 个员工(ABCDEFGHIJ)，10 名员工进入公司之后，需要指派员工在那个部门工作
    员工信息有: 姓名，工资组成；部门分为：策划、美术、研发
    随机给 10 名员工分配部门和工资
    通过 multimap 进行信息的插入 key(部门编号)与 value(员工)
    分部门显示员工信息
 */

class Worker
{
public:
    string name;
    int salary;
};

void createWorker(vector<Worker> &v)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.name = "员工";
        worker.name += nameSeed[i];

        // 10000 ~ 19999
        worker.salary = rand() % 10000 + 10000;
        // 将员工放入到容器中
        v.push_back(worker);
    }
}

// 员工分组
void setGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 产生随机部门编号
        int deptId = rand() % 3; // 0 1 2

        // 将员工插入到分组中
        // key 部门编号，value 具体员工
        m.insert(make_pair(deptId, *it));
    }
}

void showWorkerByGourp(multimap<int, Worker> &m)
{
    cout << "策划部门：" << endl;

    multimap<int, Worker>::iterator pos = m.find(CEHUA);
    // 统计具体人数
    int count = m.count(CEHUA);
    int index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.name << " 工资：" << pos->second.salary << endl;
    }

    cout << "----------------------" << endl;
    cout << "美术部门： " << endl;

    pos = m.find(MEISHU);
    // 统计具体人数
    count = m.count(MEISHU);
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.name << " 工资：" << pos->second.salary << endl;
    }

    cout << "----------------------" << endl;
    cout << "研发部门： " << endl;

    pos = m.find(YANFA);
    // 统计具体人数
    count = m.count(YANFA);
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.name << " 工资：" << pos->second.salary << endl;
    }
}

int main()
{
    srand((unsigned int)time(NULL));

    // 创建员工
    vector<Worker> vWorker;
    createWorker(vWorker);

    // 员工分组
    multimap<int, Worker> mWorker;
    setGroup(vWorker, mWorker);

    // 分组显示员工
    showWorkerByGourp(mWorker);

    // 测试
    // for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
    // {
    // 	cout << "姓名： " << it->name << " 工资： " << it->salary << endl;
    // }

    /*
        策划部门：
        姓名：员工B 工资：13665
        姓名：员工C 工资：14477
        姓名：员工E 工资：17197
        姓名：员工H 工资：16895
        ----------------------
        美术部门：
        姓名：员工I 工资：18251
        姓名：员工J 工资：18094
        ----------------------
        研发部门：
        姓名：员工A 工资：15169
        姓名：员工D 工资：11382
        姓名：员工F 工资：10295
        姓名：员工G 工资：17989
    */

    return 0;
}
```

> 当数据以键值对形式存在，可以考虑用 `map` 或 `multimap`

---
