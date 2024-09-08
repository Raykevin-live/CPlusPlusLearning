#pragma once

#include <iostream>

using namespace std;

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
	Date(const Date& x)
	{
		_year = x._year;
		_month = x._month;
		_day = x._day;
	}
	//打印
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//赋值运算符重载，作为成员函数，第一个参数为隐藏的this
	bool operator<(const Date& x2)
	{
		if (_year < x2._year)
		{
			return true;
		}
		if (_year == x2._year && _month < x2._month)
		{
			return true;
		}

		if (_year == x2._year && _month == x2._month && _day < x2._day)
		{
			return true;
		}

		return false;
	}

	Date& operator=(const Date& d)
	{
		//自身不用拷贝
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		//this在函数作用域结束时还在
		return *this;
	}

	//先实现前两个
	bool operator ==(const Date& x);
	bool operator <=(const Date& x);
	bool operator>(const Date& x);
	bool operator>=(const Date& x);
	bool operator!=(const Date& x);

	//每月的天数
	int GetMonthDay(int year, int month);	

	//d1+day
	Date& operator+=(int day);
	Date operator+(int day);

	//前置++与后置++
	//单目运算符
	Date& operator ++();
	//规定：后置++ ，传参加入int参数，不是为了接收具体的值，仅仅是占位，跟前置++构成重载
	Date operator ++(int);

	//d1-day
	Date& operator-=(int day);
	Date operator-(int day);

	//前置--与后置--
	//单目运算符
	Date& operator --();
	//规定：后置-- ，传参加入int参数，不是为了接收具体的值，仅仅是占位，跟前置--构成重载
	Date operator --(int);

	//Date1 - Date2
	int operator -(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};