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
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;

	vector<int> v2;
	v2.resize(v1.size());
	copy(++v1.begin(), --v1.end(), v2.begin());

	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
}

int main()
{
	test1();

	/*
		1 2 3 4 5 6 7 8 9 10
		2 3 4 5 6 7 8 9 0 0
	*/

	return 0;
}