#pragma once
#include <cassert>

namespace ling
{
	template<typename T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _val;

		list_node(const T& val = T()) //缺省值初始化
			:_next(nullptr)
			,_prev(nullptr)
			,_val(val)
		{}
	};

	template<typename T, typename Ref, typename Ptr>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}


		/*T& operator*()
		{
			return _node -> _val;
		}*/

		Ref operator*()
		{
			return _node->_val;
		}

		Ptr operator->()
		{
			return &_node->_val;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator--(int)
		{
			__list_iterator<T> tmp(*this);

			_node = _node->_prev;
			return *this; 
		}

		bool operator!=(const self& it)
		{
			return _node != it._node;
		}

		bool operator==(const self& it)
		{
			return _node == it._node;
		}

	};
	
	template<typename T> 
	class list 
	{
		typedef list_node<T> Node;//私有，只给自己用
	public:
		typedef __list_iterator<T, T&, T> iterator;
		//设计const迭代器
		typedef __list_iterator<T, const T&, T> const_iterator;

		iterator begin()  //迭代器对象不写析构，是由容器释放的
		{
			//return _head->_next; //单参数的类型支持隐式类型转换
			return iterator(_head->_next); // 相当于这个
		}

		const_iterator begin() const 
		{
			return const_iterator(_head->_next); 
		}

		iterator end()
		{
			return _head; //单参数的类型支持隐式类型转换
			//return iterator(_head); // 相当于这个
		}

		const_iterator end() const
		{
			return _head; //单参数的类型支持隐式类型转换
			//return iterator(_head); // 相当于这个
		}

		void empty_init()
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
			_size = 0;
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);

		}

		list<T>& operator=(list<T> lt) //list<T> 才是类型，模板中list不是类型，但是这里也可以识别list
		{
			swap(lt);
			return *this;
		}

		list()
		{
			empty_init();
		}

		//ls2(lt1)
		list(const list<T>& lt)
		{
			empty_init();

			for (auto& e : lt)
			{
				push_back(e);
			}
		}

		/*void push_back(const T& x)
		{
			Node* tail = _head->_prev;
			Node* newnode = new Node(x);

			tail->_next = newnode;
			newnode->_prev = tail;

			newnode->_next = _head;
			_head->_prev = newnode;
		}*/

		//调用函数
		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		//pos 位置之前插入
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			prev->_next = newnode;
			newnode->_next = cur;

			cur->_prev = newnode;
			newnode->_prev = prev;

			++_size;
			return newnode;
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;

			delete cur;
			--_size;

			return next;
		}

		size_t size()
		{
			return _size;
		}
		 
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it); //erase之后it就失效了
			}

			_size = 0;
		}

		~list()
		{
			clear();

			delete _head;
			_head = nullptr;
		}
	private:
		Node* _head;
		size_t _size;
	};
}


