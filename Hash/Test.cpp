#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include "HashTable.h"

using namespace std;


void test_un_set1() {
	unordered_set<int> us;

	us.insert(1);
	us.insert(1);
	us.insert(3);
	us.insert(7);
	us.insert(10);
	us.insert(4);

	unordered_set<int>::iterator it = us.begin();
	while (it != us.end()) {
		cout << *it << endl;
		++it;
	}
}

void test_un_map1() {
	unordered_map<string, string> um;

	um["sort"] = "ÅÅÐò";
	um["insert"] = "²åÈë";
	um["string"] = "×Ö·û´®";

	for (auto& kv : um) {
		cout << kv.first << " : " << kv.second << endl;
	}
}

void test_MyHashTable1() {
	open_addr::HashTable<int, int> ht;
	int a[] = { 1, 11, 111, 4, 7, 9, 15, 25, 77 };
	for (auto e : a) {
		ht.Insert(make_pair(e, e));
	}

	ht.Erase(15);

	auto ret = ht.Find(4);
	//ret->_kv.first = 40;
	ret->_kv.second = 400;

	open_addr::HashTable<string, string> dict;
	dict.Insert(make_pair("sort", "ÅÅÐò"));
	dict.Insert(make_pair("left", "xxx"));
	auto dret = dict.Find("left");
	//dret->_kv.first = "xx";
	dret->_kv.second = "×ó±ß";


	return;
}

void test_MyHashBucket1() {
	hash_bucket::HashTable<int, int> ht;
	int a[] = { 1, 11, 111, 4, 7,  14, 24, 34};
	for (auto e : a) {
		ht.Insert(make_pair(e, e));
	}
	ht.Print();

	ht.Insert(make_pair(12, 12));
	ht.Print();

	ht.Insert(make_pair(13, 13));
	ht.Print();

	ht.Insert(make_pair(15, 15));
	ht.Print();

	ht.Erase(14);
	ht.Erase(34);
	ht.Print();

	hash_bucket::HashTable<string, string> dict;
	dict.Insert(make_pair("sort", "ÅÅÐò"));
	dict.Insert(make_pair("left", "xxx"));
	auto dret = dict.Find("left");
	//dret->_kv.first = "xx";
	dret->_kv.second = "×ó±ß";
	dict.Print();
}

void test_MyHashBucket2() {
	hash_bucket::HashTable<int, int> ht;
	int a[] = { 1, 11, 111, 4, 7,  14, 24, 34 };
	for (auto e : a) {
		ht.Insert(make_pair(e, e));
	}
	ht.Print();

	hash_bucket::HashTable<int, int>cp(ht);
	cp.Print();

	//hash_bucket::HashTable<string, string> dict;
	//dict.Insert(make_pair("sort", "ÅÅÐò"));
	//dict.Insert(make_pair("left", "xxx"));
	//auto dret = dict.Find("left");
	////dret->_kv.first = "xx";
	//dret->_kv.second = "×ó±ß";
	//dict.Print();
}

int main() {
	//test_un_set1();
	//test_un_map1();
	test_MyHashBucket2();
	return 0;
}
