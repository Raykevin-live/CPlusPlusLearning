#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
using namespace std;

class A {
public:
	explicit A(int a) // explicit 禁止隐式类型转换
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
	//隐式类型转换
	double d = i;
	printf("%d %.2f\n", i, d);

	int* p = &i;
	//显示的强类型转换
	int address = (int)p;
	printf("%p, %d\n", p, address);

	//单参数的构造函数支持隐式类型转换
	A a(1);
	//A a1 = 1;
	B b = a;

	//隐式类型转换有安全隐患
	//const int n = 10;
	//volatile 修饰的变量，每次都要去内存中取
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
	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回空指针
	son* pb = dynamic_cast<son*>(pa);
	if (pb) {
		cout << "转换成功" << endl;
		pb->_x++;
		pb->_y++;
	}
	else {
		cout << "转换失败" << endl;
	}
}
void test_cast2() {
	//相关/相近类型的转换
	double d = 12.34;
	int a = static_cast<int>(d); //静态转换，相近类型的转换
	cout << a << endl;

	//不相关类型的转换
	int* p = &a;
	int address = reinterpret_cast<int>(p);
	cout << address << endl;

	// 去掉const属性
	volatile const int n = 10;// volatile 易变变量
	int* p2 = const_cast<int*>(&n);
	cout << p2 << endl;

	//用于将一个父类对象的指针/引用 转换为子类对象的指针或引用(动态转换)（向下转换）
	//子类转父类是天然支持的，赋值兼容规则（向上转换）
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

	//int重载不需要返回值
	//explicit 不影响类型转换
	//支持自定义类型转换为内置类型
	explicit operator int() {
		return _a;
	}
	//也可以重载为其他类型
	operator bool() {
		return _a;
	}
	int _a;
};
void test() {
	//内置类型转自定义类型
	AAA a = 1;

	//自定义类型转内置类型
	int i = (int)a;
}
void test_IoStream() {
	string str;
	while (cin >> str) { 
		// 1.自定义类型：调用operator>>(cin, str).operator bool()  
		// 2. 内置类型：调用cin.operator>>(str).operator bool()  
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
	// 以二进制的方式写
	//ofs.write((const char*)&d, sizeof(d));
	//文本的方式写
	ofs << d;
}


struct ServerInfo
{
	char _address[32];
	// 二进制读写不能用string vector 这样的对象存数据
	//否则写进去就是一个野指针，读进来会有错误（读到什么就会写什么）
	int _port;
	Date _date;
};
struct ConfigManager
{
public:
	ConfigManager(const char* filename = "file.txt")
		:_filename(filename)
	{}
	//二进制读写 -- 简单高效， 缺点是看不懂
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
	string _filename; // 配置文件
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
	ChatInfo winfo = { "张三", 135246, { 2022, 4, 10 }, "晚上一起看电影吧"	};
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