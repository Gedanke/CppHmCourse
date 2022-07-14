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
		v2.push_back(i + 100);
	}

	cout << "交换前： " << endl;
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;

	cout << "交换后： " << endl;
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), [](int val)
			 { cout << val << " "; });
	cout << endl;
}

int main()
{
	test1();

	/*
		交换前：
		0 1 2 3 4 5 6 7 8 9
		100 101 102 103 104 105 106 107 108 109
		交换后：
		100 101 102 103 104 105 106 107 108 109
		0 1 2 3 4 5 6 7 8 9
	*/

	return 0;
}