#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Greater4
{
public:
	bool operator()(int val)
	{
		return val >= 4;
	}
};

// 内置数据类型
void test1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);

	int num = count_if(v.begin(), v.end(), Greater4());
	cout << "大于 4 的个数为：" << num << endl;
}

// 自定义数据类型
class Person
{
public:
	string name;
	int age;

public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
};

class AgeLess35
{
public:
	bool operator()(const Person &p)
	{
		return p.age < 35;
	}
};

void test2()
{
	vector<Person> v;
	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 30);
	Person p5("曹操", 25);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	int num = count_if(v.begin(), v.end(), AgeLess35());
	cout << "小于 35 岁的个数：" << num << endl;
}

int main()
{
	test1();
	test2();

	/*
		大于 4 的个数为：4
		小于 35 岁的个数：2
	*/

	return 0;
}