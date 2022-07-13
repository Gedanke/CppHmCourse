#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 普通函数
void print1(int val)
{
	cout << val << " ";
}

// 函数对象
class print2
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

// for_each 算法基本用法
void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// 遍历算法
	for_each(v.begin(), v.end(), print1);
	cout << endl;

	for_each(v.begin(), v.end(), print2());
	cout << endl;
}

int main()
{
	test1();

	/*
		0 1 2 3 4 5 6 7 8 9
		0 1 2 3 4 5 6 7 8 9
	*/

	return 0;
}