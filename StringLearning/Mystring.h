#pragma once

#include <iostream>
#include <cstdlib>
#include <assert.h>

using namespace std;
//string 实现

namespace ling
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		//构造函数
		//string(const char* str)
		//	:_size(strlen(str))
		//	,_capacity(_size)
		//	,_str(new char[_capacity + 1])//注意初始化列表的顺序
		//{
		//	strcpy(_str, str);
		//}
		// 
		//无参
		//string()
		//	:_size(0)
		//	, _capacity(_size)
		//	, _str(new char[1])//注意初始化列表的顺序
		//{
		//	_str[0] = '\0';
		//}

		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			//strcpy(_str, str); // 遇到'\0' 会出问题
			memcpy(_str, str, _size + 1); // _size+1 是因为'\0' 
		}

		//深拷贝，拷贝构造
		string(const string& s)
		{
			_str = new char[s._capacity + 1];
			//strcpy(_str, s._str);
			memcpy(_str, s._str, s._size + 1);
			_size = s._size;
			_capacity = s._capacity;
		}

		//赋值操作符, 深拷贝
		string& operator= (const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				memcpy(tmp, s._str, s._size + 1);
				delete[] _str;
				_str = tmp;
				
				_size = s._size;
				_capacity = s._capacity;
			}

			return *this;
		}
		//现代的赋值写法
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		//string& operator=(string& s)
		//{
		//	if (this != &s)
		//	{
		//		string tmp;
		//		//this->swap(tmp);
		//		swap(tmp);
		//	}
		//	return *this;
		//}
		//更简单的写法
		string& operator=(string tmp)
		{
			swap(tmp);

			return *this;
		}

		//析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);

			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				//2倍扩容
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				//至少扩容到_size + len
				reserve(_size + len);
			}
			//strcpy(_str + _size, str);
			memcpy(_str + _size, str, len + 1);
			_size += len;
		}

		string& operator+=(char ch)
		{
			push_back(ch);

			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		void insert(size_t pos, size_t n, char ch)
		{
			assert(pos <= _size);
			if (_size + n > _capacity)
			{
				//至少扩容到_size + len
				reserve(_size + n);
			}
			//挪动数据
			int end = (int)_size; //结束时end = -1(当pos = 0)
			while (end >= (int)pos) //发生整形提升
			{
				_str[end + n] = _str[end];
				--end;
			}
			for (size_t i = 0; i < n; i++)
			{
				_str[pos + i] = ch;
			}

			_size += n;
		}

		void insert(size_t pos,const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				//至少扩容到_size + len
				reserve(_size + len);
			}
			//挪动数据
			int end = (int)_size; //结束时end = -1(当pos = 0)
			while (end >= (int)pos) //发生整形提升
			{
				_str[end + len] = _str[end];
				--end;
			}
			for (size_t i = 0; i < len; i++)
			{
				_str[pos + i] = str[i];
			}

			_size += len;
		}

		void erase(size_t pos, size_t len = npos)
		{
			assert(pos <= _size);

			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
				_str[_size] = '\0';
			}
			else
			{
				size_t end = pos + len;
				while (end <= _size)
				{
					_str[pos++] = _str[end++];
				}
				_size -= len;
			}
		}

		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}

			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			const char* ptr = strstr(_str, str);

			if (ptr)
			{
				return ptr - _str;
			}
			else
			{
				return npos;
			}
		}

		string substr(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);

			size_t n = len;
			if (len == npos || pos + len > _size)
			{
				n = _size - pos;
			}

			string tmp;

			tmp.reserve(n);
			for (size_t i = pos; i< pos + n; i++)
			{
				tmp += _str[i];
			}

			return tmp;
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0'; //比下标大1 
			}
			else
			{
				reserve(n);

				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}

				_size = n;
				_str[_size] = '\0';
			}
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		bool operator<(const string& s) const
		{
			//return strcmp(_str, s._str) < 0; // 无法比较有空格的情况
			size_t i1 = 0;
			size_t i2 = 0;
			while (i1 < _size && i2 < s.size())
			{
				if (_str[i1] < s._str[i2])
				{
					return true;
				}
				else if(_str[i1] > s._str[i2])
				{
					return false;
				}
				else
				{
					++i1;
					++i2;
				}
			}
			int ret = memcmp(_str, s._str, _size < s._size ? _size : s._size);
			return ret == 0 ? _size < s._size : ret < 0; //很复杂了，如果前面相等, 才往后判断
			//前面不等，直接判断ret大于还是小于0
		}

		bool operator==(const string& s) const
		{
			return _size == s._size && memcmp(_str, s._str, _size) == 0;
		}

		bool operator<=(const string& s) const
		{
			return *this < s || *this == s; // 复用
		}

		bool operator>(const string& s) const
		{
			return !(*this <= s);
		}

		bool operator>=(const string& s) const
		{
			return !(*this < s);
		}

		bool operator==(const string& s) const
		{
			return !(*this == s);
		}

	private:
		size_t _size;
		size_t _capacity;
		char* _str;

		static size_t npos; // 静态成员变量不可以给缺省值，
		//因为缺省值是给初始化列表的，但是静态成员变量不走初始化列表
		//静态成员变量是属于整个类的
		//const static size_t x = -1;//这是一个坑，别的类型都不行，不建议这样写
	};
	size_t string::npos = -1;//初始化时要加类名

	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();

		char ch = in.get();
		// 解决空格无法输入流的问题
		while (ch == ' ' || ch == '\n')
		{
			ch = in.get();
		}
		//满了再放进字符串中
		char buffer[128];
		int i = 0;
		//cin >> ch;   流输入以空格进行分割，会直接忽略他
		while ((ch != ' ') && (ch != '\n'))
		{
			buffer[i++] = ch;
			if (i == 127)
			{
				buffer[i] = '\0';
				s += buffer;
				i = 0;
			}
			ch = in.get();
		}

		if (i != 0)
		{
			buffer[i] = '\0';
			s += buffer;
		}

		return in;
	}
}

