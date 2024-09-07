#define _CRT_SECURE_NO_WARNINGS 1

#include "Func.h"

//声明与函数分离写法，类中的成员函数
void Stack::Init(int defalutCapacity)
{
	a = (int*)malloc(sizeof(int) * capacity);
	if (nullptr == a)
	{
		perror("malloc fail");
		return;
	}

	capacity = defalutCapacity;
	top = 0;

}