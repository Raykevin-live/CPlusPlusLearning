#pragma once

#include<iostream>
#include<cassert>
#include<cstring>

using namespace std;

namespace lingze
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			//cout << "string(char* str)" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;
			string tmp(s._str);
			swap(tmp);
		}
		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
			string tmp(s);
			swap(tmp);
			return *this;
		}
		// 移动构造
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- 移动语义" << endl;
			swap(s);
		}
		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动语义" << endl;
			swap(s);
			return *this;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
		char& operator[](size_t pos)
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
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}
			/*左值引用的使用场景：
				做参数和做返回值都可以提高效率。
				左值引用的短板：
				但是当函数返回对象是一个局部变量，出了函数作用域就不存在了，就不能使用左值引用返回，
				只能传值返回。例如：bit::string to_string(int value)函数中可以看到，这里只能使用传值返回，
				传值返回会导致至少1次拷贝构造(如果是一些旧一点的编译器可能是两次拷贝构造)。*/
				_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // 不包含最后做标识的\0
	};
}

