#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include "BinarySearchTree.h"
using namespace std;

void TestBSTree1()
{
	int a[] = { 8, 3 ,1, 10, 6, 4, 7, 14, 13 };
	BSTree<int> t;
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();
}

void TestBSTree2()
{
	int a[] = { 8, 3 ,1, 10, 6, 4, 7, 14, 13 };
	BSTree<int> t;
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.Erase(4);
	t.InOrder();
	

	t.Erase(6);
	t.InOrder();

	t.Erase(7);
	t.InOrder();

	t.Erase(7);
	t.InOrder();
}
int main()
{
	TestBSTree2();

	return 0;
}