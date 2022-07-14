# 常用拷贝和替换算法

**学习目标**：

* 掌握常用的拷贝和替换算法

**算法简介**：

* `copy`    容器内指定范围的元素拷贝到另一容器中
* `replace` 将容器内指定范围的旧元素修改为新元素
* `replace_if`  容器内指定范围满足条件的元素替换为新元素
* `swap`    互换两个容器的元素

---

## copy

**功能描述：**

* 容器内指定范围的元素拷贝到另一容器中

**函数原型：**

- `copy(iterator beg, iterator end, iterator dest);`    按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

* `beg` 开始迭代器
* `end` 结束迭代器
* `dest` 目标起始迭代器

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
```

> 总结：利用 `copy` 算法在拷贝时，目标容器记得提前开辟空间

---

## replace

**功能描述**：

* 将容器内指定范围的旧元素修改为新元素

**函数原型**：

`replace(iterator beg, iterator end, oldvalue, newvalue);`  将区间内旧元素替换成新元素

* `beg` 开始迭代器
* `end` 结束迭代器
* `oldvalue` 旧元素
* `newvalue` 新元素

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
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);

	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

	//将容器中的 20 替换成 2000
	cout << "替换后：" << endl;
	replace(v.begin(), v.end(), 20, 2000);
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

int main()
{
	test1();

	/*
		替换前：
		20 30 20 40 50 10 20
		替换后：
		2000 30 2000 40 50 10 2000
	*/

	return 0;
}
```

> 总结：`replace` 会替换区间内满足条件的元素

---

## replace_if

**功能描述**:

* 将区间内满足条件的元素，替换成指定元素

**函数原型**：

`replace_if(iterator beg, iterator end, _pred, newvalue);`  按条件替换元素，满足条件的替换成指定元素

* `beg` 开始迭代器
* `end` 结束迭代器
* `_pred` 谓词
* `newvalue` 替换的新元素

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

class ReplaceGreater30
{
public:
	bool operator()(int val)
	{
		return val >= 30;
	}
};

void test1()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);

	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

	// 将容器中大于等于的 30 替换成 3000
	cout << "替换后：" << endl;
	replace_if(v.begin(), v.end(), ReplaceGreater30(), 3000);
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

int main()
{
	test1();

	/*
		替换前：
		20 30 20 40 50 10 20
		替换后：
		20 3000 20 3000 3000 10 20
	*/

	return 0;
}
```

> 总结：`replace_if` 按条件查找，可以利用仿函数灵活筛选满足的条件

---

## swap

**功能描述**：

* 互换两个容器的元素

**函数原型**：

`swap(container c1, container c2);` 互换两个容器的元素
  
* 容器 `c1`
* 容器 `c2`

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
```

> 总结：`swap` 交换容器时，注意交换的容器要同种类型

---
