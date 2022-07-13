#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 一元谓词
struct GreaterFive
{
	bool operator()(int val)
	{
		return val > 5;
	}
};

// 公共权限
class MoreFive
{
public:
	bool operator()(int val)
	{
		return val > 8;
	}
};

void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		cout << "没找到!" << endl;
	}
	else
	{
		cout << "找到: " << *it << endl;
	}

	vector<int>::iterator p = find_if(v.begin(), v.end(), MoreFive());
	if (p == v.end())
	{
		cout << "没找到!" << endl;
	}
	else
	{
		cout << "找到: " << *p << endl;
	}
}

int main()
{
	test1();

	/*
		找到: 6
		找到: 9
	*/

	return 0;
}