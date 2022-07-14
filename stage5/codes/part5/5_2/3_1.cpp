#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test1()
{
	vector<int> v{1, 2, 5, 2, 4, 4, 6, 3, 3, 3};

	// 查找相邻重复元素
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
	{
		cout << "找不到!" << endl;
	}
	else
	{
		cout << "找到第一个相邻重复元素为: " << *it << endl;
	}
}

int main()
{
	test1();

	// 找到第一个相邻重复元素为: 4

	return 0;
}