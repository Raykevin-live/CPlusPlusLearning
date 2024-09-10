#define _CRT_SECURE_NO_WARNINGS 1

//class A 
//{
//public:
//	A(int a)
//	{
//		_a = a;
//	}
//
//private :
//	int _a = 1;
//};
//
//class B
//{
//public:
//	//初始化列表：对象成员定义的位置
//	B(int a, int& ref)
//		:_ref(ref)
//		,_n(1)
//		,_aobj(10)
//		,_x(2)
//	{
//		/*_n = 0;
//		_ref = ref;*/
//	}
//
//private:
//	//声明
//	A _aobj;	//自定义类型且没有默认构造函数,必须显式的写
//
//	//特征：必须在定义的时候初始化
//	int& _ref;	//引用
//	const int _n;	//const
//	int _x = 1;//缺省值
//};
//
//int main()
//{
//	//对象整体定义
//	int n = 1;
//	B bb1(10, n);
//	B bb2(12, n);
//
//	return 0;
//}

//隐式类型转换
//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	//成员变量 -- 属于每一个类对象
//	int _a;
//
//	// 静态成员变量 -- 属于类，属于类的每个对象共享，存储在静态区
//	static int _b;
//};
//
//int main()
//{
//	A aa1(1);
//	A aa2 = 2;//隐式类型转化，整形转化为自定义类型
//	//2拷贝一个A的临时对象，临时对象再拷贝构造aa2 --> 优化用2直接构造(编译器优化)
//	return 0;
//}


//创建一个类，只能在栈上创建对象
//创建一个类，只能在堆上创建对象

class A
{
public:
	static A GetStackObj()
	{
		A aa;
		return aa;
	}

	static A* GetHeapObj()
	{
		return new A;// new 返回指针
	}
private:
	A()
	{};
private:
	int _a = 1;
	int _b = 2;
};

int main()
{
	//static A aa1;//静态区
	//A aa2;	//栈
	//A* ptr = new A;	// 堆

	//这里会有先有鸡还是先有蛋的问题，通过这个函数去创建对象，但是需要有对象才可以调用函数
	//解决方法 使用static，static不用this指针
	A::GetStackObj();

	return 0;
}

//memory managemen

