#define _CRT_SECURE_NO_WARNINGS 1
#include "Unordered_Map.h"
#include "Unordered_Set.h"
#include <iostream>

using namespace std;


void test_My_Unordered_set1() {
	lingze::unordered_set<int> us;
	us.Insert(3);
	us.Insert(1);
	us.Insert(3);
	us.Insert(2);
	us.Insert(0);
	us.Insert(5);

	lingze::unordered_set<int>::iterator it = us.begin();
	while (it != us.end()) {
		//*it += 2;
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_My_Unordered_map1() {
	lingze::unordered_map<string, string> dict;
	dict.Insert(make_pair("sort", "≈≈–Ú"));
	dict.Insert(make_pair("left", "◊Û±ﬂ"));
	dict.Insert(make_pair("insert", "≤Â»Î"));
	dict.Insert(make_pair("sort", "xxx"));

	for (auto& kv : dict)
	{
		//kv.first += 'X';
		//kv.second += 'X';
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
	dict["right"];
	dict["sort"] = "paixu";
	for (auto& kv : dict)
	{
		//kv.first += 'X';
		//kv.second += 'X';
		cout << kv.first << ":" << kv.second << endl;
	}
}
int main()
{
	test_My_Unordered_set1();
	test_My_Unordered_map1();
	return 0;
}