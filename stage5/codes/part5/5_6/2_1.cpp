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

	vector<int> vTarget;
	// 取两个容器的和给目标容器开辟空间
	vTarget.resize(v1.size() + v2.size());

	// 返回目标容器的最后一个元素的迭代器地址
	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;

	vector<int> res(vTarget.begin(), itEnd);
	for_each(res.begin(), res.end(), myPrint());
	cout << endl;
}

int main()
{
	test1();

	/*
		0 1 2 3 4 5 6 7 8 9
		5 6 7 8 9 10 11 12 13 14
		0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
		0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
	*/

	return 0;
}