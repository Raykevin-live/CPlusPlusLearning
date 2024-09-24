#pragma once

#include <iostream>
#include <cstdlib>
#include <assert.h>

using namespace std;
//string ʵ��

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

		//���캯��
		//string(const char* str)
		//	:_size(strlen(str))
		//	,_capacity(_size)
		//	,_str(new char[_capacity + 1])//ע���ʼ���б��˳��
		//{
		//	strcpy(_str, str);
		//}
		// 
		//�޲�
		//string()
		//	:_size(0)
		//	, _capacity(_size)
		//	, _str(new char[1])//ע���ʼ���б��˳��
		//{
		//	_str[0] = '\0';
		//}

		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			//strcpy(_str, str); // ����'\0' �������
			memcpy(_str, str, _size + 1); // _size+1 ����Ϊ'\0' 
		}

		//�������������
		string(const string& s)
		{
			_str = new char[s._capacity + 1];
			//strcpy(_str, s._str);
			memcpy(_str, s._str, s._size + 1);
			_size = s._size;
			_capacity = s._capacity;
		}

		//��ֵ������, ���
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
		//�ִ��ĸ�ֵд��
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
		//���򵥵�д��
		string& operator=(string tmp)
		{
			swap(tmp);

			return *this;
		}

		//��������
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
				//2������
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
				//�������ݵ�_size + len
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
				//�������ݵ�_size + len
				reserve(_size + n);
			}
			//Ų������
			int end = (int)_size; //����ʱend = -1(��pos = 0)
			while (end >= (int)pos) //������������
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
				//�������ݵ�_size + len
				reserve(_size + len);
			}
			//Ų������
			int end = (int)_size; //����ʱend = -1(��pos = 0)
			while (end >= (int)pos) //������������
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
				_str[_size] = '\0'; //���±��1 
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
			//return strcmp(_str, s._str) < 0; // �޷��Ƚ��пո�����
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
			return ret == 0 ? _size < s._size : ret < 0; //�ܸ����ˣ����ǰ�����, �������ж�
			//ǰ�治�ȣ�ֱ���ж�ret���ڻ���С��0
		}

		bool operator==(const string& s) const
		{
			return _size == s._size && memcmp(_str, s._str, _size) == 0;
		}

		bool operator<=(const string& s) const
		{
			return *this < s || *this == s; // ����
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

		static size_t npos; // ��̬��Ա���������Ը�ȱʡֵ��
		//��Ϊȱʡֵ�Ǹ���ʼ���б�ģ����Ǿ�̬��Ա�������߳�ʼ���б�
		//��̬��Ա�����������������
		//const static size_t x = -1;//����һ���ӣ�������Ͷ����У�����������д
	};
	size_t string::npos = -1;//��ʼ��ʱҪ������

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
		// ����ո��޷�������������
		while (ch == ' ' || ch == '\n')
		{
			ch = in.get();
		}
		//�����ٷŽ��ַ�����
		char buffer[128];
		int i = 0;
		//cin >> ch;   �������Կո���зָ��ֱ�Ӻ�����
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

