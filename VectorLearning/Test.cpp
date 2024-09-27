#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Vector.h"


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
		v1[i] = (int)i;
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
		v2.push_back((int)i);
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

//扩容 ：1.5倍 扩容
void test_vector5()
{
	size_t sz;
	vector<int> v;
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity change: " << sz << endl;
		}
	}
}

//权限被放大了，iterator 不是const类型
//要创建const 迭代器
void Print(const ling::vector<int>& v)
{
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_Myvector1()
{
	ling::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	for (size_t i = 0; i < v.size(); i++)
	{
		v[i]++;
	}

	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	Print(v);
}

void test_Myvector2()
{
	ling::vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	//insert 以后迭代器可能会失效（扩容）
	// 记住insert以后就不要使用这个形参迭代器了，因为他可能失效了
	ling::vector<int>::iterator p = v1.begin() + 3;

	v1.insert(p, 7);

	//高危行为
	//*p += 10;
	Print(v1);
}

void test_Myvector3()
{
	ling::vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	auto it = v1.begin();
	//erase 使用后也认为迭代器会失效，例如迭代器在末尾，删掉数据之后迭代器会失效
	//VS 会强制报错
	v1.erase(it);

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	/*++it;
	cout << *it << endl;*/	
}

void test_Myvector4()
{
	ling::vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	v1.pop_back();
	Print(v1);
}

int main()
{
	//test_vector5();

	test_Myvector3();

	return 0;
}