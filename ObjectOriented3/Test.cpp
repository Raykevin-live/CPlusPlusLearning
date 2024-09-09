#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"


//class Date
//{
//public:
//	//构造函数
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//赋值运算符重载，作为成员函数，第一个参数为隐藏的this
//	bool operator<( const Date& x2)
//	{
//		if (_year < x2._year)
//		{
//			return true;
//		}
//		if (_year == x2._year && _month < x2._month)
//		{
//			return true;
//		}
//
//		if (_year == x2._year && _month == x2._month && _day < x2._day)
//		{
//			return true;
//		}
//
//		return false;
//	}
//	bool operator>(const Date& x2)
//	{
//		if (_year > x2._year)
//		{
//			return true;
//		}
//		if (_year == x2._year && _month > x2._month)
//		{
//			return true;
//		}
//
//		if (_year == x2._year && _month == x2._month && _day > x2._day)
//		{
//			return true;
//		}
//
//		return false;
//	}
//	// 比较两种方式
//	/*void operator=(const Date& d)
//	{
//		_year = d._day;
//		_month = d._month;
//		_day = d._day;
//	}*/
//	//this不能在实参和形参位置显式的加，但是可以在函数内部显式的给
//	//返回 别名
//	//赋值重载是默认成员函数 不要写成公有的，可能会与默认生成的造成冲突
//	Date& operator=(const Date& d)
//	{
//		//自身不用拷贝
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		
//		//this在函数作用域结束时还在
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//int main()
//{
//	//
//	Date d1(2025, 3, 4);
//	Date d2(2025, 4, 4);
//
//	//cout << (d1 > d2) << endl;
//	//cout << (d1.operator>(d2)) << endl;//转化为这个
//
//	//cout << (d1 < d2) << endl;
//	//cout << (d1.operator<(d2)) << endl;
//
//	//已经存在的两个对象之间的复制拷贝	-- 运算符重载
//	d1 = d2;
//
//	//用一个已经存在的对象初始化另一个对象	-- 拷贝构造函数
//	Date d3(d1); // 等价于：Date d3 = d1;  这种写法也是拿已经存在的对象去初始化另一个对象
//
//
//	Date d4, d5;
//
//	//这种赋值2不可以，因为返回类型定为void了
//	d5 = d4 = d3;
//	return 0;
//}

//
//重点：日期类的实现

void TestDate1()
{
	Date d1(2024, 9, 8);
	d1 += 100;
	d1.Print();

	Date d2(2024, 9, 8);
	Date d3(d2 + 100);
	d2.Print();
	d3.Print();
}

void TestDate2()
{
	Date d1(2024, 9, 8);
	// 都要++
	//前置++， 返回++以后的对象

	++d1;// d1.opertor++(&d1);
	d1++;//d1.opertor++(&d1, 0);
	d1.Print();
	//后置++， 返回++之前的对象

}


void TestDate3()
{
	Date d1(2024, 9, 8);
	
	d1 -= 100;
	d1.Print();

	Date d2 = d1 - 100;
	d2.Print();
}

void TestDate4()
{
	Date d1(2024, 9, 8);
	d1 += 100;
	d1.Print();

	Date d2(2024, 10, 1);
	d2 += -100;//加等负数
	d2.Print();

	Date d3(2024, 9, 8);
	d3 -= 100;
	d3.Print();
	d3 -= -100;
	d3.Print();

}

void TestDate5()
{
	Date d1(2024, 9, 8);
	// 都要++
	//前置++， 返回++以后的对象

	--d1;// d1.opertor--(&d1);
	d1--;//d1.opertor--(&d1, 0)
	d1.Print();
	//后置++， 返回++之前的对象

}

void TestDate6()
{
	Date d1(2023, 1, 1);
	Date d2(2023, 2, 3);

	int ret = d2 - d1;
	cout << ret << endl;
}

void TestDate7()
{
	Date d1(2023, 1, 1);
	Date d2(2024, 1, 1);
	Date d3(2025, 1, 1);
	
	//流 ：从左往右流
	//cout << d1 << d2 << d3;
	cin >> d2;
	cout << d2;
}

int main()
{
	TestDate7();

	return 0;
}

