#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <array>
#include "MyString.h"
#include "PerfectForward.h"
#include "MyList.h"
#include <list>
#include <functional>
#include "SmartPointer.h"
using namespace std;


struct Point {
	Point(int x, int y) {
		_x = x;
		_y = y;
	}

	int _x;
	int _y;
};

//列表初始化
//int main()
//{
//	//都是调用构造函数
//	Point p0(1, 2);
//	Point p1 = { 2, 3 };
//	Point p2{ 3, 4 };   // 多参数构造函数的隐式类型转换
//	
// Point& r = {3, 3}; //会生成一个临时对象，临时对象具有常性 需要加const：const Point& 
//	return 0;
//}

class A {
private:
	decltype(malloc) pf2;
};



void test_vec_Poi() {
	vector<int> v1 = { 1, 2, 3 }; //因为vector支持initializer_list 构造
	Point p1 = { 1, 2 };//这两不一样

	auto li = { 1, 2, 3 };

	cout << typeid(li).name() << endl; //typeid().name() 推出的是字符串，只能看不能用

	auto pf = malloc;
	auto pf1 = pf;
	//单纯先定义一个变量出现
	decltype(pf) pf2;
}

void test_array() {
	int a1[10];
	array<int, 10> a2; //加入了越界检查

	cout << sizeof(a1) << endl;
	cout << sizeof(a2) << endl;

	/*a1[20] = 1;
	a2[20] = 3;*/ //operator[] 函数调用加入了类型检查
}

void right_valueRef() {
	//左值引用
	int a = 0;
	int& af = a;

	//右值引用
	int&& rf = 10;
	double x = 1.1, y = 1.2;
	double&& rx = x + y;

	//左值引用给右值取别名
	//int& r2 = 10;//不可以
	const int& r2 = 10;//可以
	const double& rx1 = x + y;// 必须有const（常量）

	//右值引用给左值取别名
	int&& r3 = move(a); //需要使用move后的左值
}


//构成函数重载
void fun(const int& x) {
	cout << "fun(const int&)" << endl;
}
//没有下面这个函数构成重载时，右值也会进入第一个函数
void fun(int&& x) {
	cout << "fun(int&&)" << endl;
}

lingze::string func() {
	lingze::string str("xxxxxxxxxxxxxx");
	return str;
}
void test_move() {
	lingze::string ret1 = func();

	lingze::string ret2;
	ret2 = func();
}


void test_perfectForward() {
	PerfectForward(10); //右值
	int a = 10;
	PerfectForward(a); //左值
	PerfectForward(std::move(a)); // 右值
	const int b = 8;
	PerfectForward(b); // const 左值
	PerfectForward(std::move(b)); // const 右值
}

void test_MyList_forward() {
	lingze::List<lingze::string> lt;
	lt.PushBack("1111");
	lt.PushFront("2222");
}

void test_lambda() {
	auto add = [](int x, int y) {return x + y; };
	int a = 1, b = 2;
	auto pt = [&] {cout << add(a, b) << endl; };
	pt();
}


template<class F, class T>
T useF(F f, T x)
{
	static int count = 0;
	cout << "count:" << ++count << endl;
	cout << "count:" << &count << endl;
	return f(x);
}
double f(double i)
{
	return i / 2;
}
struct Functor
{
	double operator()(double d)
	{
		return d / 3;
	}
};

void test_function() {
	//包装器
	
	// 函数名
	cout << useF(f, 11.11) << endl;
	// 函数对象
	cout << useF(Functor(), 11.11) << endl;
	// lamber表达式
	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;

	//useF()函数被实例化成三分

	//包装器包装 -- 可调用对象的类型问题
	function<double(double)> f1 = f;
	function<double(double)> f2 = [](double d)->double { return d / 4; };
	function<double(double)> f3 = Functor();

	vector< function<double(double)>> v = { f1, f2, f3 };
	double db = 1.1;

	for (auto f : v) {
		cout<<f(db++)<<endl;
	}
}



//template<class T, class ...Args>
//void showList(T value, Args... args) {
//	cout << sizeof...(args) << endl; //注意要加三个点
//}

//要使用参数的方法
//1. 再加入一个模板参数，使用递归推演
//template<class T>
//void showList(T value) {
//	//结束条件的函数
//	cout << value<<" " << endl; //注意要加三个点
//}
//
//template<class T, class ...Args>
//void showList(T value, Args... args) {
//	cout << value << " ";
//	showList(args...);
//}

//2. 再套一层
void _showList() {
	//也可以用这种结束
	cout << endl;
} 
//template<class T>
//void _showList(T value) {
//	//结束条件的函数
//	cout << value<<" " << endl; //注意要加三个点
//}
template<class T, class ...Args>
void _showList(T value, Args... args) {
	cout << value << " ";
	_showList(args...);
}
template<class ...Args>
void showList(Args... args) {
	_showList(args...);
}


void test_var_args() {
	//可变模板参数
	showList(1);
	showList(1, 2, 3);
	showList(1, 2, 3, 4);
	showList(1, 2, 3, 4, 5);

}

//举个使用可变模板参数的实例
class Date {
public:
	Date(int year = 1, int month = 1, int day =1)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		cout << "Date构造" << endl;
	}

	Date(const Date& d) 
		:_year(d._year)
		, _month(d._month)
		, _day(d._day) 
	{
		cout << "Date拷贝构造" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
template<class ...Args>
Date* Create(Args ...args) {
	Date* ret = new Date(args...);
	return ret;
}

void test_Date1() {
	//灵活
	Date* p1 = Create();
	Date* p2= Create(2023);
	Date* p3 = Create(2023, 9);
	Date* p4 = Create(2023, 9, 27);

	Date d(2023, 1, 1);
	Date* p5 = Create(d);//调用默认拷贝构造
}

void test_Date2() {
	std::list<Date> lt;
	lt.push_back(Date(2023, 1, 1)); //先构造再拷贝构造（只能传日期类）
	lt.emplace_back(2023, 9, 27);//直接使用可变参数模板构造， 参数包直接调用构造 （既可以传日期类对象，
																			//也可以传参数包）
}


//bind 绑定
double Plus(int a, int b, double rate)
{
	return (a + b)*rate;
}
double PPlus(double rate, int a, int b)
{
	return (a + b) * rate;
}
double PPPlus(int a, double rate, int b)
{
	return (a + b) * rate;
}

void test_bind1() {
	//绑定全局函数

	//用于交换参数
	//function<int(int, int)> rSub = bind(&Sub::sub, placeholders::_2, placeholders::_1);//palceholder 占位符
	//cout << rSub(10, 5) << endl;


	function<double(int, int)> fp1 = bind(Plus, placeholders::_1, placeholders::_2, 4.0);
	function<double(int, int)> fp2 = bind(Plus, placeholders::_1, placeholders::_2, 4.1);
	function<double(int, int)> fp3 = bind(Plus, placeholders::_1, placeholders::_2, 4.2);

	cout << fp1(5, 3) << endl;
	cout << fp2(5, 3) << endl;
	cout << fp3(5, 3) << endl;

	//注意还是从1开始标号而不是2， 3
	function<double(int, int)> fpp1 = bind(PPlus, 4.0, placeholders::_1, placeholders::_2);
	function<double(int, int)> fpp2 = bind(PPlus, 4.1, placeholders::_1, placeholders::_2);
	function<double(int, int)> fpp3 = bind(PPlus, 4.2, placeholders::_1, placeholders::_2);

	cout << fpp1(5, 3) << endl;
	cout << fpp2(5, 3) << endl;
	cout << fpp3(5, 3) << endl;

	//说明固定参数不参与排序, 是与左边的参数列表一一对应的
	function<double(int, int)> fppp1 = bind(PPPlus, placeholders::_1, 4.0, placeholders::_2);
	function<double(int, int)> fppp2 = bind(PPPlus, placeholders::_1, 4.1, placeholders::_2);
	function<double(int, int)> fppp3 = bind(PPPlus, placeholders::_1, 4.2, placeholders::_2);
}


class Sub {
public:
	static int sub(int a, int b)
	{
		return a - b;
	}

	double ssub(int a, int b, double rate)
	{
		return (a - b)*rate;
	}
};

void test_bind2() {
	//绑定类的成员函数
	
	//非静态的成员函数必须要加取地址符，而静态的可以加也可以不加
	function<int(int, int)> fs1 = bind(&Sub::sub, placeholders::_1, placeholders::_2);

	//非静态成员函数要多一个this指针参数，所以需要传入对象地址
	Sub sub1;
	function<double(int, int)> fs2 = bind(&Sub::ssub, &sub1, placeholders::_1, placeholders::_2, 1.1);

	//也可以传个临时对象
	function<double(int, int)> fs3 = bind(&Sub::ssub, Sub(), placeholders::_1, placeholders::_2, 1.1);

	//之所以可以传对象或者指针，是因为它本质上也是一个仿函数，既可以对象调用也可以指针调用

	cout << typeid(fs3).name() << endl; //typename检测不出来他的类型
}


//智能指针
//由于异常类会引起内存泄漏（异常的抛出）
int div()
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw invalid_argument("除0错误");
	return a / b;
}
void ff() {
	pair<string, string>* p1 = new pair<string, string>;

	try {
		div();
	}
	catch (...) {
		delete p1;
		cout << "delete: "<< p1 << endl;
		throw;
	}
	cout << "delete: " << p1 << endl;
	delete p1;
}

//指针指针的实现本质上是封装一个类去自动调用析构函数
template<class T>
class Smart {
public:
	// RAII机制
	//资源交给对象管理，对象生命周期内，资源有效，对象生命周期到了，释放资源
	//1. RAII管控资源释放
	//2.想指针一样

	Smart(T* p) :_p(p)
	{}

	~Smart() {
		cout << "delete: ~smart:-> " << _p << endl;
		delete _p;
	}

	T& operator*() {
		return *_p;
	}
	T* operator->() {
		return _p;
	}
private:
	T* _p;
};
void fSmart() {
	pair<string, string>* p1 = new pair<string, string>;
	Smart< pair<string, string>> sp1(p1);

	Smart< pair<string, string>> sp2(new pair<string, string>);
	//不再需要释放
	div();
}

void test_smartPoint1() {
	try {
		//f();
		fSmart();
	}
	catch (const exception& e) {
		cout<<e.what()<<endl;
	}
	
}

class Aa {
public:
	Aa(int a)
		:_a(a)
	{
		cout << "Aa-构造" << endl;
	}
	Aa() :_a(0) { cout << "Aa-无参构造" << endl; }

	~Aa() {
		cout << this;
		cout << " ~Aa-析构" << endl;
	}
//private:
	int _a;
};

void test_smartPoint2(){
	auto_ptr<Aa> apt1(new Aa(1));
	auto_ptr<Aa> apt2(new Aa(2));

	//拷贝时会发生管理权转移（资源转移）
	//导致被拷贝对象悬空，访问就会出问题
	auto_ptr<Aa> apt3(apt1); //apt1 悬空

	//奔溃
	//apt1->_a++;
	apt3->_a++;
}

void test_smart_ptr1() {
	/*lingze::unique_ptr<Aa> up1(new Aa(1));
	lingze::unique_ptr<Aa> up2(new Aa(2));
	//解决拷贝时出现悬空的情况
	//直接不允许拷贝
	//lingze::unique_ptr<A> up3(up1);
	cout << endl << endl;

	shared_ptr<Aa> sp1(new Aa(1));
	shared_ptr<Aa> sp2(new Aa(2));
	shared_ptr<Aa> sp3(sp1);
	
	sp1->_a++;
	sp3->_a++;
	cout << sp1->_a << endl;
	*/

	lingze::shared_ptr<Aa> lsp1(new Aa(1));
	lingze::shared_ptr<Aa> lsp2(new Aa(2));
	lingze::shared_ptr<Aa> lsp3(lsp1);
	lingze::shared_ptr<Aa> lsp4(lsp1);
	lsp2 = lsp4;
	lsp1->_a++;
	lsp3->_a++;
	lsp1 = lsp1;
	cout << lsp1->_a << endl;
}

struct Node {
	Aa _val;
	/*shared_ptr<Node> _next;
	shared_ptr<Node> _prev;*/

	//解决循环引用问题
	/*weak_ptr<Node> _next;
	weak_ptr<Node> _prev;*/

	lingze::weak_ptr<Node> _next;
	lingze::weak_ptr<Node> _prev;
};

void test_smart_ptr2() {
	/*Node* n1 = new Node;
	Node* n2 = new Node;

	delete n1;
	delete n2;*/

	/*shared_ptr<Node> sp1(new Node);
	shared_ptr<Node> sp2(new Node);*/
	//智能指针是内置类型，sp1->_next 是自定义类型，所以类型不匹配需要修改
	// 但是会出现循环引用问题需要使用weak_ptr

	//weak_ptr 不是RAII机制
	//解决的原理就是不增加引用计数，可以访问资源，不参与资源释放的管理
	/*cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
	sp1->_next = sp2;
	sp2->_prev = sp1;
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;*/


	lingze::shared_ptr<Node> msp1(new Node);
	lingze::shared_ptr<Node> msp2(new Node);
	cout << msp1.use_count() << endl;
	cout << msp2.use_count() << endl;
	msp1->_next = msp2;
	msp2->_prev = msp1;
	cout << msp1.use_count() << endl;
	cout << msp2.use_count() << endl;
}

template<class T>
struct DeleteArray {
	void operator()(T* ptr) {
		delete[]ptr;
	}
};

void test_smart_ptr3() {
	//需要传入删除器，是一个函数对象
	lingze::shared_ptr<Aa> sp1(new Aa[10], DeleteArray<Aa>());
	lingze::shared_ptr<Aa> sp2((Aa*)malloc(sizeof(Aa)), [](Aa* ptr) {free(ptr); });
	lingze::shared_ptr<FILE> sp3(fopen("Test.cpp", "r"), [](FILE* ptr) {fclose(ptr); });

	lingze::shared_ptr<Aa> sp4(new Aa);
}


//特殊类的设计

//只在堆上创建对象的类
class HeapOnly {
public:
	void Destroy() {
		cout << "手动删除" << endl;
		delete this;
	}
private:
	//对象的生命周期在程序结束时自动结束，所以需要自动释放，但是类外的对象无法调用私有成员
	//而动态申请的资源不会自动调用析构函数
	~HeapOnly() {
	}
};

class HeapOnly2 {
public:
	// 先有鸡还是先有蛋的问题，static静态机制，
	// 直接让函数输入整个类，不用在乎对象
	static HeapOnly2* CreatObj() {
		return new HeapOnly2;
	}
private:
	// 构造函数私有化
	HeapOnly2() {
	}
	HeapOnly2(const HeapOnly2& hp) = delete;
	HeapOnly2& operator=(const HeapOnly2& hp) = delete;
};

class StackOnly {
public:
	static StackOnly CreatObj() {
		StackOnly st;
		//构造+拷贝构造
		return st;
	}
private:
	// 构造函数私有化
	StackOnly() {
		//...
	}
	//对一个类实现专属的operator new
	void* operator new(size_t size) = delete;
};

void test_heap_only() {
	/*HeapOnly hp1;
	HeapOnly hp2;*/
	HeapOnly* hp3 = new HeapOnly;
	hp3->Destroy();

	//但是还要注意可以拷贝构造，会在栈上，要将他们也封起来
	HeapOnly2* hp4 = HeapOnly2::CreatObj();
	//HeapOnly2 hp5(*hp4);
}

void test_stack_only() {
	StackOnly sp1 = StackOnly::CreatObj();
	/*StackOnly sp2;
	StackOnly sp3 = new StackOnly;*/
	StackOnly copy(sp1);//拷贝构造，允许

	//new operator new + 构造
	//StackOnly* sp4 = new StackOnly(sp1);
}



//设计模式
//一、单例模式
// 单一对象
//饿汉模式：就是说不管你将来用不用，程序启动时（main函数之前）就创建一个唯一的实例对象
//1、如果单例对象初始化很多内容，可能会影响启动速度
//2、如果两个单例类，互相有依赖关系
//假设有A,B两个依赖类要求A先初始化，B再初始化，B的初始化创建依赖A，编译器无法保证
namespace hungry {
	class Singleton {
	public:
		// 2、获取唯一实例的接口
		static Singleton& GetInstance() {
			return _sinst;
		}



		// 3、删除拷贝构造函数和赋值操作符，防止复制
		Singleton(const Singleton&) = delete;
		Singleton& operator=(const Singleton&) = delete;
	private:
		// 1、私有构造函数，防止外部创建实例
		Singleton() {}
		// 示例数据成员
		pair<string, string> _dict;
		// 静态成员变量，存储唯一的实例
		static Singleton _sinst; //这是允许的
	};
	// 静态成员变量的定义和初始化
	Singleton Singleton::_sinst;
}
// 懒汉模式
namespace lazy {
	class Singleton {
	public:
		// 2、获取唯一实例的接口
		static Singleton& GetInstance() {
			if (_psinst == nullptr) {
				//第一次调用GetInstance时再创建
				_psinst = new Singleton;
			}
			return *_psinst;
		}

		//显示写析构函数，为了中途有时候可以手动删除重来
		static void DelInstance() {
			if (_psinst) {
				delete _psinst;
				_psinst = nullptr;
			}
		}

		// 3、删除拷贝构造函数和赋值操作符，防止复制
		Singleton(const Singleton&) = delete;
		Singleton& operator=(const Singleton&) = delete;
	private:
		// 1、私有构造函数，防止外部创建实例
		Singleton() {}

		~Singleton() { cout << "~Singleton"; }

		// 示例数据成员
		pair<string, string> _dict;
		// 静态成员变量，存储唯一的实例
		static Singleton* _psinst; //这是允许的
	};
	// 静态成员变量的定义和初始化
	// 只实例化指针，并不真的创建
	Singleton* Singleton::_psinst = nullptr;
}

void test_Singleton() {
	cout << &hungry::Singleton::GetInstance() << endl;
	cout << &hungry::Singleton::GetInstance() << endl;
	cout << &hungry::Singleton::GetInstance() << endl;
	cout << endl;
	cout << &lazy::Singleton::GetInstance() << endl;
	cout << &lazy::Singleton::GetInstance() << endl;
	cout << &lazy::Singleton::GetInstance() << endl;

	//为了程序结束时可以自动析构，可以随便定义一个类的对象，在析构函数中使用DelInstance函数
	//对象的生命周期定义到全局，在程序结束后自动析构
	//也可以在本类中定义一个类，可以自动调用析构，带走单一对象
}

int main() {

	//test_vec_Poi();
	//test_array();

	//right_valueRef();
	/*int a = 0, b = 1;
	fun(a + b);*/
	
	/*test_move();*/

	//test_perfectForward();
	//test_MyList_forward();
	//test_lambda();

	//test_function();

	//test_Date2();

	//test_var_args();

	//test_bind1();
	//test_bind2();

	//test_smartPoint2();

	//test_smart_ptr3();
	//test_heap_only();

	//test_stack_only();

	test_Singleton();
	return 0;
}