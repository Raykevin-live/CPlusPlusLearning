#pragma once

#include <iostream>
#include <cassert>

using namespace std;

class Date
{
	//ȫ��+��Ԫ����������ֻ��һ���������ڹ��л���˽�ж����ԣ�
	//���������ʱ������⣬���Է�����
	friend ostream& operator <<(ostream& out, const Date& d);
	friend istream& operator >>(istream& in, Date& d);
public:
	//���캯��
	Date(int year = 1, int month = 1, int day = 1);
	
	//�������캯��
	Date(const Date& x)
	{
		_year = x._year;
		_month = x._month;
		_day = x._day;
	}
	//��ӡ
	void Print() const // �ӵ���������this* Ȩ�޿�����С������const�������ͨ���󶼿��Դ�ӡ
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//��ֵ��������أ���Ϊ��Ա��������һ������Ϊ���ص�this
	// ����֮ǰû��const��ʱ��this����ͨ��������x2��const���������Է������ȵ�ʱ��ͻ������
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
	Date operator+(int day) const;

	//ǰ��++�����++
	//��Ŀ�����
	Date& operator ++();
	//�涨������++ �����μ���int����������Ϊ�˽��վ����ֵ��������ռλ����ǰ��++��������
	Date operator ++(int);

	//d1-day
	Date& operator-=(int day);
	Date operator-(int day) const;

	//ǰ��--�����--
	//��Ŀ�����
	Date& operator --();
	//�涨������-- �����μ���int����������Ϊ�˽��վ����ֵ��������ռλ����ǰ��--��������
	Date operator --(int);

	//Date1 - Date2
	int operator -(const Date& d);
	//Date1 + Date2 û���õĲ�������
	// 
	//������
	//cout<< d1 �ұߵĶ����������
	//���⣺d1 ����д�������������ΪDate����Ĭ�ϵ�ռ�õ�һ�������������������
	//д����������������������ʹ��ϰ��
	//��������� д��ȫ��
	//void operator <<(ostream& out);

private:
	int _year = 1;
	int _month = 1;
	int _day = 1;
};

//�޷������ڲ�����ʹ����Ԫ����
//������
 ostream& operator <<(ostream& out, const Date& d);
 //����ȡ
 istream& operator >>(istream& in, Date& d);