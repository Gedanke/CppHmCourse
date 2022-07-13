#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 常用遍历算法，搬运 transform
class TransForm
{
public:
	int operator()(int val)
	{
		return 2 * val;
	}
};

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// 目标容器
	vector<int> vTarget;

	// 目标容器需要提前开辟空间
	vTarget.resize(v.size());

	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	transform(v.begin(), v.end(), vTarget.begin(), TransForm());

	for_each(vTarget.begin(), vTarget.end(), MyPrint());
	cout << endl;
}

int main()
{
	test1();

	/*
		0 1 2 3 4 5 6 7 8 9
		0 2 4 6 8 10 12 14 16 18
	*/

	return 0;
}