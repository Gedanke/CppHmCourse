#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void test1()
{
	vector<int> v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	int total = accumulate(v.begin(), v.end(), 0);
	cout << "total = " << total << endl;
}

int main()
{
	test1();

	// total = 5050

	return 0;
}