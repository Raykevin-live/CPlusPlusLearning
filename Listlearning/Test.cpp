#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <list>
#include <vector>

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

	//在五个位置插入数据
	//v.insert(v.begin() + 5, 10);
	//插入的区别，在于迭代器不同
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
	//while(it < lt.end()) //这种是错的，由于链表的尾的位置不确定，
		//可能是循环链表，所以要用不等于
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

int main()
{
	test_list3();

	return 0;
}