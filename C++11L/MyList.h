#pragma once


namespace lingze {
	template<class T>
	struct ListNode
	{
		ListNode* _next = nullptr;
		ListNode* _prev = nullptr;
		T _data;

	};
	template<class T>
	class List
	{
		typedef ListNode<T> Node;
	public:
		List()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		void PushBack(T&& x)
		{
			//Insert(_head, x);
			Insert(_head, std::forward<T>(x));
		}
		void PushFront(T&& x)
		{
			//Insert(_head->_next, x);
			Insert(_head->_next, std::forward<T>(x));
		}
		void Insert(Node* pos, T&& x)
		{
			Node* prev = pos->_prev;
			Node* newnode = new Node;
			newnode->_data = std::forward<T>(x); // 关键位置
			// prev newnode pos
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = pos;
			pos->_prev = newnode;

			cout << "INsert--T&& x" << endl;

		}
		void Insert(Node* pos, const T& x)
		{
			Node* prev = pos->_prev;
			Node* newnode = new Node;
			newnode->_data = x; // 关键位置
			// prev newnode pos
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = pos;
			pos->_prev = newnode;
			cout << "INsert--const T& x" << endl;
		}
	private:
		Node* _head;
	};
}