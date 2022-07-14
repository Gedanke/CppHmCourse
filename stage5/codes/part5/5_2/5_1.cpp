#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

	int num = count(v.begin(), v.end(), 4);
	cout << "4 的个数为：" << num << endl;
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

	bool operator==(const Person &p)
	{
		if (this->age == p.age)
		{
			return true;
		}
		else
		{
			return false;
		}
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

	Person p("诸葛亮", 35);

	int num = count(v.begin(), v.end(), p);
	cout << "num = " << num << endl;
}

int main()
{
	test1();
	test2();

	/*
		4 的个数为：3
		num = 3
	*/

	return 0;
}