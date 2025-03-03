#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
using namespace std;

class A {
public:
	explicit A(int a) // explicit ��ֹ��ʽ����ת��
		:_a(a)
	{}
private:
	int _a;
};

class B {
public:
	B(const A& a) {

	}
private:

};
void test_cast1() {
	int i = 1;
	//��ʽ����ת��
	double d = i;
	printf("%d %.2f\n", i, d);

	int* p = &i;
	//��ʾ��ǿ����ת��
	int address = (int)p;
	printf("%p, %d\n", p, address);

	//�������Ĺ��캯��֧����ʽ����ת��
	A a(1);
	//A a1 = 1;
	B b = a;

	//��ʽ����ת���а�ȫ����
	//const int n = 10;
	//volatile ���εı�����ÿ�ζ�Ҫȥ�ڴ���ȡ
	volatile const int n = 10;

	int* pn = (int*)&n;
	(*pn)++;
	cout << n << endl;
	cout << *pn << endl;
}

class father {
public:
	int _x = 1;
	virtual void fun(){}
};

class son : public father{
public:
	int _y = 0;
};

void fun(father* pa) {
	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻ؿ�ָ��
	son* pb = dynamic_cast<son*>(pa);
	if (pb) {
		cout << "ת���ɹ�" << endl;
		pb->_x++;
		pb->_y++;
	}
	else {
		cout << "ת��ʧ��" << endl;
	}
}
void test_cast2() {
	//���/������͵�ת��
	double d = 12.34;
	int a = static_cast<int>(d); //��̬ת����������͵�ת��
	cout << a << endl;

	//��������͵�ת��
	int* p = &a;
	int address = reinterpret_cast<int>(p);
	cout << address << endl;

	// ȥ��const����
	volatile const int n = 10;// volatile �ױ����
	int* p2 = const_cast<int*>(&n);
	cout << p2 << endl;

	//���ڽ�һ����������ָ��/���� ת��Ϊ��������ָ�������(��̬ת��)������ת����
	//����ת��������Ȼ֧�ֵģ���ֵ���ݹ�������ת����
	son b;
	father* aa = new son;
	fun(aa);
	fun(&b);

}

class AAA {
public:
	AAA(int a)
		:_a(a)
	{}

	//int���ز���Ҫ����ֵ
	//explicit ��Ӱ������ת��
	//֧���Զ�������ת��Ϊ��������
	explicit operator int() {
		return _a;
	}
	//Ҳ��������Ϊ��������
	operator bool() {
		return _a;
	}
	int _a;
};
void test() {
	//��������ת�Զ�������
	AAA a = 1;

	//�Զ�������ת��������
	int i = (int)a;
}
void test_IoStream() {
	string str;
	while (cin >> str) { 
		// 1.�Զ������ͣ�����operator>>(cin, str).operator bool()  
		// 2. �������ͣ�����cin.operator>>(str).operator bool()  
		cout << str << endl;
	}
}

class Date {
public:
	Date(int year, int month, int day)
		:_year(year)
		,_month(month)
		,_day(day)
	{}

	friend istream& operator >> (istream& in, Date& d);
	friend ostream& operator << (ostream& out, const Date& d);
private:
	int _year = 2024;
	int _month = 1;
	int _day = 1;
};

istream& operator >> (istream& in, Date& d) {
	in >> d._year >> d._month >> d._day;
	return in;
}

ostream& operator << (ostream& out, const Date& d) {
	out << d._year << " " << d._month << " " << d._day;
	return out;
}

void test_date() {
	Date d(2025, 3, 3);
	//FILE* fin = fopen("file.txt", "w");
	/*fwrite(&d, sizeof(Date), 1, fin);
	fclose(fin);*/

	//ofstream ofs("file.txt", ios_base::out | ios_base::binary);
	ofstream ofs("file.txt");
	// �Զ����Ƶķ�ʽд
	//ofs.write((const char*)&d, sizeof(d));
	//�ı��ķ�ʽд
	ofs << d;
}


struct ServerInfo
{
	char _address[32];
	// �����ƶ�д������string vector �����Ķ��������
	//����д��ȥ����һ��Ұָ�룬���������д��󣨶���ʲô�ͻ�дʲô��
	int _port;
	Date _date;
};
struct ConfigManager
{
public:
	ConfigManager(const char* filename = "file.txt")
		:_filename(filename)
	{}
	//�����ƶ�д -- �򵥸�Ч�� ȱ���ǿ�����
	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_filename, ios_base::out | ios_base::binary);
		ofs.write((const char*)&info, sizeof(info));
	}
	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_filename, ios_base::in | ios_base::binary);
		ifs.read((char*)&info, sizeof(info));
	}
	void WriteText(const ServerInfo& info)
	{
		ofstream ofs(_filename);
		ofs << info._address << " " << info._port << " " << info._date;
	}
	void ReadText(ServerInfo& info)
	{
		ifstream ifs(_filename);
		ifs >> info._address >> info._port >> info._date;
	}

private:
	string _filename; // �����ļ�
};

struct ChatInfo
{
	string _name;
	int _id; 
	Date _date;
	string _msg; 
};

void test_file() {
	/*ConfigManager cm;
	ServerInfo winfo = { "192.0.0.1", 80, { 2022, 4, 10 } };
	cm.WriteBin(winfo);*/

	/*ifstream ifs("Test.cpp");
	char ch;
	while (ifs.get(ch)) {
		cout << ch;
	}*/
	ChatInfo winfo = { "����", 135246, { 2022, 4, 10 }, "����һ�𿴵�Ӱ��"	};
	stringstream ss;
	ss << winfo._name << " " << winfo._id << " " << winfo._date << " " << winfo._msg;
	string str = ss.str();
	cout << str << endl;

}

int main()
{
	//test_cast2();
	//test_IoStream();

	//test_date();
	test_file();
	return 0;
}