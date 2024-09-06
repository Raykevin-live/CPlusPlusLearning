#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cassert>
using namespace std;

//缺省参数 -- 一个参数
//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	Func();//没有传参时按照默认的参数
//	Func(10);//传参时按照传入的参数
//
//	return 0;
//}

//缺省参数 -- 多个参数(从左到右依次传参)
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//int main()
//{
//	Func(); //10, 20, 30
//	Func(1); // 1, 20, 30
//	Func(1, 2); // 1, 2, 30
//	Func(1, 2, 3);// 1, 2, 3
//
//	return 0;
//}

//半缺省参数 -- 严格 从右往左缺省，传参从左往右缺省
//void Func(int a, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//int main()
//{
//	//Func(); //缺少参数报错
//	Func(1); // 1, 20, 30
//	Func(1, 2); // 1, 2, 30
//	Func(1, 2, 3);// 1, 2, 3
//
//	return 0;
//}

//声明和定义不可以同时给缺省
//要在声明处缺省，好像都可以?
//int add(int a, int b = 2);//b在声明处缺省

//将函数体放到主函数前面的时候似乎会直接编译函数体，
//如果说放到后面的话会优先编译声明，再根据声明去找函数体，这时需要在声明中缺省

//int main()
//{
//	printf("%d\n", add(1));
//	return 0;
//}
//
//int add(int a, int b)
//{
//	return a + b;
//}

// 1、参数类型不同
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}
//2. 参数的个数不同
//void f()
//{
//	cout << "f()" << endl;
//}
//
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//3.类型顺序不同
//void fun(int a, char b)
//{
//	cout << "fun(int a, char b)" << endl;
//}
//void fun(char b, int a)
//{
//	cout << "fun(char b, int a)" << endl;
//}


//引用
//int main()
//{
//	int a = 0;
//	int& b = a;
//	int& c = b;
//	int& d = a; //引用必须给一个值，否则不知道是引用的谁
//
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << &d<< endl;
//
//	d++;
//	c++;//改变一个都会改变
//
//	int x = 10;
//	d = x; //引用是不能改变指向的，（引用一旦指定就不可以再引用其他实体）这种写法只能赋值
//
//	return 0;
//}

//引用的使用
//1.做参数（输出型参数——形参改变会改变实参）
//void Swap(int& a, int& b)//这里a和b为别名，相当于直接改变原地址处的数字，不用再使用指针
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	int a = 0, b = 1;
//	Swap(a, b);
//
//	cout << a << " " << b << endl;
//
//	return 0;
//}

//2.代替指针
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}LTNode, *PLTNode;//这里的PLTNode 是ListNode* 类型
//写法1：
void LTPushBack(PLTNode& phead, int x)
{
	//...
}
//写法2：
//void LTPushBack(LTNode*& phead, int x)//注意类型在前，引用在后
//{
//	// ...
//}

//3.引用做返回值（传引用返回，减少拷贝提高效率）
//静态区变量可以返回引用值
int& Count()
{
	static int n = 0;//静态区变量不会随便销毁
	//int n = 0;
	//临时变量在Count函数结束时，栈帧会被销毁掉，清理栈帧，那么ret的结果是随机值
	//如果Count函数结束，栈帧销毁，没有清理栈帧，那么ret的结果侥幸为正确值
	//已经销毁了就没有权限访问，相当于野指针
	n++;
	return n;//返回n的拷贝
}
//int main()
//{
//	int ret = Count();
//	cout << ret << endl;
//
//	return 0;
//}
// 
//4.引用做返回值（可以修改返回值）
//typedef struct SeqList
//{
//	int a[100];
//	size_t size;
//
//	//C++写法：
//	int& at(int pos)
//	{
//		assert(pos >= 0 && pos < 100);
//		return a[pos];
//	}
//	//运算符重载：
//	int& operator[](int pos)
//	{
//		assert(pos >= 0 && pos < 100);
//		return a[pos];
//	}
//}*PSL;
//
//int SLGet(PSL ps, int pos)
//{
//	assert(ps);
//
//	return ps->a[pos];
//}
//
//void SLModify(PSL ps, int pos, int x)
//{
//	assert(pos < 100 && pos >= 0);
//	ps->a[pos] = x;
//}
//
//int& SLAt(SeqList& s, int pos)
//{
//	assert(pos < 100 && pos >= 0);
//
//	return s.a[pos];
//}
//
//int main()
//{
//	//以前的做法
//	SeqList s;
//	SLModify(&s, 0, 1);
//	cout << SLGet(&s, 0) << endl;
//	//对第0个位的值加5
//	int ret = SLGet(&s, 0);
//	SLModify(&s, 0, ret + 5);
//	cout << SLGet(&s, 0) << endl;
//
//	//返回引用值 做法
//	SLAt(s, 0) = 1;
//	cout << SLAt(s, 0) << endl;
//	SLAt(s, 0) += 5;
//	cout << SLAt(s, 0) << endl;
//
//	//C++简单写法：
//	s.at(0) = 1;
//	s.at(0) += 5;
//	cout << s.at(0) << endl;
//
//	//运算符重载
//	s[0] = 1;
//	s[0] += 5;
//	cout << s[0] << endl;
//
//	return 0;
//}

//常量引用
//int main()
//{
//	//引用过程中，权限不能放大
//	//const int a = 0;
//	//int& b = a;//错误
//
//	//可以, c拷贝给d，没有放大权限，因为d的改变不影响c
//	const int c = 0;
//	int d = c;
//
//	//不可以
//	//引用过程中，权限可以平移或者缩小
//	int x = 0;
//	int& y = x;//平移
//	const int& z = x;//缩小（缩小的是z作为别名的权限，不会改变x的权限）
//	++x;
//
//	const int& m = 10;//平移
//
//	double f = 1.11;
//	int ff = f;//可以，会产生临时变量，临时变量具有常性(相当于被const修饰了)
//	//int& fff = f;//不可以，这里权限被放大了
//	const int& cc = f;//可以，这里是权限平移
//
//	return 0;
//}

#include <map>
#include <string>
#include <vector>

//auto关键字
//int main()
//{
//	int a = 0;
//	int b = a;
//	auto c = a;
//	auto d = 1 + 1.11;//根据右边的表达式，自动推到类型
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;//typeid是打印出类型
//	
//	//容器
//	vector<int> v;
//	//auto适用于类型名很长时
//	//vector<int>::iterator it = v.begin();
//	auto it = v.begin();//等价与上面的类型
//
//	std::map<std::string, std::string> dict;//不展开命名空间写法
//	//std::map<std::string, std::string> ::iterator dit = dict.begin();
//	auto dit = dict.begin();
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1, 2,3, 4, 5, 6, 7 };
//
//	//以前写法
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//		arr[i] *= 2;
//
//	for (int* p = arr; p < arr + sizeof(arr) / sizeof(arr[0]); ++p)
//		cout << *p << " ";
//	cout << endl;
//
//	//适用于数组
//	//范围for —— grammer suger
//	//依次取数组中数据赋值给e
//	//自动迭代，自动判断结束
//	for (auto& e : arr)//引用可以改变数组内容
//	{
//		e *= 2;
//	}
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
// 
// int x = 10;
// auto a = &x;
// auto* b = a;
// auto& c = x;
//
//	return 0;
//}

//宏函数 -- 不加分号，宏是替换，可能会出问题
//优点：不需要建立栈帧，提高调用效率
//缺点：复杂、容易出错、可读性差、不能调试
//#define ADD(X , Y) ((X)*(Y)*10)
//
//int main()
//{
//	int ret = ADD(1, 2);
//	printf("%d", ret);
//	return 0;
//}


//内联函数
// 与宏函数类似也是在编译时直接展开
//适用于短小、频繁调用的函数，代码过于复杂会导致
//inline对于编译器只是一个建议，最终是否成为inline，编译器自己决定
//想类似函数就算加了内联函数也会被否决掉
//1.比较长的函数
//2.递归函数
//debug版本下默认不会显示内联
//内联函数直接定义在.h文件，不要声明与定义分开，否则会出现编译错误
inline int Add(int x, int y)
{
	return x + y;
}

int main()
{
	for (int i = 0; i < 100000; i++)
	{
		cout << Add(i, i + 1) << endl;
	}

	return 0;
}

