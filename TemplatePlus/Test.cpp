#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <list>
#include <array>

using namespace std;

//template<typename Container>
//void Print(const Container& v)
//{
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	Print(v);
//
//	list<int> lt;
//
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//静态栈
//#define N 100

//非类型模板参数
//template<typename T, size_t N>
//class Stack
//{
//private:
//	T _a[N];
//	int _top;
//};
//
//int main()
//{
//	/*Stack<int, 10> st1;
//	Stack<int, 100> st2;*/
//
//	array<int, 10> arr;
//	arr[0] = 0;
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//模板
//template <typename T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
//
////函数模板的特化（也可以使用函数重载）
//template <>
//bool Less<int*>(int* left, int* right)
//{
//	return *left < *right;
//}
//
//int main()
//{
//	cout << Less(1, 2) << endl;
//
//	int a = 1, b = 2;
//	cout << Less(&a, &b) << endl;
//
//	return 0;
//}

//类的特化（全特化）
template<typename T1, typename T2>
class Date
{
public:
	Date()
	{
		cout << "Date<T1, T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

//假设针对int、double要进行特殊处理
template<>
class Date<int, double>
{
public:
	Date()
	{
		cout << "Date<int, double>" << endl;
	}
private:
};

int main() 
{
	Date<int, int> d1;
	Date<int, double> d2;
}