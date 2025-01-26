#define _CRT_SECURE_NO_WARNINGS 1
#include "MySet.h"
#include "MyMap.h"
using namespace std;

void test_MyMap1() {
	lingze::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(7, 7));
	m.insert(make_pair(2, 2));

	auto it = m.begin();
	while (it != m.end()) {
		//it->first = 1;
		//it->second = 2;
		cout <<it->first <<":"<<it->second<< endl;
		++it;
	}
}

void test_MyMap2() {
	lingze::map<string, string> m;
	m.insert(make_pair("sort", "XXX"));
	m["sort"] = "ÅÅÐò";
	m["left"];
	auto it = m.begin();
	while (it != m.end()) {
		//it->first = 1;
		//it->second = 2;
		cout << it->first << ":" << it->second << endl;
		++it;
	}

	m["left"] = "×ó±ß";
	m["right"] = "ÓÒ±ß";

	it = m.begin();
	while (it != m.end()) {
		//it->first = 1;
		//it->second = 2;
		cout << it->first << ":" << it->second << endl;
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
		cout << *it << endl;

		/*if (*it % 2 == 0) {
			*it += 10;
		}*/
		++it;
	}

	for (const auto& e : s) {
		cout << e << endl;
	}
}
int main()
{
	test_MyMap2();
	//test_set1();
	return 0;
}