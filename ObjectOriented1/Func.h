#pragma once
#include <string>
#include <iostream>

using namespace std;

class Stack
{
public:
	//��Ա����
	void Init(int defaultCapacity = 4);

	//������ĺ���Ĭ�Ͼ���inline, Ҫд������ֱ���ں����ڲ�д������������Ӳ��ϵ�����
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
	//��Ա����

	int* a;// ����
	int top;
	int capacity;
	//��Ա����һ��� _member
};
