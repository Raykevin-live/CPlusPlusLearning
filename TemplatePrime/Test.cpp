#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

//ģ��
//����ģ�� + ��ģ��
template<typename T>	//ģ������������������
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
	
	//���õĲ�����һ����������ģ�����ɣ�ģ���ʵ�������ɾ���ĺ���
	//��ʽʵ����
	Swap(a, b);
	Swap(c, d);

	//Swap(a, d); //��������²���ȷ���޷���������

	//��ʾʵ���� -- ��ָ��������ʵ����
	Swap<int>(b, a);

	return 0;
}