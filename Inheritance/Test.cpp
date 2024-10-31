#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class Person
{
	//�����˽�г�Ա�������ò���
private:
	
public:
	Person(const char* name ="Perter")
		:_name(name)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
		:_name(p._name)
	{
		cout << "Person(const Perter& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person& operator=(const Person& p)" << endl;
		if (this != &p)
		{
			_name = p._name;
			_age = p._age;
		}
		return *this;
	}

	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name;
	int _age;
};

class Student : public Person
{
public:
	Student(const char* name = "����", int stuid = 0)
		:_stuid(stuid)
		, Person(name)
	{}

	Student(const Student& s)
		:Person(s) //���ﰴ��˵��Ҫ������ı��������Ǹ������û��������������ֱ�Ӵ��������
		//��Ϊ������󣬿��Ա����������ʽ����ת��
		,_stuid(s._stuid)
	{}

	Student& operator=(const Student& s)
	{
		cout << "Student& operator=(const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator=(s);//��ֵ���������ؿ���ָ���������������ﵽĿ��
			_stuid = s._stuid;
		}
		return *this;
	}
	~Student()
	{
		//���ں����̬��ԭ�����������ĺ����������⴦����
		//ͳһ�����destrucot
		
		//��ʽ���ø��������������޷���֤���Ӻ�
		//������������������ɾ��Զ����ø��࣬�����ͱ�֤�����Ӻ�
		//Person::~Person();
	}
protected:
	int _stuid;
};

class Teacher : public Person
{
protected:
	int _jobid;
};

//�̳�
//int main()
//{
//	Person p;
//	Student s;
//	Teacher t;
//	s.Print();
//	t.Print();
//	//�Ӹ������ǿ��Ե�
//	p = s;
//
//	int i = 0;
//	//double& d = i; // ��������Ϊ��ʱ�������г���
//	const double& d = i;
//
//	//��ֵ����(�и�\��Ƭ��
//	Person p1 = s;
//	Person& rp = s;//���ò�������ʱ������ֻ���г������ֵı���
//
//	return 0;
//}

// �������ʼ���б�
int main()
{
	Student s;

	return 0;
}