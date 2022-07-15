# 常用查找算法

**学习目标**：

* 掌握常用的查找算法

**算法简介**：

* `find`    查找元素
* `find_if` 按条件查找元素
* `adjacent_find`   查找相邻重复元素
* `binary_search`   二分查找法
* `count`   统计元素个数
* `count_if`    按条件统计元素个数

---

## find

**功能描述**：

* 查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器 `end()`

**函数原型**：

`find(iterator beg, iterator end, value);`	按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

* `beg` 开始迭代器
* `end` 结束迭代器
* `value` 查找的元素

demo:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i + 1);
	}
	// 查找容器中是否有 5 这个元素
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())
	{
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "找到: " << *it << endl;
	}
}

class Person
{
public:
	string name;
	int age;

public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	// 重载==
	bool operator==(const Person &p)
	{
		if (this->name == p.name && this->age == p.age)
		{
			return true;
		}
		return false;
	}
};

void test2()
{
	vector<Person> v;
	// 创建数据
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator it = find(v.begin(), v.end(), p2);
	if (it == v.end())
	{
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "找到姓名: " << it->name << " 年龄: " << it->age << endl;
	}
}

int main()
{
	test1();
	test2();

	/*
		找到: 5
		找到姓名: bbb 年龄: 20
	*/

	return 0;
}
```

> 总结：利用 `find` 可以在容器中找指定的元素，返回值是迭代器；自定义类型需要重载 `==`

---

## find_if

**功能描述**：

* 按条件查找元素

**函数原型**：

`find_if(iterator beg, iterator end, _Pred);`	按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

* `beg` 开始迭代器
* `end` 结束迭代器
* `_Pred` 函数或者谓词(返回 `bool` 类型的仿函数)

demo:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 内置数据类型
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i + 1);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "找到大于 5 的数字: " << *it << endl;
	}
}

// 自定义数据类型
class Person
{
public:
	string name;
	int age;

public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
};

class Greater20
{
public:
	bool operator()(Person &p)
	{
		return p.age > 20;
	}
};

bool Greater(Person &p)
{
	return p.age > 20;
}

void test2()
{
	vector<Person> v;
	// 创建数据
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());
	// vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater);
	if (it == v.end())
	{
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "找到年龄大于 20 的成员。姓名: " << it->name << " 年龄: " << it->age << endl;
	}
}

int main()
{
	test1();
	test2();

	/*
		找到大于 5 的数字: 6
		找到年龄大于 20 的成员。姓名: ccc 年龄: 30
	*/

	return 0;
}
```

> 总结：`find_if` 按条件查找使查找更加灵活，提供的仿函数可以改变不同的策略

---

## adjacent_find

**功能描述**：

* 查找相邻重复元素

**函数原型**：

`adjacent_find(iterator beg, iterator end);`	查找相邻重复元素，返回相邻元素的第一个位置的迭代器

* `beg` 开始迭代器
* `end` 结束迭代器

demo:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test1()
{
	vector<int> v{1, 2, 5, 2, 4, 4, 6, 3, 3, 3};

	// 查找相邻重复元素
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
	{
		cout << "找不到!" << endl;
	}
	else
	{
		cout << "找到第一个相邻重复元素为: " << *it << endl;
	}
}

int main()
{
	test1();

	// 找到第一个相邻重复元素为: 4

	return 0;
}
```

> 总结：面试题中如果出现查找相邻重复元素，记得用 STL 中的 `adjacent_find` 算法

---

## binary_search

**功能描述**：

* 查找指定元素是否存在

**函数原型**：

`bool binary_search(iterator beg, iterator end, value);`	查找指定的元素，查到返回 `true`，否则 `false`，注意: 在 **无序序列中不可用**

* `beg` 开始迭代器
* `end` 结束迭代器
* `value` 查找的元素

demo:

```cpp
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
```

> 总结：二分查找法查找效率很高，值得注意的是查找的容器中元素必须的有序序列

---

## count

**功能描述**：

* 统计元素个数

**函数原型**：

`count(iterator beg, iterator end, value);`	统计元素出现次数

* `beg` 开始迭代器
* `end` 结束迭代器
* `value` 统计的元素

demo:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 内置数据类型
void test1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);

	int num = count(v.begin(), v.end(), 4);
	cout << "4 的个数为：" << num << endl;
}

// 自定义数据类型
class Person
{
public:
	string name;
	int age;

public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	bool operator==(const Person &p)
	{
		if (this->age == p.age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

void test2()
{
	vector<Person> v;
	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 30);
	Person p5("曹操", 25);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	Person p("诸葛亮", 35);

	int num = count(v.begin(), v.end(), p);
	cout << "num = " << num << endl;
}

int main()
{
	test1();
	test2();

	/*
		4 的个数为：3
		num = 3
	*/

	return 0;
}
```

> 总结：统计自定义数据类型时候，需要配合重载 `operator==`

---

## count_if

**功能描述**：

* 按条件统计元素个数

**函数原型**：

`count_if(iterator beg, iterator end, _Pred);`	按条件统计元素出现次数

* `beg` 开始迭代器
* `end` 结束迭代器
* `_Pred` 谓词

demo:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Greater4
{
public:
	bool operator()(int val)
	{
		return val >= 4;
	}
};

// 内置数据类型
void test1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);

	int num = count_if(v.begin(), v.end(), Greater4());
	cout << "大于 4 的个数为：" << num << endl;
}

// 自定义数据类型
class Person
{
public:
	string name;
	int age;

public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
};

class AgeLess35
{
public:
	bool operator()(const Person &p)
	{
		return p.age < 35;
	}
};

void test2()
{
	vector<Person> v;
	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 30);
	Person p5("曹操", 25);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	int num = count_if(v.begin(), v.end(), AgeLess35());
	cout << "小于 35 岁的个数：" << num << endl;
}

int main()
{
	test1();
	test2();

	/*
		大于 4 的个数为：4
		小于 35 岁的个数：2
	*/

	return 0;
}
```

> 总结：按值统计用 `count`，按条件统计用 `count_if`

---
