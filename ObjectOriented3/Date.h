#pragma once

#include <iostream>
#include <cassert>

using namespace std;

class Date
{
	//全局+友元函数声明（只是一个声明，在公有或者私有都可以）
	//连续输出流时会出问题，所以返回流
	friend ostream& operator <<(ostream& out, const Date& d);
	friend istream& operator >>(istream& in, Date& d);
public:
	//构造函数
	Date(int year = 1, int month = 1, int day = 1);
	
	//拷贝构造函数
	Date(const Date& x)
	{
		_year = x._year;
		_month = x._month;
		_day = x._day;
	}
	//打印
	void Print() const // 加到这里修饰this* 权限可以缩小，这样const对象和普通对象都可以打印
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//赋值运算符重载，作为成员函数，第一个参数为隐藏的this
	// 这里之前没有const的时候，this是普通参数，而x2是const参数，所以反过来比的时候就会出问题
	bool operator<(const Date& x2) const 
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
	Date operator+(int day) const;

	//前置++与后置++
	//单目运算符
	Date& operator ++();
	//规定：后置++ ，传参加入int参数，不是为了接收具体的值，仅仅是占位，跟前置++构成重载
	Date operator ++(int);

	//d1-day
	Date& operator-=(int day);
	Date operator-(int day) const;

	//前置--与后置--
	//单目运算符
	Date& operator --();
	//规定：后置-- ，传参加入int参数，不是为了接收具体的值，仅仅是占位，跟前置--构成重载
	Date operator --(int);

	//Date1 - Date2
	int operator -(const Date& d);
	//Date1 + Date2 没有用的不用重载
	// 
	//流插入
	//cout<< d1 右边的对象流向左边
	//问题：d1 必须写在左操作数，因为Date对象默认的占用第一个参数，就是左操作数
	//写出来就是下面这样不符合使用习惯
	//解决方法： 写到全局
	//void operator <<(ostream& out);

private:
	int _year = 1;
	int _month = 1;
	int _day = 1;
};

//无法访问内部对象，使用友元函数
//流插入
 ostream& operator <<(ostream& out, const Date& d);
 //流提取
 istream& operator >>(istream& in, Date& d);