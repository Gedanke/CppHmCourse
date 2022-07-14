#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

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
	srand((unsigned int)time(NULL));
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

	// 打乱顺序
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

int main()
{
	test1();

	/*
		0 1 2 3 4 5 6 7 8 9
		7 2 5 0 1 4 8 3 9 6
	*/

	return 0;
}