#define _CRT_SECURE_NO_WARNINGS 1
#include "AVLTree.h"

int main()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	const int N = 1000000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));
	for (size_t i = 0; i < N; i++)
	{
		v.push_back(rand());
	}
	AVLTree<int, int> t;
	for (auto e : v)
	{
		t.Insert(make_pair(e, e));
		/*if (e == 7) {
			int x = 1;
		}
		cout << "Insert: " << e << "->" << t.IsBalance() << endl;*/
	}


	return 0;
}