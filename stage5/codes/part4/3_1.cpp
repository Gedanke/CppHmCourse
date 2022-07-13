#include <iostream>
#include <functional>

using namespace std;

// negate
void test1()
{
	negate<int> n;
	cout << n(50) << endl;
}

// plus
void test2()
{
	plus<int> p;
	cout << p(10, 20) << endl;
	cout << p(10, 20.1) << endl;
}

int main()
{
	test1();
	test2();

	/*
		-50
		30
		30
	*/

	return 0;
}