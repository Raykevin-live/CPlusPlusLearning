#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

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
//	//��ʼ���б������Ա�����λ��
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
//	//����
//	A _aobj;	//�Զ���������û��Ĭ�Ϲ��캯��,������ʽ��д
//
//	//�����������ڶ����ʱ���ʼ��
//	int& _ref;	//����
//	const int _n;	//const
//	int _x = 1;//ȱʡֵ
//};
//
//int main()
//{
//	//�������嶨��
//	int n = 1;
//	B bb1(10, n);
//	B bb2(12, n);
//
//	return 0;
//}

//��ʽ����ת��
//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	//��Ա���� -- ����ÿһ�������
//	int _a;
//
//	// ��̬��Ա���� -- �����࣬�������ÿ���������洢�ھ�̬��
//	static int _b;
//};
//
//int main()
//{
//	A aa1(1);
//	A aa2 = 2;//��ʽ����ת��������ת��Ϊ�Զ�������
//	//2����һ��A����ʱ������ʱ�����ٿ�������aa2 --> �Ż���2ֱ�ӹ���(�������Ż�)
//	return 0;
//}


//����һ���ֻ࣬����ջ�ϴ�������
//����һ���ֻ࣬���ڶ��ϴ�������

//class A
//{
//public:
//	static A GetStackObj()
//	{
//		A aa;
//		return aa;
//	}
//
//	static A* GetHeapObj()
//	{
//		return new A;// new ����ָ��
//	}
//private:
//	A()
//	{};
//private:
//	int _a = 1;
//	int _b = 2;
//};
//
//int main()
//{
//	//static A aa1;//��̬��
//	//A aa2;	//ջ
//	//A* ptr = new A;	// ��
//
//	//����������м��������е������⣬ͨ���������ȥ�������󣬵�����Ҫ�ж���ſ��Ե��ú���
//	//������� ʹ��static��static����thisָ��
//	A::GetStackObj();
//
//	return 0;
//}


//��������
class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
private:
	int _a;
};

class Solution
{
public:
	Solution()
	{}
public:
	int Sum_Solution(int n)
	{
		cout << "Sum_Solution" << endl;
		return n;
	}
};

int main()
{
	A aa(1); // �������� -- ���������ڵ�ǰ�����ֲ���
	A(2);    //�������� -- ���������ڵ�ǰ��

	Solution s1;
	s1.Sum_Solution(10);

	Solution().Sum_Solution(20); // ��������

	//A& ra = A(1); //����������г���
	const A& ra = A(1); //const �����ӳ�����������������ڣ����������ڵ�ǰ�����ֲ���

	return 0;
}

//memory managemen

