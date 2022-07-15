#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test1()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;

	// 返回目标容器的最后一个元素的迭代器地址
	vector<int> vTarget1;
	// v1 与 v2 的差集大小不超过 v1 的大小
	vTarget1.resize(v1.size());
	cout << "v1 与 v2 的差集为：" << endl;
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget1.begin());
	for_each(vTarget1.begin(), itEnd, myPrint());
	cout << endl;

	vector<int> vTarget2;
	// v2 与 v1 的差集大小不超过 v2 的大小
	vTarget2.resize(v2.size());
	cout << "v2 与 v1 的差集为： " << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget2.begin());
	for_each(vTarget2.begin(), itEnd, myPrint());
	cout << endl;
}

int main()
{
	test1();

	/*
		0 1 2 3 4 5 6 7 8 9
		5 6 7 8 9 10 11 12 13 14
		v1 与 v2 的差集为：
		0 1 2 3 4
		v2 与 v1 的差集为：
		10 11 12 13 14
	*/

	return 0;
}