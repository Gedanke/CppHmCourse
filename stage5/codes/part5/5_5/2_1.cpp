#include <iostream>
#include <vector>
#include <numeric>
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
	vector<int> v;
	v.resize(10);
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

	// 填充
	fill(++v.begin(), --v.end(), 100);

	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

int main()
{
	test1();

	/*
		0 0 0 0 0 0 0 0 0 0
		0 100 100 100 100 100 100 100 100 0
	*/

	return 0;
}