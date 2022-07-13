#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

class MyCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

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

	bool operator>(const Person &p) const
	{
		return this->score > p.score;
	}

	bool operator<(const Person &p) const
	{
		return this->score < p.score;
	}

	void show()
	{
		cout << "Name: " << this->name << " Score: " << this->score << endl;
	}
};

class ComparePerson
{
public:
	bool operator()(const Person &p1, const Person &p2)
	{
		return p1.score < p2.score;
	}
};

void test1()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 自己实现仿函数
	// sort(v.begin(), v.end(), MyCompare());
	// STL 内建仿函数，大于仿函数
	sort(v.begin(), v.end(), greater<int>());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	sort(v.begin(), v.end(), less<int>());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test2()
{
	string nameSeed = "ABCDEDF";
	vector<Person> v;
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "person";
		name += nameSeed[i];
		Person p(name, i * 10 + 30);
		v.push_back(p);
	}

	sort(v.begin(), v.end(), greater<Person>());
	for (auto it = v.begin(); it != v.end(); it++)
	{
		it->show();
	}

	cout << "=========" << endl;

	sort(v.begin(), v.end(), ComparePerson());
	for (auto it = v.begin(); it != v.end(); it++)
	{
		it->show();
	}
}

int main()
{
	test1();

	test2();

	/*
		10 30 50 40 20
		50 40 30 20 10
		10 20 30 40 50
		Name: personF Score: 90
		Name: personD Score: 80
		Name: personE Score: 70
		Name: personD Score: 60
		Name: personC Score: 50
		Name: personB Score: 40
		Name: personA Score: 30
		=========
		Name: personA Score: 30
		Name: personB Score: 40
		Name: personC Score: 50
		Name: personD Score: 60
		Name: personE Score: 70
		Name: personD Score: 80
		Name: personF Score: 90
	*/

	return 0;
}