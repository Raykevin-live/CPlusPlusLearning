#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//ȫ�ֱ���
//int a = 0;



//�ֲ���
//ȫ����
//int main()
//{
//	//�ֲ�����
//	int a = 1;
//
//	printf("%d\n", a);
//	// :: �������޶���������ȫ����
//	printf("%d\n", ::a);
//	return 0;
//}


//����

//�����ռ���

//int a = 0;
//
//namespace num
//{
//	int a = 1;
//}

//չ�������ռ���
//using namespace num;


// ˳�򣺾ֲ���->ȫ����Ĭ������²���ȥ�����ռ�����ȥ����
//�����������ȥ���� �����ռ���1.չ���������ռ���2.ָ�����������ռ���

//int main()
//{
//	int a = 2;
//
//	printf("%d\n", a);
//	printf("%d\n", ::a);
//	//ָ�������ռ���
//	printf("%d\n", num::a);
//
//	return 0;
//}

//������ͻ����
//namespace num
//{
//	int rand = 1;
//	namespace test
//	{
//		int rand = 2;
//	}
//}
//
////��Ҫ���չ�������ռ���
//int main()
//{
//	printf("%d\n", num::rand);
//	printf("%p\n", rand);
//	printf("%d\n", num::test::rand);
//	return 0;
//}

//cppд����û��.h
#include <iostream>
#include <list>
#include <vector>

//չ�������ռ������׳�ͻƽʱ��ϰ������ôд�������в�����
//using namespace std;

//ָ��չ����չ�����õ� ,�������Ƽ�

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