#pragma once

#include <iostream>

using namespace std;

class Date
{
public:
	//���캯��
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//�������캯��
	Date(const Date& x)
	{
		_year = x._year;
		_month = x._month;
		_day = x._day;
	}
	//��ӡ
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//��ֵ��������أ���Ϊ��Ա��������һ������Ϊ���ص�this
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
		//�����ÿ���
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		//this�ں������������ʱ����
		return *this;
	}

	//��ʵ��ǰ����
	bool operator ==(const Date& x);
	bool operator <=(const Date& x);
	bool operator>(const Date& x);
	bool operator>=(const Date& x);
	bool operator!=(const Date& x);

	//ÿ�µ�����
	int GetMonthDay(int year, int month);	

	//d1+day
	Date& operator+=(int day);
	Date operator+(int day);

	//ǰ��++�����++
	//��Ŀ�����
	Date& operator ++();
	//�涨������++ �����μ���int����������Ϊ�˽��վ����ֵ��������ռλ����ǰ��++��������
	Date operator ++(int);

	//d1-day
	Date& operator-=(int day);
	Date operator-(int day);

	//ǰ��--�����--
	//��Ŀ�����
	Date& operator --();
	//�涨������-- �����μ���int����������Ϊ�˽��վ����ֵ��������ռλ����ǰ��--��������
	Date operator --(int);

	//Date1 - Date2
	int operator -(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};