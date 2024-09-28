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

		//��������
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
		
		//ģ��ƥ��ԭ�򣬷�ֹƥ�����
		vector(int n, const T& val = T())
		{
			resize(n, val);
		}

		//[first, last) ������Ĭ���������ķ���ʹ��
		template<typename InputIterator>//ģ����ģ��
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
		//���
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
					// ʹ��ǳ�����������
					//memcpy(tmp, _start, sizeof(T) * old_size);
					for (size_t i = 0; i < old_size; i++)
					{
						tmp[i] = _start[i];//������� ��ֵ���� '=' 
					}

					delete[] _start;
				}

				_start = tmp;
				_finish = _start + old_size;				
				_endofstorage = _start + n;
			}
		}

		void resize(size_t n, const T& val = T())// T() ����������ȱʡֵ��Ĭ��ֵ��int ����0��float����0.0
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
					//��ֵ
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

		//���Ը��õ�push_back
		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);

			if (_finish == _endofstorage)
			{
				//��¼���λ�ã���������ʱ���ܻ������
				size_t len = pos - _start;

				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
				//���������ʧЧ����
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
		iterator _start = nullptr; // ����ʼȱʡֵ����������ʼ��
		iterator _finish = nullptr;
		iterator _endofstorage = nullptr;
	};
}
