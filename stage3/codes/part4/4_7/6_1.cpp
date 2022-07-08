#include <iostream>

using namespace std;

// 抽象 CPU 类
class CPU
{
public:
    // 抽象的计算函数
    virtual void calculate() = 0;
};

// 抽象显卡类
class VideoCard
{
public:
    // 抽象的显示函数
    virtual void display() = 0;
};

// 抽象内存条类
class Memory
{
public:
    // 抽象的存储函数
    virtual void storage() = 0;
};

// 电脑类
class Computer
{
private:
    CPU *cpu;      // CPU 的零件指针
    VideoCard *vc; // 显卡零件指针
    Memory *mem;   // 内存条零件指针

public:
    Computer(CPU *cpu, VideoCard *vc, Memory *mem)
    {
        this->cpu = cpu;
        this->vc = vc;
        this->mem = mem;
    }

    // 提供工作的函数
    void work()
    {
        // 让零件工作起来，调用接口
        this->cpu->calculate();
        this->vc->display();
        this->mem->storage();
    }

    // 提供析构函数，释放 3 个电脑零件
    ~Computer()
    {
        // 释放 CPU 零件
        if (this->cpu != NULL)
        {
            delete this->cpu;
            this->cpu = NULL;
        }

        // 释放显卡零件
        if (this->vc != NULL)
        {
            delete this->vc;
            this->vc = NULL;
        }

        // 释放内存条零件
        if (this->mem != NULL)
        {
            delete this->mem;
            this->mem = NULL;
        }
    }
};

// 具体厂商
// Intel 厂商
class IntelCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout << "Intel 的 CPU 开始计算了！" << endl;
    }
};

class IntelVideoCard : public VideoCard
{
public:
    virtual void display()
    {
        cout << "Intel 的显卡开始显示了！" << endl;
    }
};

class IntelMemory : public Memory
{
public:
    virtual void storage()
    {
        cout << "Intel 的内存条开始存储了！" << endl;
    }
};

// Lenovo 厂商
class LenovoCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout << "Lenovo 的 CPU 开始计算了！" << endl;
    }
};

class LenovoVideoCard : public VideoCard
{
public:
    virtual void display()
    {
        cout << "Lenovo 的显卡开始显示了！" << endl;
    }
};

class LenovoMemory : public Memory
{
public:
    virtual void storage()
    {
        cout << "Lenovo 的内存条开始存储了！" << endl;
    }
};

void test1()
{
    // 第一台电脑零件
    cout << "第一台电脑开始工作：" << endl;
    // 创建第一台电脑
    Computer *computer1 = new Computer(new IntelCPU, new IntelVideoCard, new IntelMemory);
    computer1->work();
    delete computer1;

    cout << "-----------------------" << endl;
    cout << "第二台电脑开始工作：" << endl;
    // 第二台电脑组装
    Computer *computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
    computer2->work();
    delete computer2;

    cout << "-----------------------" << endl;
    cout << "第三台电脑开始工作：" << endl;
    // 第三台电脑组装
    Computer *computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);
    computer3->work();
    delete computer3;
}

int main()
{
    test1();

    /*
        第一台电脑开始工作：
        Intel 的 CPU 开始计算了！
        Intel 的显卡开始显示了！
        Intel 的内存条开始存储了！
        -----------------------
        第二台电脑开始工作：
        Lenovo 的 CPU 开始计算了！
        Lenovo 的显卡开始显示了！
        Lenovo 的内存条开始存储了！
        -----------------------
        第三台电脑开始工作：
        Lenovo 的 CPU 开始计算了！
        Intel 的显卡开始显示了！
        Lenovo 的内存条开始存储了！
    */

    return 0;
}