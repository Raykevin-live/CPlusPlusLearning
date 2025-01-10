#define _CRT_SECURE_NO_WARNINGS 1
#include<map>
#include<set>
#include<iostream>

using namespace std;

void test_set1()
{
	set<int> s;
	s.insert(3);
	s.insert(2);
	s.insert(4);
	s.insert(5);
	s.insert(1);
	s.insert(5);
	s.insert(2);
	s.insert(5);

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	auto pos = s.find(3); //O(logN)

	pos = find(s.begin(), s.end(), 3); //O(N)
}
static void test_set2()
{
	//multiset<int> 
}
static void test_map1()
{
	map<string, string> dict;
	// ����pair
	pair<string, string> kv1("insert", "����");
	dict.insert(kv1);
	// ʹ��pair��������
	dict.insert(pair<string, string>("sort", "����"));
	// make_pair ���� �Զ�����ת��
	dict.insert(make_pair("string", "�ַ���"));

	//c++11 ������Ĺ��캯��֧����ʽ����ת��
	dict.insert({ "string", "�ַ���" });
}
static void test_map2()
{
	map<string, string> dict;
	
	dict.insert(make_pair("string", "�ַ���"));
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("insert", "����"));

	map<string, string>::iterator it = dict.begin();
	//����c++�����Է�������ֵ�����Է�װ��pair��
	while (it != dict.end()) {
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	
	for (const auto& kv : dict) {
		cout << kv.first << ": " << kv.second << endl;
	}
}
int main()
{
	//test_set1();
	test_map2();

	return 0;
}