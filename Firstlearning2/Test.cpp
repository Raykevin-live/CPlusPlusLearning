#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cassert>
using namespace std;

//ȱʡ���� -- һ������
//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	Func();//û�д���ʱ����Ĭ�ϵĲ���
//	Func(10);//����ʱ���մ���Ĳ���
//
//	return 0;
//}

//ȱʡ���� -- �������(���������δ���)
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

//��ȱʡ���� -- �ϸ� ��������ȱʡ�����δ�������ȱʡ
//void Func(int a, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//int main()
//{
//	//Func(); //ȱ�ٲ�������
//	Func(1); // 1, 20, 30
//	Func(1, 2); // 1, 2, 30
//	Func(1, 2, 3);// 1, 2, 3
//
//	return 0;
//}

//�����Ͷ��岻����ͬʱ��ȱʡ
//Ҫ��������ȱʡ�����񶼿���?
//int add(int a, int b = 2);//b��������ȱʡ

//��������ŵ�������ǰ���ʱ���ƺ���ֱ�ӱ��뺯���壬
//���˵�ŵ�����Ļ������ȱ����������ٸ�������ȥ�Һ����壬��ʱ��Ҫ��������ȱʡ

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

// 1���������Ͳ�ͬ
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
//2. �����ĸ�����ͬ
//void f()
//{
//	cout << "f()" << endl;
//}
//
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//3.����˳��ͬ
//void fun(int a, char b)
//{
//	cout << "fun(int a, char b)" << endl;
//}
//void fun(char b, int a)
//{
//	cout << "fun(char b, int a)" << endl;
//}


//����
//int main()
//{
//	int a = 0;
//	int& b = a;
//	int& c = b;
//	int& d = a; //���ñ����һ��ֵ������֪�������õ�˭
//
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << &d<< endl;
//
//	d++;
//	c++;//�ı�һ������ı�
//
//	int x = 10;
//	d = x; //�����ǲ��ܸı�ָ��ģ�������һ��ָ���Ͳ���������������ʵ�壩����д��ֻ�ܸ�ֵ
//
//	return 0;
//}

//���õ�ʹ��
//1.������������Ͳ��������βθı��ı�ʵ�Σ�
//void Swap(int& a, int& b)//����a��bΪ�������൱��ֱ�Ӹı�ԭ��ַ�������֣�������ʹ��ָ��
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

//2.����ָ��
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}LTNode, *PLTNode;//�����PLTNode ��ListNode* ����
//д��1��
void LTPushBack(PLTNode& phead, int x)
{
	//...
}
//д��2��
//void LTPushBack(LTNode*& phead, int x)//ע��������ǰ�������ں�
//{
//	// ...
//}

//3.����������ֵ�������÷��أ����ٿ������Ч�ʣ�
//��̬���������Է�������ֵ
int& Count()
{
	static int n = 0;//��̬�����������������
	//int n = 0;
	//��ʱ������Count��������ʱ��ջ֡�ᱻ���ٵ�������ջ֡����ôret�Ľ�������ֵ
	//���Count����������ջ֡���٣�û������ջ֡����ôret�Ľ������Ϊ��ȷֵ
	//�Ѿ������˾�û��Ȩ�޷��ʣ��൱��Ұָ��
	n++;
	return n;//����n�Ŀ���
}
//int main()
//{
//	int ret = Count();
//	cout << ret << endl;
//
//	return 0;
//}
// 
//4.����������ֵ�������޸ķ���ֵ��
//typedef struct SeqList
//{
//	int a[100];
//	size_t size;
//
//	//C++д����
//	int& at(int pos)
//	{
//		assert(pos >= 0 && pos < 100);
//		return a[pos];
//	}
//	//��������أ�
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
//	//��ǰ������
//	SeqList s;
//	SLModify(&s, 0, 1);
//	cout << SLGet(&s, 0) << endl;
//	//�Ե�0��λ��ֵ��5
//	int ret = SLGet(&s, 0);
//	SLModify(&s, 0, ret + 5);
//	cout << SLGet(&s, 0) << endl;
//
//	//��������ֵ ����
//	SLAt(s, 0) = 1;
//	cout << SLAt(s, 0) << endl;
//	SLAt(s, 0) += 5;
//	cout << SLAt(s, 0) << endl;
//
//	//C++��д����
//	s.at(0) = 1;
//	s.at(0) += 5;
//	cout << s.at(0) << endl;
//
//	//���������
//	s[0] = 1;
//	s[0] += 5;
//	cout << s[0] << endl;
//
//	return 0;
//}

//��������
//int main()
//{
//	//���ù����У�Ȩ�޲��ܷŴ�
//	//const int a = 0;
//	//int& b = a;//����
//
//	//����, c������d��û�зŴ�Ȩ�ޣ���Ϊd�ĸı䲻Ӱ��c
//	const int c = 0;
//	int d = c;
//
//	//������
//	//���ù����У�Ȩ�޿���ƽ�ƻ�����С
//	int x = 0;
//	int& y = x;//ƽ��
//	const int& z = x;//��С����С����z��Ϊ������Ȩ�ޣ�����ı�x��Ȩ�ޣ�
//	++x;
//
//	const int& m = 10;//ƽ��
//
//	double f = 1.11;
//	int ff = f;//���ԣ��������ʱ��������ʱ�������г���(�൱�ڱ�const������)
//	//int& fff = f;//�����ԣ�����Ȩ�ޱ��Ŵ���
//	const int& cc = f;//���ԣ�������Ȩ��ƽ��
//
//	return 0;
//}

#include <map>
#include <string>
#include <vector>

//auto�ؼ���
//int main()
//{
//	int a = 0;
//	int b = a;
//	auto c = a;
//	auto d = 1 + 1.11;//�����ұߵı��ʽ���Զ��Ƶ�����
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;//typeid�Ǵ�ӡ������
//	
//	//����
//	vector<int> v;
//	//auto�������������ܳ�ʱ
//	//vector<int>::iterator it = v.begin();
//	auto it = v.begin();//�ȼ������������
//
//	std::map<std::string, std::string> dict;//��չ�������ռ�д��
//	//std::map<std::string, std::string> ::iterator dit = dict.begin();
//	auto dit = dict.begin();
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1, 2,3, 4, 5, 6, 7 };
//
//	//��ǰд��
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//		arr[i] *= 2;
//
//	for (int* p = arr; p < arr + sizeof(arr) / sizeof(arr[0]); ++p)
//		cout << *p << " ";
//	cout << endl;
//
//	//����������
//	//��Χfor ���� grammer suger
//	//����ȡ���������ݸ�ֵ��e
//	//�Զ��������Զ��жϽ���
//	for (auto& e : arr)//���ÿ��Ըı���������
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

//�꺯�� -- ���ӷֺţ������滻�����ܻ������
//�ŵ㣺����Ҫ����ջ֡����ߵ���Ч��
//ȱ�㣺���ӡ����׳����ɶ��Բ���ܵ���
//#define ADD(X , Y) ((X)*(Y)*10)
//
//int main()
//{
//	int ret = ADD(1, 2);
//	printf("%d", ret);
//	return 0;
//}


//��������
// ��꺯������Ҳ���ڱ���ʱֱ��չ��
//�����ڶ�С��Ƶ�����õĺ�����������ڸ��ӻᵼ��
//inline���ڱ�����ֻ��һ�����飬�����Ƿ��Ϊinline���������Լ�����
//�����ƺ������������������Ҳ�ᱻ�����
//1.�Ƚϳ��ĺ���
//2.�ݹ麯��
//debug�汾��Ĭ�ϲ�����ʾ����
//��������ֱ�Ӷ�����.h�ļ�����Ҫ�����붨��ֿ����������ֱ������
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

