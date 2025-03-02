#pragma once


namespace lingze {
	template<class T>
	class unique_ptr {
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{
			cout << "unique_ptr ";
		}

		~unique_ptr() {
			cout << "delete: ~smart:-> " << _ptr << endl;
			delete _ptr;
		}

		T& operator*() {
			return *_ptr;
		}
		T* operator->() {
			return _ptr;
		}

		//��ʵʱ��������
		//����1�� ֻ��������ʵ�֣�����Ϊ˽��
	//private:
	//	unique_ptr(unique_ptr<T>& ap);
		//����2��ʹ��delete
		unique_ptr(unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(unique_ptr<T>& up) = delete;
	private:
		T* _ptr;
	};

	template<class T>
	class shared_ptr {
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))
		{
			cout << "shared_ptr ";
		}

		~shared_ptr() {
			if (--(*_pcount) == 0) {
				cout << "delete: ~shared:-> " << _ptr << endl;
				delete _ptr;
				delete _pcount;
			}
		}

		T& operator*() {
			return *_ptr;
		}
		T* operator->() {
			return _ptr;
		}

	
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
		{
			++(*_pcount);
		}
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			//ע���Լ����Լ���ֵ
			if (_ptr != sp._ptr) {
				//ɾ��ԭ������Դ���ӣ����ԭ����Դָ����Ϊ0����Ҫ����
				if (--(*_pcount) == 0) {
					delete _ptr;
					delete _pcount;
				}
				//ָ���µ���Դ
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				++(* _pcount);
			}
			return *this;
		}

	private:
		T* _ptr;
		//��Ҫ�����������������Ϊ0ʱ���ſ�ʼ����һ��
		//1. ʹ��static�����ԣ���Ϊ���ǹ��еģ����¶����Դ����һ��_count����Ҫ����һ����Դ��һ��_count
		//static int _count;

		//2. ��Ҫʹ��int* ÿ����Դָ��һ��ָ�룬һ������
		int* _pcount;
	};
}