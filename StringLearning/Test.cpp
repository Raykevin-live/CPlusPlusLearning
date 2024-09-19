#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

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

int main()
{
	//string s1;
	//string s2("张三");
	//string s3("hello world");
	//string s4(10, '*');
	//string s5(s2);

	////拷贝部分
	//string s6(s3, 6, 5);

	////运算符重载 -- 默认的自定义类型是没有重载的
	//cout << s1 << endl;
	//cout << s2 << endl;
	//cout << s4 << endl;
	//cout << s5 << endl;

	//cout << s3 << endl;
	//cout << s6 << endl;

	////流操作的运算符优先级比较高，所以要加括号
	//cout << (s1 == s2) << endl;//运算符重载
	//cout << (s1 < s2) << endl;

	/*string s1("hello");

	s1 += " ";
	s1 += "world";

	cout << s1 << endl;*/

	size_t x = 0;
	cin >> x;
	//将x转化为string 对象

	string xstr;
	while (x)
	{
		size_t val = x % 10;
		xstr += ('0' + val);
		x /= 10;
	}
	cout << xstr << endl;
	return 0;
}