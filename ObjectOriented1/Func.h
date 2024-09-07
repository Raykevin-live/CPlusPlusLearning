#pragma once
#include <string>
#include <iostream>

using namespace std;

class Stack
{
public:
	//成员函数
	void Init(int defaultCapacity = 4);

	//类里面的函数默认就是inline, 要写内联就直接在函数内部写，避免出现链接不上的问题
	void Push(int x)
	{
		//...
		a[top++] = x;
	}

	void Destory()
	{
		free(a);
		a = nullptr;
		top = capacity;
	}

	int Top()
	{
		return a[top - 1];
	}

private:
	//成员变量

	int* a;// 声明
	int top;
	int capacity;
	//成员变量一般加 _member
};
