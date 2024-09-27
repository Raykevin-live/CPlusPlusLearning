#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void test_vector1()
{
	vector<string> v;

	string name1("张三");
	v.push_back(name1);

	v.push_back(string("张三"));
	//单参数的构造函数支持隐式类型转换
	v.push_back("张三");
}

//int main()
//{
//	//显式实例化
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2); 
//	v.push_back(3);
//	v.push_back(4);
//
//
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	test_vector1();
//
//	return 0;
//}

//初始化
void test_vector2()
{
	//使用n个元素初始化
	vector<int> v1(10, 1);
	vector<string> v2(10, "***");

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

	//用自己类型迭代器初始化
	vector<int> v3(v1.begin(), v1.end());
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;

	//字符串初始化
	string str("hello world");
	vector<char> v4(str.begin(), str.end());
	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;
	sort(str.begin(), str.end());
	cout << str << endl;

	//用数组的指针初始化
	int a[] = { 3, 1, 57, 0 };
	vector<int> v5(a, a + 4);
	for (auto e : v5)
	{
		cout << e << " ";
	}
	cout << endl;
	sort(a, a + 4);
	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;

	//排序 -- 容器与算法的关联与使用
	sort(v5.begin(), v5.end());//升序(默认) <
	//sort(v5.rbegin(), v5.rend()); // 可以使用反向迭代器去遍历排降序
	//降序 >
	for (auto e : v5)
	{
		cout << e << " ";
	}
	cout << endl;

	sort(v5.begin(), v5.end(), greater<int>());// greater<int>() 匿名对象
	for (auto e : v5)
	{
		cout << e << " ";
	}
	cout << endl;
	
}

//reserve 和 resize 的区别
void test_vector3()
{
	vector<int> v1;
	// 使用reserve 时要注意使用方括号操作符，
	// 因为方括号需要判断数据的有效性，不是根据capacity的值
	//v1.reserve(10);
	v1.resize(10);
	for (size_t i = 0; i < 10; i++)
	{
		v1[i] = i;
	}
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v2;
	v2.reserve(10);
	for (size_t i = 0; i < 10; i++)
	{
		v2.push_back(i);
	}
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
}

//头删 erase 和头插 insert
void test_vector4()
{
	int a[] = { 16,2,77,29,3,33,43,3,2,3,3,2 };
	vector<int> v1(a, a + sizeof(a)/sizeof(int));
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	//头删
	v1.erase(v1.begin());
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	//头插
	v1.insert(v1.begin(), 100);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	// 删除第3个数据
	v1.erase(v1.begin() + 2);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}


int main()
{
	test_vector4();

	return 0;
}