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
		return new A;// new ����ָ��
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
	//static A aa1;//��̬��
	//A aa2;	//ջ
	//A* ptr = new A;	// ��

	//����������м��������е������⣬ͨ���������ȥ�������󣬵�����Ҫ�ж���ſ��Ե��ú���
	//������� ʹ��static��static����thisָ��
	A::GetStackObj();

	return 0;
}

//memory managemen

