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
		v2.push_back(i + 1);
	}

	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	// reverse(v2.begin(), v2.end());
	// random_shuffle(v2.begin(), v2.end());
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;

	vector<int> vtarget;
	// 目标容器需要提前开辟空间，否则 Segmentation fault
	vtarget.resize(v1.size() + v2.size());
	// 合并，需要两个有序序列
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
	for_each(vtarget.begin(), vtarget.end(), myPrint());
	cout << endl;
}

int main()
{
	test1();

	/*
		0 1 2 3 4 5 6 7 8 9
		1 2 3 4 5 6 7 8 9 10
		0 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10
	*/

	return 0;
}