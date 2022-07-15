# 常用排序算法

**学习目标**：

* 掌握常用的排序算法

**算法简介**：

* `sort`    对容器内元素进行排序
* `random_shuffle`  洗牌，指定范围内的元素随机调整次序
* `merge`   容器元素合并，并存储到另一容器中
* `reverse` 反转指定范围的元素

---

## sort

**功能描述**：

* 对容器内元素进行排序

**函数原型**：

`sort(iterator beg, iterator end, _Pred);`  按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

* `beg` 开始迭代器
* `end` 结束迭代器
* `_Pred` 谓词

demo:

```cpp
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
```

> 总结：`sort` 属于开发中最常用的算法之一，需熟练掌握

---

## random_shuffle

**功能描述**：

* 洗牌指定范围内的元素随机调整次序

**函数原型**：

`random_shuffle(iterator beg, iterator end);`   指定范围内的元素随机调整次序

* `beg` 开始迭代器
* `end` 结束迭代器

demo:

```cpp
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
```

> 总结：`random_shuffle` 洗牌算法比较实用，使用时记得加随机数种子

---

## merge

**功能描述**：

* 两个容器元素合并，并存储到另一容器中

**函数原型**：

`merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);`   容器元素合并，并存储到另一容器中。注意: 两个容器必须是 **有序的**

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
```

> 总结：`merge` 合并的两个容器必须的有序序列，如果不是有序的，合并的结果也不是有序的

---

## reverse

**功能描述**：

* 将容器内元素进行反转

**函数原型**：

`reverse(iterator beg, iterator end);`  反转指定范围的元素

* `beg` 开始迭代器
* `end` 结束迭代器

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
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	cout << "反转前：" << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

	cout << "反转后：" << endl;
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

int main()
{
	test1();

	/*
		反转前：
		10 30 50 20 40
		反转后：
		40 20 50 30 10
	*/

	return 0;
}
```

> 总结：`reverse` 反转区间内元素，面试题可能涉及到

---
