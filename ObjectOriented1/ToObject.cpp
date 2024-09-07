#define _CRT_SECURE_NO_WARNINGS 1

#include "Func.h"

//int main()
//{
//	//类实例化对象/对象定义
//	Stack st1;
//	Stack st2;
//
//	//不能，类访问top是声明，top不能存数据，要用st1，st2
//	//Stack::Top = 1;
//
//
//	return 0;
//}

int main()
{
	Stack st1;
	Stack st2;

	
	//对象的大小只存储成员变量，不存储成员函数
	cout << sizeof(st1) << endl;
	return 0;
}