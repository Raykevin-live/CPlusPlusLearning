#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"


//class Date
//{
//public:
//	//���캯��
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//��ֵ��������أ���Ϊ��Ա��������һ������Ϊ���ص�this
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
//	// �Ƚ����ַ�ʽ
//	/*void operator=(const Date& d)
//	{
//		_year = d._day;
//		_month = d._month;
//		_day = d._day;
//	}*/
//	//this������ʵ�κ��β�λ����ʽ�ļӣ����ǿ����ں����ڲ���ʽ�ĸ�
//	//���� ����
//	//��ֵ������Ĭ�ϳ�Ա���� ��Ҫд�ɹ��еģ����ܻ���Ĭ�����ɵ���ɳ�ͻ
//	Date& operator=(const Date& d)
//	{
//		//�����ÿ���
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		
//		//this�ں������������ʱ����
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
//	//cout << (d1.operator>(d2)) << endl;//ת��Ϊ���
//
//	//cout << (d1 < d2) << endl;
//	//cout << (d1.operator<(d2)) << endl;
//
//	//�Ѿ����ڵ���������֮��ĸ��ƿ���	-- ���������
//	d1 = d2;
//
//	//��һ���Ѿ����ڵĶ����ʼ����һ������	-- �������캯��
//	Date d3(d1); // �ȼ��ڣ�Date d3 = d1;  ����д��Ҳ�����Ѿ����ڵĶ���ȥ��ʼ����һ������
//
//
//	Date d4, d5;
//
//	//���ָ�ֵ2�����ԣ���Ϊ�������Ͷ�Ϊvoid��
//	d5 = d4 = d3;
//	return 0;
//}

//
//�ص㣺�������ʵ��

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
	// ��Ҫ++
	//ǰ��++�� ����++�Ժ�Ķ���

	++d1;// d1.opertor++(&d1);
	d1++;//d1.opertor++(&d1, 0);
	d1.Print();
	//����++�� ����++֮ǰ�Ķ���

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
	d2 += -100;//�ӵȸ���
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
	// ��Ҫ++
	//ǰ��++�� ����++�Ժ�Ķ���

	--d1;// d1.opertor--(&d1);
	d1--;//d1.opertor--(&d1, 0)
	d1.Print();
	//����++�� ����++֮ǰ�Ķ���

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
	
	//�� ������������
	//cout << d1 << d2 << d3;
	cin >> d2;
	cout << d2;
}

int main()
{
	TestDate7();

	return 0;
}

