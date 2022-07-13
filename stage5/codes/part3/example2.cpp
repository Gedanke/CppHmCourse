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