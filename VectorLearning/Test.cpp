#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Vector.h"


using namespace std;

void test_vector1()
{
	vector<string> v;

	string name1("����");
	v.push_back(name1);

	v.push_back(string("����"));
	//�������Ĺ��캯��֧����ʽ����ת��
	v.push_back("����");
}

//int main()
//{
//	//��ʽʵ����
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2); 
//	v.push_back(3);
//	v.push_back(4);
//
//
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	test_vector1();
//
//	return 0;
//}

//��ʼ��
void test_vector2()
{
	//ʹ��n��Ԫ�س�ʼ��
	vector<int> v1(10, 1);
	vector<string> v2(10, "***");

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

	//���Լ����͵�������ʼ��
	vector<int> v3(v1.begin(), v1.end());
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;

	//�ַ�����ʼ��
	string str("hello world");
	vector<char> v4(str.begin(), str.end());
	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;
	sort(str.begin(), str.end());
	cout << str << endl;

	//�������ָ���ʼ��
	int a[] = { 3, 1, 57, 0 };
	vector<int> v5(a, a + 4);
	for (auto e : v5)
	{
		cout << e << " ";
	}
	cout << endl;
	sort(a, a + 4);
	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;

	//���� -- �������㷨�Ĺ�����ʹ��
	sort(v5.begin(), v5.end());//����(Ĭ��) <
	//sort(v5.rbegin(), v5.rend()); // ����ʹ�÷��������ȥ�����Ž���
	//���� >
	for (auto e : v5)
	{
		cout << e << " ";
	}
	cout << endl;

	sort(v5.begin(), v5.end(), greater<int>());// greater<int>() ��������
	for (auto e : v5)
	{
		cout << e << " ";
	}
	cout << endl;
	
}

//reserve �� resize ������
void test_vector3()
{
	vector<int> v1;
	// ʹ��reserve ʱҪע��ʹ�÷����Ų�������
	// ��Ϊ��������Ҫ�ж����ݵ���Ч�ԣ����Ǹ���capacity��ֵ
	//v1.reserve(10);
	v1.resize(10);
	for (size_t i = 0; i < 10; i++)
	{
		v1[i] = (int)i;
	}
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v2;
	v2.reserve(10);
	for (size_t i = 0; i < 10; i++)
	{
		v2.push_back((int)i);
	}
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
}

//ͷɾ erase ��ͷ�� insert
void test_vector4()
{
	int a[] = { 16,2,77,29,3,33,43,3,2,3,3,2 };
	vector<int> v1(a, a + sizeof(a)/sizeof(int));
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	//ͷɾ
	v1.erase(v1.begin());
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	//ͷ��
	v1.insert(v1.begin(), 100);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	// ɾ����3������
	v1.erase(v1.begin() + 2);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}

//���� ��1.5�� ����
void test_vector5()
{
	size_t sz;
	vector<int> v;
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity change: " << sz << endl;
		}
	}
}

//Ȩ�ޱ��Ŵ��ˣ�iterator ����const����
//Ҫ����const ������
void Print(const ling::vector<int>& v)
{
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_Myvector1()
{
	ling::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	for (size_t i = 0; i < v.size(); i++)
	{
		v[i]++;
	}

	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	Print(v);
}

void test_Myvector2()
{
	ling::vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	//insert �Ժ���������ܻ�ʧЧ�����ݣ�
	// ��סinsert�Ժ�Ͳ�Ҫʹ������βε������ˣ���Ϊ������ʧЧ��
	ling::vector<int>::iterator p = v1.begin() + 3;

	v1.insert(p, 7);

	//��Σ��Ϊ
	//*p += 10;
	Print(v1);
}

void test_Myvector3()
{
	ling::vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	auto it = v1.begin();
	//erase ʹ�ú�Ҳ��Ϊ��������ʧЧ�������������ĩβ��ɾ������֮���������ʧЧ
	//VS ��ǿ�Ʊ���
	v1.erase(it);

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	/*++it;
	cout << *it << endl;*/	
}

void test_Myvector4()
{
	ling::vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	v1.pop_back();
	Print(v1);
}

int main()
{
	//test_vector5();

	test_Myvector3();

	return 0;
}