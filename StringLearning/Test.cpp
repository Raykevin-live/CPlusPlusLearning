#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

//int main()
//{
//	string s1;
//	std::string s2;
//
//	std::string name("张飞");
//	name = "张飞";
//
//	return 0;
//}

//int main()
//{
//	//string s1;
//	//string s2("张三");
//	//string s3("hello world");
//	//string s4(10, '*');
//	//string s5(s2);
//
//	////拷贝部分
//	//string s6(s3, 6, 5);
//
//	////运算符重载 -- 默认的自定义类型是没有重载的
//	//cout << s1 << endl;
//	//cout << s2 << endl;
//	//cout << s4 << endl;
//	//cout << s5 << endl;
//
//	//cout << s3 << endl;
//	//cout << s6 << endl;
//
//	////流操作的运算符优先级比较高，所以要加括号
//	//cout << (s1 == s2) << endl;//运算符重载
//	//cout << (s1 < s2) << endl;
//
//	/*string s1("hello");
//
//	s1 += " ";
//	s1 += "world";
//
//	cout << s1 << endl;*/
//
//	size_t x = 0;
//	cin >> x;
//	//将x转化为string 对象
//
//	string xstr;
//	while (x)
//	{
//		size_t val = x % 10;
//		xstr += ('0' + val);
//		x /= 10;
//	}
//	cout << xstr << endl;
//	return 0;
//}

//int main()
//{
//	string s1("hello world");
//
//	cout << s1 << endl;
//	//遍历string 
//	//1.下标+[]
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i] << " ";//可以访问到'\0'
//	}
//	cout << endl;
//
//
//	char s3[] = "hello world";
//
//	s3[1]; // -> *(s3+1)
//	s1[1]; // -> s1.operator[](1)
//
//	//迭代器
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	//范围for
//	//底层就是迭代器
//	for (auto& ch : s1)
//	{
//		ch++;
//	}
//	for (auto ch : s1)
//	{
//		cout << ch << " ";
//	}
//	cout << endl;
//
//	//任何容器都支持迭代器
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	vector<int>::iterator vit = v.begin();
//
//	while (vit != v.end())
//	{
//		cout << *vit << " ";
//		++vit;
//	}
//	cout << endl;
//
//	//迭代器和容器配合
//	return 0;
//}

//void Func(const string& s)
//{
//	string::const_iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}

////反向迭代器
//int main()
//{
//	string s1("hello, world");
//	//string::reverse_iterator rit = s1.rbegin();
//	auto rit = s1.rbegin();
//	while (rit != s1.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	Func(s1);
//	return 0;
//}

////size（STL定义的） 和 length(刚开始定义的), 建议使用size
//int main()
//{
//
//
//	return 0;
//}

//int main()
//{
//	string s1("hello world");
//	s1.erase(5, 1);
//	cout << s1 << endl;
//
//	s1.erase(5);
//	cout << s1 << endl;
//
//	//头删
//	string s2("hello, day");
//	s2.erase(0, 1);
//	cout << s2 << endl;
//	//使用迭代器头删
//	s2.erase(s2.begin());
//	cout << s2 << endl;
//
//	return 0;
//}

//int main()
//{
//	string s1("hello world hello you");
//	
//	s1.replace(6, 5, "xxxxxxxxxxxx");// 将从第6个字符开始的后面5个字符替换为 后面的字符串
//	cout << s1 << endl;
//
//	//所有空格替换为20%
//	string s2("hello world hello you");
//	string s3;
//
//	for (auto ch : s2)
//	{
//		if (ch != ' ')
//		{
//			s3 += ch;
//		}
//		else
//		{
//			s3 += "20%";
//		}
//	}
//	//赋值
//	s2 = s3;
//	cout << s2 << endl;
//	cout << s2.c_str() << endl;//c的一些接口函数配合
//
//	return 0;
//}

//find 使用
//int main()
//{
//	string url = "https://legacy.cplusplus.com/reference/string/string/";
//	size_t pos1 = url.find("://");
//	string protocol;
//	if (pos1 != string::npos)
//	{
//		protocol = url.substr(0, pos1);
//	}
//	cout << protocol << endl;
//	string domain, uri;
//
//	size_t pos2 = url.find("/", pos1+3);
//
//
//	if (pos2 != string::npos)
//	{
//		domain = url.substr(pos1+3, pos2 - (pos1+3));
//		uri = url.substr(pos2 + 1);
//	}
//	cout << domain << endl;
//	cout << uri << endl;
//
//	return 0;
//}

#include "Mystring.h"

void test_string1()
{
	ling::string s("hello world");
	s.resize(8);
	s.resize(13, 'x');
	s.resize(20, 'y');

}

void test_string2()
{
	string s1("bb");
	string s2("aaa");
	cout << (s1 < s2) << endl; // 注意操作的优先级
}
int main()
{
	test_string2();


	return 0;
}

