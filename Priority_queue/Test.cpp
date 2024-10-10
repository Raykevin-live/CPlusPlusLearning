#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include "priority_queue.h"

using namespace std;

void test_priority_queue()
{
	ling::priority_queue<int> pq;
	pq.push(3);
	pq.push(5);
	pq.push(1);
	pq.push(4);
	pq.push(2);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

int main()
{
	test_priority_queue();

	return 0;
}