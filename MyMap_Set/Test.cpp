#define _CRT_SECURE_NO_WARNINGS 1
#include "MySet.h"
#include "MyMap.h"
using namespace std;

void test_MySet1() {
	lingze::map<int, int> m;
	m.Insert(make_pair(1, 1));
	m.Insert(make_pair(3, 3));
	m.Insert(make_pair(7, 7));
	m.Insert(make_pair(2, 2));

	auto it = m.begin();
	while (it != m.end()) {
		cout <<it->first <<":"<<it->second<< endl;
		++it;
	}
}

void test_set1() {
	lingze::set<int> s;
	s.Insert(3);
	s.Insert(7);
	s.Insert(8);
	s.Insert(6);

	auto it = s.begin();
	while (it != s.end()) {
		cout << *it<< endl;
		++it;
	}
}
int main()
{
	test_MySet1();
	test_set1();
	return 0;
}