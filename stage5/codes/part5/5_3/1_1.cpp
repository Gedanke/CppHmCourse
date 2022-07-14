#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void myPrint(int val)
{
	cout << val << " ";
}

class MySort
{
public:
	bool operator()(const int &num1, const int &num2)
	{
		return num1 < num2;
	}
};

bool mineSort(const int &num1, const int &num2)
{
	return num1 > num2;
}

void test1()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	// sort 默认从小到大排序
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	// 从大到小排序
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	// 从小到大排序
	sort(v.begin(), v.end(), MySort());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	// 从大到小排序
	sort(v.begin(), v.end(), mineSort);
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main()
{
	test1();

	/*
		10 20 30 40 50
		50 40 30 20 10
		10 20 30 40 50
		50 40 30 20 10
	*/

	return 0;
}