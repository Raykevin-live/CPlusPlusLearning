#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

//int main()
//{
//	string s1;
//	std::string s2;
//
//	std::string name("�ŷ�");
//	name = "�ŷ�";
//
//	return 0;
//}

int main()
{
	//string s1;
	//string s2("����");
	//string s3("hello world");
	//string s4(10, '*');
	//string s5(s2);

	////��������
	//string s6(s3, 6, 5);

	////��������� -- Ĭ�ϵ��Զ���������û�����ص�
	//cout << s1 << endl;
	//cout << s2 << endl;
	//cout << s4 << endl;
	//cout << s5 << endl;

	//cout << s3 << endl;
	//cout << s6 << endl;

	////����������������ȼ��Ƚϸߣ�����Ҫ������
	//cout << (s1 == s2) << endl;//���������
	//cout << (s1 < s2) << endl;

	/*string s1("hello");

	s1 += " ";
	s1 += "world";

	cout << s1 << endl;*/

	size_t x = 0;
	cin >> x;
	//��xת��Ϊstring ����

	string xstr;
	while (x)
	{
		size_t val = x % 10;
		xstr += ('0' + val);
		x /= 10;
	}
	cout << xstr << endl;
	return 0;
}