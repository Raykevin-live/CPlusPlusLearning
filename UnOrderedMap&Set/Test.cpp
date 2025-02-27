#define _CRT_SECURE_NO_WARNINGS 1
#include "Unordered_Map.h"
#include "Unordered_Set.h"
#include <iostream>
#include <unordered_set>
#include "BitSet.h"
#include <bitset>
#include "BloomFilter.h"

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
	dict.Insert(make_pair("sort", "ÅÅĞò"));
	dict.Insert(make_pair("left", "×ó±ß"));
	dict.Insert(make_pair("insert", "²åÈë"));
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

void test_expand1() {
	unordered_set<int> us;
	size_t old = us.bucket_count();
	cout << old << endl;

	for (int i = 0; i < 10000; i++) {
		us.insert(i);

		if (old != us.bucket_count()) {
			old = us.bucket_count();
			cout << old << endl;
		}
	}
}

void test_bitset1() {
	// ·ÇÀàĞÍÄ£°å²ÎÊıµÄÊ¹ÓÃ
	lingze::bitset<1000> bs;
	bs.set(1);
	bs.set(10);
	bs.set(100);

	cout << bs.test(1) << endl;
	cout << bs.test(10) << endl;
	cout << bs.test(100) << endl;
	cout << bs.test(999) << endl<<endl;

	bs.reset(10);
	bs.set(999);

	cout << bs.test(1) << endl;
	cout << bs.test(10) << endl;
	cout << bs.test(100) << endl;
	cout << bs.test(999) << endl;


}

void test_bloomfilter1() {
	lingze::bloomfilter<1000> bf;
	bf.set("ËïÎò¿Õ");
	bf.set("Öí°Ë½ä");

	cout << bf.test("Öí°Ë½ä") << endl;
	cout << bf.test("ËïÎò¿Õ") << endl;
	cout << bf.test("ÌÆÉ®") << endl;
}
class ABC {
private:
	int x, y;
public:
	//ABC(){}
	//ABC(int a, int b) { x = a; y = a; }
};

void test_lambda() {
	auto add = [](int a, int b) {return a + b; };
	int x = 3, y = 10;
	auto ADD = [x, &y]() mutable{return ++x; };
	auto lambda1 = [&](int a, int b)->double {return x + y; };
	ADD();
	cout << "x: " << x << " y: " << y << endl;
	cout << add(1, 2) << endl;

}
int main()
{
	/*test_My_Unordered_set1();
	test_My_Unordered_map1();*/
	//test_bitset1();
	//test_expand1();
	//test_bloomfilter1();
	test_lambda();
	return 0;
}