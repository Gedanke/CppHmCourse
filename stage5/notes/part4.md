# STL 函数对象

---

## 函数对象

### 函数对象概念

**概念**：

* 重载 **函数调用操作符** 的类，其对象常称为 **函数对象**
* **函数对象** 使用重载的 `()` 时，行为类似函数调用，也叫 **仿函数**

**本质**：

函数对象(仿函数)是一个 **类**，不是一个函数

---

### 函数对象使用

**特点**：

* 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
* 函数对象超出普通函数的概念，函数对象可以有自己的状态
* 函数对象可以作为参数传递

demo:

```cpp
#include <iostream>

using namespace std;

// 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

void test1()
{
    MyAdd myAdd;
    cout << myAdd(10, 10) << endl;
}

// 函数对象可以有自己的状态
class MyPrint
{
public:
    // 内部自己的状态
    int count;

public:
    MyPrint()
    {
        this->count = 0;
    }

    void operator()(string test)
    {
        cout << test << endl;
        // 统计使用次数
        this->count++;
    }
};

void test2()
{
    MyPrint myPrint;
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    cout << "myPrint 调用次数为：" << myPrint.count << endl;
}

// 函数对象可以作为参数传递
void doPrint(MyPrint &mp, string test)
{
    mp(test);
}

void test3()
{
    MyPrint myPrint;
    doPrint(myPrint, "Hello C++");
}

int main()
{
    test1();
    test2();
    test3();

    /*
        20
        hello world
        hello world
        hello world
        myPrint 调用次数为：3
        Hello C++
    */

    return 0;
}
```

> 仿函数写法非常灵活，可以作为参数进行传递

---

## 谓词

### 谓词概念

**概念**：

* 返回 `bool` 类型的仿函数称为 **谓词**
* 如果 `operator()` 接受一个参数，那么叫做一元谓词
* 如果 `operator()` 接受两个参数，那么叫做二元谓词

### 一元谓词

demo:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 一元谓词
struct GreaterFive
{
	bool operator()(int val)
	{
		return val > 5;
	}
};

// 公共权限
class MoreFive
{
public:
	bool operator()(int val)
	{
		return val > 8;
	}
};

void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		cout << "没找到!" << endl;
	}
	else
	{
		cout << "找到: " << *it << endl;
	}

	vector<int>::iterator p = find_if(v.begin(), v.end(), MoreFive());
	if (p == v.end())
	{
		cout << "没找到!" << endl;
	}
	else
	{
		cout << "找到: " << *p << endl;
	}
}

int main()
{
	test1();

	/*
		找到: 6
		找到: 9
	*/

	return 0;
}
```

> 总结：参数只有一个的谓词，称为一元谓词

### 二元谓词

demo:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 二元谓词
class MyCompare
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2;
	}
};

void test1()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);

	// 默认从小到大
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "----------------------------" << endl;

	// 使用函数对象改变算法策略，排序从大到小
	sort(v.begin(), v.end(), MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test1();

	/*
		10 20 30 40 50
		----------------------------
		50 40 30 20 10
	*/

	return 0;
}
```

## 内建函数对象

### 内建函数对象意义

**概念**：

* STL 内建了一些函数对象

**分类**:

* 算术仿函数
* 关系仿函数
* 逻辑仿函数

**用法**：

* 这些仿函数所产生的对象，用法和一般函数完全相同
* 使用内建函数对象，需要引入头文件 `#include<functional>`

### 算术仿函数

**功能描述**：

* 实现四则运算
* 其中 `negate` 是一元运算，其他都是二元运算

**仿函数原型**：

* `template<class T> T plus<T>` 加法仿函数
* `template<class T> T minus<T>`    减法仿函数
* `template<class T> T multiplies<T>`   乘法仿函数
* `template<class T> T divides<T>`  除法仿函数
* `template<class T> T modulus<T>`  取模仿函数
* `template<class T> T negate<T>`   取反仿函数

demo:

```cpp
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
```

> 总结：使用内建函数对象时，需要引入头文件 `#include <functional>`

---

### 关系仿函数

**功能描述**：

* 实现关系对比

**仿函数原型**：

* `template<class T> bool equal_to<T>`  等于
* `template<class T> bool not_equal_to<T>`  不等于
* `template<class T> bool greater<T>`   大于
* `template<class T> bool greater_equal<T>` 大于等于
* `template<class T> bool less<T>`  小于
* `template<class T> bool less_equal<T>`    小于等于

demo:

```cpp
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

class MyCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

class Person
{
public:
	string name;
	int score;

public:
	Person(string name, int score)
	{
		this->name = name;
		this->score = score;
	}

	bool operator>(const Person &p) const
	{
		return this->score > p.score;
	}

	bool operator<(const Person &p) const
	{
		return this->score < p.score;
	}

	void show()
	{
		cout << "Name: " << this->name << " Score: " << this->score << endl;
	}
};

class ComparePerson
{
public:
	bool operator()(const Person &p1, const Person &p2)
	{
		return p1.score < p2.score;
	}
};

void test1()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 自己实现仿函数
	// sort(v.begin(), v.end(), MyCompare());
	// STL 内建仿函数，大于仿函数
	sort(v.begin(), v.end(), greater<int>());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	sort(v.begin(), v.end(), less<int>());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test2()
{
	string nameSeed = "ABCDEDF";
	vector<Person> v;
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "person";
		name += nameSeed[i];
		Person p(name, i * 10 + 30);
		v.push_back(p);
	}

	sort(v.begin(), v.end(), greater<Person>());
	for (auto it = v.begin(); it != v.end(); it++)
	{
		it->show();
	}

	cout << "=========" << endl;

	sort(v.begin(), v.end(), ComparePerson());
	for (auto it = v.begin(); it != v.end(); it++)
	{
		it->show();
	}
}

int main()
{
	test1();

	test2();

	/*
		10 30 50 40 20
		50 40 30 20 10
		10 20 30 40 50
		Name: personF Score: 90
		Name: personD Score: 80
		Name: personE Score: 70
		Name: personD Score: 60
		Name: personC Score: 50
		Name: personB Score: 40
		Name: personA Score: 30
		=========
		Name: personA Score: 30
		Name: personB Score: 40
		Name: personC Score: 50
		Name: personD Score: 60
		Name: personE Score: 70
		Name: personD Score: 80
		Name: personF Score: 90
	*/

	return 0;
}
```

> 总结：关系仿函数中最常用的就是 `greater<>` 大于

> 对于自定义类型，在类中重载相关运算符即可

### 逻辑仿函数

**功能描述**：

* 实现逻辑运算

**函数原型**：

* `template<class T> bool logical_and<T>`   逻辑与
* `template<class T> bool logical_or<T>`    逻辑或
* `template<class T> bool logical_not<T>`   逻辑非

demo:

```cpp
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

void test1()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 逻辑非，将 v 容器搬运到 v2 中，并执行逻辑非运算
	vector<bool> v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test1();

	/*
		1 0 1 0
		0 1 0 1
	*/

	return 0;
}
```

> 总结：逻辑仿函数实际应用较少，了解即可

---
