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

		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * old_size);
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
					_finish = val;
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
			insert( end(), x);
		}

		void pop_back()
		{
			erase( --end());
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

		iterator erase(iterator pos)
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
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _endofstorage = nullptr;
	};
}
