#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 内置数据类型
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i + 1);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "找到大于 5 的数字: " << *it << endl;
	}
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

class Greater20
{
public:
	bool operator()(Person &p)
	{
		return p.age > 20;
	}
};

bool Greater(Person &p)
{
	return p.age > 20;
}

void test2()
{
	vector<Person> v;
	// 创建数据
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());
	// vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater);
	if (it == v.end())
	{
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "找到年龄大于 20 的成员。姓名: " << it->name << " 年龄: " << it->age << endl;
	}
}

int main()
{
	test1();
	test2();

	/*
		找到大于 5 的数字: 6
		找到年龄大于 20 的成员。姓名: ccc 年龄: 30
	*/

	return 0;
}