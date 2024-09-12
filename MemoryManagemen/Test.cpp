#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


//int main()
//{
// 
// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间
//还会调用构造函数和析构函数

//	//C语言
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//
//	//C++
//	int* p2 = new int;
//	delete p2;
//
//	//c语言
//	int* p3 = (int*)malloc(sizeof(int) * 10);
//	free(p3);
//
//	//C++
//	int* p4 = new int[10];
//	delete[] p4;
//	//初始化
//	int* p5 = new int(10);
//	delete p5;
//	//数组初始化, 未给定的初始化为0
//	int* p6 = new int[10]{1, 2, 3};
//	delete[] p6;
//
//	return 0;
//}

//int main()
//{
//	int* p1 = (int*)operator new(sizeof(int));
//	int* p2 = new int;
//	
//	operator delete(p1);
//	delete p2;
//
//	return 0;
//}


