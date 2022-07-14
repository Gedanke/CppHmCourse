#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class I, class T>
int binarySearch(I first, I second, T value)
{
	int res = -1;
	I l = first;
	I r = second;
	while (l <= r)
	{
		I mid = (r - l) / 2 + l;
		if (*mid == value)
		{
			res = mid - first;
			break;
		}
		else if (*mid < value)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}

	return res;
}

void test1()
{
	vector<int> v;
	for (int i = 0; i < 11; i++)
	{
		v.push_back(i + 1);
	}

	int idx = binarySearch(v.begin(), v.end(), -1);
	if (idx == -1)
	{
		cout << "-1 未找到 " << endl;
	}
	else
	{
		cout << "-1 的索引为: " << idx << endl;
	}

	idx = binarySearch(v.begin(), v.end(), 7);
	if (idx == -1)
	{
		cout << "7 未找到 " << endl;
	}
	else
	{
		cout << "7 的索引为: " << idx << endl;
	}

	// 二分查找
	bool ret = binary_search(v.begin(), v.end(), 2);
	if (ret)
	{
		cout << "2 找到了" << endl;
	}
	else
	{
		cout << "2 未找到" << endl;
	}
}

int main()
{
	test1();

	/*
		-1 未找到
		7 的索引为: 6
		2 找到了
	*/

	return 0;
}