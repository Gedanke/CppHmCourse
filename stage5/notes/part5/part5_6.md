# 常用算术生成算法

**学习目标**：

* 掌握常用的集合算法

**算法简介**：

* `set_intersection`    求两个容器的交集
* `set_union`   求两个容器的并集
* `set_difference`  求两个容器的差集

---

## set_intersection

**功能描述**：

* 求两个容器的交集

**函数原型**：

* `set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);`    求两个集合的交集。注意，两个集合必须是有序序列

* `beg1` 容器 1 开始迭代器
* `end1` 容器 1 结束迭代器
* `beg2` 容器 2 开始迭代器
* `end2` 容器 2 结束迭代器
* `dest` 目标容器开始迭代器

demo:

```cpp
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
		v2.push_back(i + 5);
	}

	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;

	vector<int> vTarget;
	// 取两个里面较小的值给目标容器开辟空间
	vTarget.resize(min(v1.size(), v2.size()));

	// 返回目标容器的最后一个元素的迭代器地址
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;

	vector<int> res(vTarget.begin(), itEnd);
	for_each(res.begin(), res.end(), myPrint());
	cout << endl;
}

int main()
{
	test1();

	/*
		0 1 2 3 4 5 6 7 8 9
		5 6 7 8 9 10 11 12 13 14
		5 6 7 8 9
		5 6 7 8 9
	*/

	return 0;
}
```

> 求交集的两个集合必须的有序序列

> 目标容器开辟空间需要从 **两个容器中取小值**

> `set_intersection` 返回值既是交集中最后一个元素的位置

---

## set_union

**功能描述**：

* 求两个集合的并集

**函数原型**：

* `set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);`   求两个集合的并集。注意: 两个集合必须是有序序列

* `beg1` 容器 1 开始迭代器
* `end1` 容器 1 结束迭代器
* `beg2` 容器 2 开始迭代器
* `end2` 容器 2 结束迭代器
* `dest` 目标容器开始迭代器

demo:

```cpp
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
		v2.push_back(i + 5);
	}

	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;

	vector<int> vTarget;
	// 取两个容器的和给目标容器开辟空间
	vTarget.resize(v1.size() + v2.size());

	// 返回目标容器的最后一个元素的迭代器地址
	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;

	vector<int> res(vTarget.begin(), itEnd);
	for_each(res.begin(), res.end(), myPrint());
	cout << endl;
}

int main()
{
	test1();

	/*
		0 1 2 3 4 5 6 7 8 9
		5 6 7 8 9 10 11 12 13 14
		0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
		0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
	*/

	return 0;
}
```

> 求并集的两个集合必须的有序序列

> 目标容器开辟空间需要 **两个容器相加**

> `set_union` 返回值既是并集中最后一个元素的位置

---

## set_difference

**功能描述**：

* 求两个集合的差集

**函数原型**：

* `set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);`  求两个集合的差集。注意: 两个集合必须是有序序列

* `beg1` 容器 1 开始迭代器
* `end1` 容器 1 结束迭代器
* `beg2` 容器 2 开始迭代器
* `end2` 容器 2 结束迭代器
* `dest` 目标容器开始迭代器

demo:

```cpp
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
		v2.push_back(i + 5);
	}

	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;

	// 返回目标容器的最后一个元素的迭代器地址
	vector<int> vTarget1;
	// v1 与 v2 的差集大小不超过 v1 的大小
	vTarget1.resize(v1.size());
	cout << "v1 与 v2 的差集为：" << endl;
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget1.begin());
	for_each(vTarget1.begin(), itEnd, myPrint());
	cout << endl;

	vector<int> vTarget2;
	// v2 与 v1 的差集大小不超过 v2 的大小
	vTarget2.resize(v2.size());
	cout << "v2 与 v1 的差集为： " << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget2.begin());
	for_each(vTarget2.begin(), itEnd, myPrint());
	cout << endl;
}

int main()
{
	test1();

	/*
		0 1 2 3 4 5 6 7 8 9
		5 6 7 8 9 10 11 12 13 14
		v1 与 v2 的差集为：
		0 1 2 3 4
		v2 与 v1 的差集为：
		10 11 12 13 14
	*/

	return 0;
}
```

> 求差集的两个集合必须的有序序列

> 目标容器开辟空间需要从 **两个容器取较大值**

> `set_difference` 返回值既是差集中最后一个元素的位置

---
