#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

//class Person
//{
//	//�����˽�г�Ա�������ò���
//private:
//	
//public:
//	Person(const char* name ="Perter")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Perter& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person& operator=(const Person& p)" << endl;
//		if (this != &p)
//		{
//			_name = p._name;
//			_age = p._age;
//		}
//		return *this;
//	}
//
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name;
//	int _age;
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name = "����", int stuid = 0)
//		:_stuid(stuid)
//		, Person(name)
//	{}
//
//	Student(const Student& s)
//		:Person(s) //���ﰴ��˵��Ҫ������ı��������Ǹ������û��������������ֱ�Ӵ��������
//		//��Ϊ������󣬿��Ա����������ʽ����ת��
//		,_stuid(s._stuid)
//	{}
//
//	Student& operator=(const Student& s)
//	{
//		cout << "Student& operator=(const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator=(s);//��ֵ���������ؿ���ָ���������������ﵽĿ��
//			_stuid = s._stuid;
//		}
//		return *this;
//	}
//	~Student()
//	{
//		//���ں����̬��ԭ�����������ĺ����������⴦����
//		//ͳһ�����destrucot
//		
//		//��ʽ���ø��������������޷���֤���Ӻ�
//		//������������������ɾ��Զ����ø��࣬�����ͱ�֤�����Ӻ�
//		//Person::~Person();
//	}
//protected:
//	int _stuid;
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid;
//};

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
//int main()
//{
//	Student s;
//
//	return 0;
//}

//��������̳�
class A
{
public:
	int _a;
};

//class B : virtual public A 
//{
//public:
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//	int _c;
//};

class B : public A
{
public:
	int _b;
};

class C : public A
{
public:
	int _c;
};

class D : public B, public C
{
public:
	int _d;
};

//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	//d._a = 0;
//
//	return 0;
//}


class Person
{
public:
	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}
};

class Student : public Person
{
public:
	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }

	~Student() { cout << "~Student()" << endl; }
};

//���������������麯����Ϊʲô��
// ����������vritual, �ǲ��Ǻ�����д��
// �ǣ���Ϊ�������������Ǳ������destrctor���ͳһ������
// ΪʲôҪ��ô�����أ���ΪҪ�����ǹ�����д
// ��ΪʲôҪ�����ǹ�����д�أ�
//int main()
//{
//	Person p;
//	Student s;
//
//	return 0;
//}

//����ĳ�����
//������ڴ�й¶��û�е������������������
//int main()
//{
//	Person* p = new Person;
//	p->BuyTicket();
//	delete p;
//
//	p = new Student;
//	p->BuyTicket();
//	delete p;// p->destructor()+operator delete(p)
//	// ������������p->destructor()��һ����̬���ã���ֹ�ڴ�й©������������ͨ����
//
//	return 0;
//} 

//final ��������д�麯��
//�����಻�� vritualҲ����д����Ϊ����ʡ��
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	void Drive() { cout << "Benz-����" << endl; }
//};

//override ����������Ƿ���д���麯��(û�лᱨ��
class Car {
public:
	virtual void Drive() {}
};
class Benz :public Car {
public:
	virtual void Drive() override { cout << "Benz-����" << endl; }
};