#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

//class Date
//{
//public:
//	// 1.无参构造函数
//	Date()
//	{}
//
//	// 2.带参构造函数
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	//内置类型
//	//C++11支持，这里不是初始化，因为这里只是声明
//	//这里给的是默认的缺省值，给编译器生成默认构造函数用
//	int _year = 1;
//	int _month = 1;
//	int _day = 1;
//};
//
//void TestDate()
//{
//	Date d1; // 调用无参构造函数
//	Date d2(2015, 1, 1); // 调用带参的构造函数
//
//
//	// 注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
//	// 以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象
//	// warning C4930: “Date d3(void)”: 未调用原型函数(是否是有意用变量定义的?)
//	Date d3();
//}


//typedef int DataType;
//class Stack
//{
//public:
//	//带参构造函数
//	Stack(size_t capacity = 3)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	// 析构函数，销毁
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0; 
//		}
//	}
//private:
//	//内置类型
//	DataType* _array;
//	int _capacity;
//	int _size;
//
//	//自定义类型
//	//Stack _st;
//};
//
//void TestStack()
//{
//	Stack s;
//	s.Push(1);
//	s.Push(2);
//}

//练习
//class Stack
//{
//public:
//	//构造函数
//	//1.无参，不建议写无参
//	/*Stack()
//	{
//		cout << "Stack()" << endl;
//		_a = (int*)malloc(sizeof(int) * 4);
//		if (nullptr == _a)
//		{
//			perror("malloc fail");
//			return;
//		}
//
//		_capacity = 4;
//		_top = 0;
//	}*/
//	//2.全缺省
//	Stack(int defaultcapacity = 4)
//	{
//		cout << "Stack()" << endl;
//		_a = (int*)malloc(sizeof(int) * defaultcapacity);
//		if (nullptr == _a)
//		{
//			perror("malloc fail");
//			return;
//		}
//
//		_capacity = defaultcapacity;
//		_top = 0;
//	}
//	//析构函数
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_capacity = _top = 0;
//	}
//private:
//	//内置成员最好给初始化
//	int* _a = nullptr;
//	int _top = 0;
//	int _capacity = 0;
//};
//
//int main()
//{
//	Stack st1;
//
//	return 0;
//}


//拷贝构造
class Date
{
public:
	//构造函数
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//拷贝构造函数
	/*C++规定：
		内置类型直接拷贝；
		自定义类型必须调用拷贝函数完成拷贝；*/
	//Date(Date d) //传值会出问题
	//Date(Date& d)//传引用，d就是d1的别名，也可以使用指针
	//Date(const Date& d)
	//{
	//	cout << "Date(Date& d)" << endl;
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//	//要注意写反的情况出现可以加入const修饰
	//	/*d._year = _year;
	//	d._month = _month;
	//	d._year = _day;*/
	//}

//private:
	int _year;
	int _month;
	int _day;
};

//比较
//操作符，要放在类外面
bool operator<(const Date& x1, const Date& x2)
{
	if (x1._year < x2._year)
	{
		return true;
	}
	if (x1._year == x2._year && x1._month < x2._month)
	{
		return true;
	}

	if (x1._year == x2._year && x1._month == x2._month && x1._day < x2._day)
	{
		return true;
	}

	return false;
}

bool operator > (const Date& x1, const Date& x2)
{
	if (x1._year > x2._year)
	{
		return true;
	}
	if (x1._year == x2._year && x1._month > x2._month)
	{
		return true;
	}

	if (x1._year == x2._year && x1._month == x2._month && x1._day > x2._day)
	{
		return true;
	}

	return false;
}

int main()
{
	//Date d1; // 调用无参构造函数
	//Date d2(2015, 1, 1);// 调用全缺省构造函数
	
	////日期为内置类型，可以实现浅拷贝，不用自己写拷贝构造函数，可以自动实现
	////但是涉及到动态数据时，一定要自己实现拷贝构造函数，实现深拷贝
	//Date d3(d2);//拷贝构造函数

	//为什么内置类型可以直接比较大小，而自定义类型不可以
	Date d1(2025, 3, 4);
	Date d2(2025, 4, 4);

	cout << (d1 > d2) << endl;
	cout << (operator>(d1, d2)) << endl;

	cout << (d1 < d2) << endl;
	cout << (operator<(d1, d2)) << endl;

	return 0;
}
