#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

bool Date::operator ==(const Date& x)
{
	return _year == x._year &&
		_month == x._month
		&& _day == x._day;
}

bool Date::operator <=(const Date& x)
{
	return *this < x || *this == x;
}

bool Date::operator>(const Date& x)
{
	return !(*this <= x);
}

bool Date::operator>=(const Date& x)
{
	return !(*this < x);
}

bool Date::operator!=(const Date& x)
{
	return !(*this == x);
}

int Date::GetMonthDay(int year, int month)
{
	// 使用静态变量，不用每次都创建数组
	static int daysArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		return 29;
	return daysArray[month];
}

// + 和 += 的复用
//方法1：
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		*this -= abs(day);
		return *this;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}

	return *this;
}

//创建临时变量少，效率高
Date Date::operator+(int day)
{
	//拷贝构造
	Date tmp(*this);

	//代码冗余可以复用
	/*tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		++tmp._month;
		if (tmp._month == 13)
		{
			++tmp._year;
			tmp._month = 1;
		}
	}*/

	tmp += day;//直接调用上面的代码

	//tmp出作用域会销毁
	return tmp;
}


//方法2：
//Date& Date::operator+=(int day)
//{
//	//赋值重载
//	*this = *this + day;
//
//	return *this;
//}
//
////创建临时变量多，效率降低
//Date Date::operator+(int day)
//{
//	//拷贝构造
//	Date tmp(*this);
//
//	//代码冗余可以复用
//	tmp._day += day;
//	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
//	{
//		tmp._day -= GetMonthDay(tmp._year, tmp._month);
//		++tmp._month;
//		if (tmp._month == 13)
//		{
//			++tmp._year;
//			tmp._month = 1;
//		}
//	}
//
//	//tmp出作用域会销毁
//	return tmp;
//}

//赋值运算符重载
Date& Date::operator ++()
{
	*this += 1;
	return *this;
}

//规定：后置++ ，传参加入int参数，不是为了接收具体的值，仅仅是占位，跟前置++构成重载
Date Date::operator ++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		*this += abs(day);
		return *this;
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_month = 12;
			--_year;
		}
		
		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

Date Date::operator-(int day)
{
	Date tmp = *this;

	tmp -= day;
	return tmp;
}

Date& Date::operator --()
{
	*this -= 1;
	return *this;
}

Date Date::operator --(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}

int Date::operator -(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (max < min)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}

	return n * flag;
}