#define _CRT_SECURE_NO_WARNINGS 1

#include "Func.h"

//�����뺯������д�������еĳ�Ա����
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