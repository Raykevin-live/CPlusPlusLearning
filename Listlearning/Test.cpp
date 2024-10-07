#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <list>
#include <vector>
#include "List.h"

using namespace std;

void test_list1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	lt.push_front(10);
	lt.push_front(20);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//�����λ�ò�������
	//v.insert(v.begin() + 5, 10);
	//������������ڵ�������ͬ
	auto it = lt.begin();
	for (size_t i = 0; i < 5; i++)
	{
		++it;
	}
	lt.insert(it, 100);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list2()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	lt.push_front(10);
	lt.push_front(20);

	auto it = lt.begin();
	//while(it < lt.end()) //�����Ǵ�ģ����������β��λ�ò�ȷ����
		//������ѭ����������Ҫ�ò�����
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
}

void test_list3()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	lt.push_front(10);
	lt.push_front(20);

	auto it = lt.begin();
	
	it = find(lt.begin(), lt.end(), 3);
	if (it != lt.end())
	{
		lt.insert(it, 30);
		*it *= 100;
	}

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	it = lt.begin();
	while (it != lt.end())
	{
		if (*it % 2 == 0)
		{
			it = lt.erase(it);
		}
		else
		{
			++it;
		}
	}

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list4()
{
	std::list<int> mylist1, mylist2;
	std::list<int>::iterator it;

	// ����ֵ
	for (int i = 1; i <= 4; i++) // 1, 2, 3, 4
	{
		mylist1.push_back(i);
	}

	for (int i = 1; i <= 3; i++) // 10, 20, 30
	{
		mylist2.push_back(i*10);
	}

	for (auto e : mylist1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : mylist2)
	{
		cout << e << " ";
	}
	cout << endl << endl;

	it = mylist1.begin(); 
	++it;						//ָ���Ƶ��ڶ���λ��
	//ȫ��ת��
	//mylist1.splice(it, mylist2); // ��mylist2�����У�ת�Ƶ�mylist1��itλ��֮ǰ
	//����ת��
	//mylist1.splice(it, mylist2, ++mylist2.begin()); // ��mylist2�Ķ�Ӧλ�õ�һ������ת�Ƶ�mylist1��itλ��֮ǰ
	//mylist1.splice(mylist1.begin(), mylist1, ++mylist1.begin()); // ��mylist1�ĵڶ���λ��ת�Ƶ�mylist1�ĵ�һ��ֵ��λ��֮ǰ
	mylist1.splice(mylist1.begin(), mylist1, ++mylist1.begin(), mylist1.end()); // ��mylist1�ӵڶ���λ�ÿ�ʼת�Ƶ�mylist1�ĵ�һ��ֵ��λ��֮ǰ

	for (auto e : mylist1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : mylist2)
	{
		cout << e << " ";
	}
	cout << endl;
}

void Print(const ling::list<int>& lt)
{
	ling::list<int>::const_iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_Mylist1()
{
	ling::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	ling::list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_Mylist2()
{
	ling::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_front(5);
	lt.push_front(6);
	lt.push_front(7);
	lt.push_front(8);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.pop_back();
	lt.pop_front();

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_Mylist3()
{
	ling::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_front(5);
	lt.push_front(6);
	lt.push_front(7);
	lt.push_front(8);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.pop_back();
	lt.pop_front();

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.clear();
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_Mylist4()
{
	ling::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	ling::list<int> lt1(lt);

	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	//test_list4();
	test_Mylist4();

	return 0;
}