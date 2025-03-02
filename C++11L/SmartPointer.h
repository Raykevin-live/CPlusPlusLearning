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

		//现实时不允许拷贝
		//方法1： 只声明，不实现，且置为私有
	//private:
	//	unique_ptr(unique_ptr<T>& ap);
		//方法2：使用delete
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
			//注意自己对自己赋值
			if (_ptr != sp._ptr) {
				//删除原来的资源链接，如果原来资源指向数为0，需要析构
				if (--(*_pcount) == 0) {
					delete _ptr;
					delete _pcount;
				}
				//指向新的资源
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				++(* _pcount);
			}
			return *this;
		}

	private:
		T* _ptr;
		//需要加入计数，当计数减为0时，才开始析构一次
		//1. 使用static不可以，因为他是共有的，导致多个资源享有一个_count，需要的是一个资源有一个_count
		//static int _count;

		//2. 需要使用int* 每个资源指向一个指针，一个计数
		int* _pcount;
	};
}