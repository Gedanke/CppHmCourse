# 常用遍历算法

**学习目标**：

* 掌握常用的遍历算法

**算法简介**：

* `for_each`    遍历容器
* `transform`   搬运容器到另一个容器中

---

## for_each

**功能描述**：

* 实现遍历容器

**函数原型**：

`for_each(iterator beg, iterator end, _func);`  遍历算法 遍历容器元素

* `beg` 开始迭代器
* `end` 结束迭代器
* `_func` 函数或者函数对象

demo:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 普通函数
void print1(int val)
{
	cout << val << " ";
}

// 函数对象
class print2
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

// for_each 算法基本用法
void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// 遍历算法
	for_each(v.begin(), v.end(), print1);
	cout << endl;

	for_each(v.begin(), v.end(), print2());
	cout << endl;
}

int main()
{
	test1();

	/*
		0 1 2 3 4 5 6 7 8 9
		0 1 2 3 4 5 6 7 8 9
	*/

	return 0;
}
```

> 总结：`for_each` 在实际开发中是最常用遍历算法，需要熟练掌握

---

## transform

**功能描述**：

* 搬运容器到另一个容器中

**函数原型**：

`transform(iterator beg1, iterator end1, iterator beg2, _func);`

* `beg1` 源容器开始迭代器
* `end1` 源容器结束迭代器
* `beg2` 目标容器开始迭代器
* `_func` 函数或者函数对象

demo:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 常用遍历算法，搬运 transform
class TransForm
{
public:
	int operator()(int val)
	{
		return 2 * val;
	}
};

class MyPrint
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
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// 目标容器
	vector<int> vTarget;

	// 目标容器需要提前开辟空间
	vTarget.resize(v.size());

	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	transform(v.begin(), v.end(), vTarget.begin(), TransForm());

	for_each(vTarget.begin(), vTarget.end(), MyPrint());
	cout << endl;
}

int main()
{
	test1();

	/*
		0 1 2 3 4 5 6 7 8 9
		0 2 4 6 8 10 12 14 16 18
	*/

	return 0;
}
```

> 总结：搬运的目标容器必须要提前开辟空间，否则无法正常搬运

---
