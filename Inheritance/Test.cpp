#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

//class Person
//{
//	//父类的私有成员，子类用不了
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
//	Student(const char* name = "张三", int stuid = 0)
//		:_stuid(stuid)
//		, Person(name)
//	{}
//
//	Student(const Student& s)
//		:Person(s) //这里按理说是要传父类的变量，但是父类对象没法传进来，可以直接传子类对象，
//		//因为子类对象，可以被父类对象隐式类型转换
//		,_stuid(s._stuid)
//	{}
//
//	Student& operator=(const Student& s)
//	{
//		cout << "Student& operator=(const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator=(s);//赋值操作符重载可以指定父类作用域来达到目的
//			_stuid = s._stuid;
//		}
//		return *this;
//	}
//	~Student()
//	{
//		//由于后面多态的原因，析构函数的函数名被特殊处理了
//		//统一处理成destrucot
//		
//		//显式调用父类析构函数，无法保证先子后父
//		//所以子类析构函数完成就自动调用父类，这样就保证了先子后父
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

//继承
//int main()
//{
//	Person p;
//	Student s;
//	Teacher t;
//	s.Print();
//	t.Print();
//	//子赋给父是可以的
//	p = s;
//
//	int i = 0;
//	//double& d = i; // 不可以因为临时变量具有常性
//	const double& d = i;
//
//	//赋值兼容(切割\切片）
//	Person p1 = s;
//	Person& rp = s;//引用不产生临时变量，只是切出来部分的别名
//
//	return 0;
//}

// 派生类初始化列表
//int main()
//{
//	Student s;
//
//	return 0;
//}

//菱形虚拟继承
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
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}
};

class Student : public Person
{
public:
	virtual void BuyTicket() { cout << "买票-半价" << endl; }

	~Student() { cout << "~Student()" << endl; }
};

//析构函数可以是虚函数吗？为什么？
// 析构函数加vritual, 是不是函数重写？
// 是，因为类析构函数都是被处理成destrctor这个统一的名字
// 为什么要这么处理呢？因为要让他们构成重写
// 那为什么要让他们构成重写呢？
//int main()
//{
//	Person p;
//	Student s;
//
//	return 0;
//}

//下面的场景：
//会造成内存泄露，没有调用派生类的析构函数
//int main()
//{
//	Person* p = new Person;
//	p->BuyTicket();
//	delete p;
//
//	p = new Student;
//	p->BuyTicket();
//	delete p;// p->destructor()+operator delete(p)
//	// 这里我们期望p->destructor()是一个多态调用（防止内存泄漏），而不是普通调用
//
//	return 0;
//} 

//final 不可以重写虚函数
//派生类不加 vritual也是重写，因为可以省略
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	void Drive() { cout << "Benz-舒适" << endl; }
//};

//override 检查派生类是否重写了虚函数(没有会报错）
class Car {
public:
	virtual void Drive() {}
};
class Benz :public Car {
public:
	virtual void Drive() override { cout << "Benz-舒适" << endl; }
};