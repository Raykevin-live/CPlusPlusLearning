#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//全局变量
//int a = 0;



//局部域
//全局域
//int main()
//{
//	//局部变量
//	int a = 1;
//
//	printf("%d\n", a);
//	// :: 域作用限定符，优先全局域
//	printf("%d\n", ::a);
//	return 0;
//}


//类域

//命名空间域

//int a = 0;
//
//namespace num
//{
//	int a = 1;
//}

//展开命名空间域
//using namespace num;


// 顺序：局部域->全局域，默认情况下不会去命名空间域中去搜索
//有两种情况回去访问 命名空间域：1.展开了命名空间域；2.指定访问命名空间域

//int main()
//{
//	int a = 2;
//
//	printf("%d\n", a);
//	printf("%d\n", ::a);
//	//指定命名空间域
//	printf("%d\n", num::a);
//
//	return 0;
//}

//解决域冲突问题
//namespace num
//{
//	int rand = 1;
//	namespace test
//	{
//		int rand = 2;
//	}
//}
//
////不要随便展开命名空间域
//int main()
//{
//	printf("%d\n", num::rand);
//	printf("%p\n", rand);
//	printf("%d\n", num::test::rand);
//	return 0;
//}

//cpp写法，没有.h
#include <iostream>
#include <list>
#include <vector>

//展开命名空间域，容易冲突平时练习可以这么写，工程中不建议
//using namespace std;

//指定展开：展开常用的 ,工程中推荐

using std::cout;
using std::endl;

int main()
{
	cout << "hello world" << endl;
	cout << "hello world" << endl;
	cout << "hello world" << endl;
	cout << "hello world" << endl;
	cout << "hello world" << endl;
	cout << "hello world" << endl;
	cout << "hello world" << endl;


	return 0;
}