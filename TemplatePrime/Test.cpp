#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

//模板
//函数模板 + 类模板
template<typename T>	//模板参数：定义的是类型
void Swap(T& x1, T& x2)
{
	T tmp = x1;
	x1 = x2;
	x2 = tmp;
}

int main()
{
	int a = 0, b = 1;
	double c = 1.1, d = 2.2;
	
	//调用的不是用一个函数，由模板生成，模板的实例化生成具体的函数
	//隐式实例化
	Swap(a, b);
	Swap(c, d);

	//Swap(a, d); //这种情况下不明确，无法推演类型

	//显示实例化 -- 用指定的类型实例化
	Swap<int>(b, a);

	return 0;
}