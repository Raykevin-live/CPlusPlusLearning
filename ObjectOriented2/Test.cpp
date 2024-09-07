#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

//class Date
//{
//public:
//	// 1.�޲ι��캯��
//	Date()
//	{}
//
//	// 2.���ι��캯��
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	//��������
//	//C++11֧�֣����ﲻ�ǳ�ʼ������Ϊ����ֻ������
//	//���������Ĭ�ϵ�ȱʡֵ��������������Ĭ�Ϲ��캯����
//	int _year = 1;
//	int _month = 1;
//	int _day = 1;
//};
//
//void TestDate()
//{
//	Date d1; // �����޲ι��캯��
//	Date d2(2015, 1, 1); // ���ô��εĹ��캯��
//
//
//	// ע�⣺���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺�������
//	// ���´���ĺ�����������d3�������ú����޲Σ�����һ���������͵Ķ���
//	// warning C4930: ��Date d3(void)��: δ����ԭ�ͺ���(�Ƿ��������ñ��������?)
//	Date d3();
//}


//typedef int DataType;
//class Stack
//{
//public:
//	//���ι��캯��
//	Stack(size_t capacity = 3)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc����ռ�ʧ��!!!");
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
//	// ��������������
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
//	//��������
//	DataType* _array;
//	int _capacity;
//	int _size;
//
//	//�Զ�������
//	//Stack _st;
//};
//
//void TestStack()
//{
//	Stack s;
//	s.Push(1);
//	s.Push(2);
//}

//��ϰ
//class Stack
//{
//public:
//	//���캯��
//	//1.�޲Σ�������д�޲�
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
//	//2.ȫȱʡ
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
//	//��������
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_capacity = _top = 0;
//	}
//private:
//	//���ó�Ա��ø���ʼ��
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


//��������
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
	/*C++�涨��
		��������ֱ�ӿ�����
		�Զ������ͱ�����ÿ���������ɿ�����*/
	//Date(Date d) //��ֵ�������
	//Date(Date& d)//�����ã�d����d1�ı�����Ҳ����ʹ��ָ��
	//Date(const Date& d)
	//{
	//	cout << "Date(Date& d)" << endl;
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//	//Ҫע��д����������ֿ��Լ���const����
	//	/*d._year = _year;
	//	d._month = _month;
	//	d._year = _day;*/
	//}

//private:
	int _year;
	int _month;
	int _day;
};

//�Ƚ�
//��������Ҫ����������
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
	//Date d1; // �����޲ι��캯��
	//Date d2(2015, 1, 1);// ����ȫȱʡ���캯��
	
	////����Ϊ�������ͣ�����ʵ��ǳ�����������Լ�д�������캯���������Զ�ʵ��
	////�����漰����̬����ʱ��һ��Ҫ�Լ�ʵ�ֿ������캯����ʵ�����
	//Date d3(d2);//�������캯��

	//Ϊʲô�������Ϳ���ֱ�ӱȽϴ�С�����Զ������Ͳ�����
	Date d1(2025, 3, 4);
	Date d2(2025, 4, 4);

	cout << (d1 > d2) << endl;
	cout << (operator>(d1, d2)) << endl;

	cout << (d1 < d2) << endl;
	cout << (operator<(d1, d2)) << endl;

	return 0;
}
