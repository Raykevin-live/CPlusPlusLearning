#pragma once

#include <assert.h>

namespace ling
{
	template<typename T>

	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;


		vector()
			//:_start(nullptr)
			//, _finish(nullptr)
			//, _endofstorage(nullptr)
		{}

		//拷贝构造
		vector(const vector<T>& v)
			//:_start(nullptr)
			//, _finish(nullptr)
			//, _endofstorage(nullptr)
		{
			_start = new T(v.capacity());
			memcpy(_start, v._start, sizeof(T)*v.size());
			_finish = _start + v.size();
			_endofstorage = _start + v.capacity();

		}

		vector(size_t n, const T& val = T())
			//:_start(nullptr)
			//, _finish(nullptr)
			//, _endofstorage(nullptr)
		{
			resize(n, val);
		}
		
		//模板匹配原则，防止匹配错误
		vector(int n, const T& val = T())
		{
			resize(n, val);
		}

		//[first, last) 迭代器默认是这样的方便使用
		template<typename InputIterator>//模板套模板
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}
		//深拷贝
		vector<T>& operator=(vector<T> v) const 
		{
			swap(v);

			return *this;
		}

		iterator begin()
		{
			return _start;
		}

		const_iterator begin() const
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator end() const
		{
			return _finish;
		}

		

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				if (_start)
				{
					// 使用浅拷贝会出问题
					//memcpy(tmp, _start, sizeof(T) * old_size);
					for (size_t i = 0; i < old_size; i++)
					{
						tmp[i] = _start[i];//调用深拷贝 赋值重载 '=' 
					}

					delete[] _start;
				}

				_start = tmp;
				_finish = _start + old_size;				
				_endofstorage = _start + n;
			}
		}

		void resize(size_t n, const T& val = T())// T() 是匿名对象，缺省值或默认值，int 赋给0，float赋给0.0
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);

				while (_finish != _start + n)
				{
					//填值
					*_finish = val;
					++_finish;
				}
			}
		}

		void push_back(const T& x)
		{
			/*if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0? 4: capacity()*2;

				reserve(newcapacity);
			}

			*_finish = x;
			++_finish;*/
			auto it = end();
			insert( it, x);
		}

		void pop_back()
		{
			 auto it = end();
			 erase(--it);
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}

		//可以复用到push_back
		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);

			if (_finish == _endofstorage)
			{
				//记录相对位置，由于扩容时可能会出问题
				size_t len = pos - _start;

				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
				//解决迭代器失效问题
				pos = _start + len;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			
			*pos = x;
			++_finish;

			return pos;
		}

		iterator erase(const iterator& pos)
		{
			assert(pos >= _start && pos <= _finish);
			
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish;

			return pos;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr ;
			}
		}
	private:
		iterator _start = nullptr; // 给初始缺省值，方便后面初始化
		iterator _finish = nullptr;
		iterator _endofstorage = nullptr;
	};
}
