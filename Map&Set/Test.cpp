#define _CRT_SECURE_NO_WARNINGS 1
#include<map>
#include<set>
#include<iostream>

using namespace std;

void test_set1()
{
	set<int> s;
	s.insert(3);
	s.insert(2);
	s.insert(4);
	s.insert(5);
	s.insert(1);
	s.insert(5);
	s.insert(2);
	s.insert(5);

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	auto pos = s.find(3); //O(logN)

	pos = find(s.begin(), s.end(), 3); //O(N)
}
static void test_set2()
{
	//multiset<int> 
}
static void test_map1()
{
	map<string, string> dict;
	// 利用pair
	pair<string, string> kv1("insert", "插入");
	dict.insert(kv1);
	// 使用pair匿名对象
	dict.insert(pair<string, string>("sort", "排序"));
	// make_pair 函数 自动类型转换
	dict.insert(make_pair("string", "字符串"));

	//c++11 多参数的构造函数支持隐式类型转换
	dict.insert({ "string", "字符串" });
}
static void test_map2()
{
	map<string, string> dict;
	
	dict.insert(make_pair("string", "字符串"));
	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("insert", "插入"));

	map<string, string>::iterator it = dict.begin();
	//由于c++不可以返回两个值，所以封装在pair中
	while (it != dict.end()) {
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	
	for (const auto& kv : dict) {
		cout << kv.first << ": " << kv.second << endl;
	}
}
int main()
{
	//test_set1();
	test_map2();

	return 0;
}