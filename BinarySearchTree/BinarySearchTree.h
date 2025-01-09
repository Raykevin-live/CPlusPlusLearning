#pragma once
using namespace std;

template<class K>
struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;
	BSTreeNode(const K& key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	BSTree()
		:_root(nullptr)
	{}
	BSTree(const BSTree<K>& t)
	{
		_root = Copy(t._root);
	}
	BSTree<K>& operator=(BSTree<K> t)
	{
		//cout << "=" << endl;
		std::swap(_root, t._root);
		return *this;
	}
	~BSTree()
	{
		Destory(_root);
	}
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* cur = _root;
		Node* parent = cur;

		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key);
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}
	
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					if (parent->_left == cur)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
				}
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					if (parent->_left == cur)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}
					return true; 
				}
				else
				{
					Node* leftMax = cur->_left;
					Node* leftMaxParent = cur;
					while (leftMax->_right)
					{
						leftMaxParent = cur;
						leftMax = leftMax->_right;
					}
					std::swap(cur->_key, leftMax->_key);
					//这地方可能不进去，在根上
					if (leftMaxParent->_left == leftMax)
					{
						leftMaxParent->_left = leftMax->_left;
					}
					else
					{
						leftMaxParent->_right = leftMax->_left;
					}
					cur = leftMax;
				}
				delete cur;
				return true;
			}
		}
		return false;
	}
	//递归版本实现
	bool FindR(const K& key)
	{
		return _FindR(_root, key);
	}
	bool InsertR(const K& key)
	{
		return _InsertR(_root, key);
	}
	bool EraseR(const K& key)
	{
		return _EraseR(_root, key);
	}
private:
	Node* Copy(const Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* copyroot = new Node(root->_key);
		copyroot->_left = Copy(root->_left);
		copyroot->_right = Copy(root->_right);
		return copyroot;
	}
	void Destory(Node*& root)
	{
		if (root == nullptr)
		{
			return;
		}
		Destory(root->_left);
		Destory(root->_right);
		delete root;
		root = nullptr;
	}
	//递归版本实现
	//巧用引用
	bool _EraseR(Node*& root, const K& key)
	{
		if (root == nullptr)
			return false;
		if (root->_key < key)
		{
			return _EraseR(root->_right, key);
		}
		else if (root->_key > key)
		{
			return _EraseR(root->_left, key);
		}
		else
		{
			Node* del = root;
			//1. 左为空
			//2. 右为空
			//3. 左右都不为空
			if (root->_left == nullptr)
			{
				root = root->_right;
			}
			else if (root->_right == nullptr)
			{
				root = root->_left;
			}
			else
			{
				Node* leftMax = root->_left;
				while (leftMax->_right)
				{
					leftMax = leftMax->_right;
				}
				swap(root->_key, leftMax->_key);
				return _EraseR(root->_left, key);
			}
			delete del;
			return true;
		}
	}
	bool _InsertR(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			root = new Node(key);
			return true;
		}
		if (root->_key < key)
		{
			return _InsertR(root->_right, key);
		}
		else if (root->_key > key)
		{
			return _InsertR(root->_left, key);
		}
		else {
			//已经有了就不在插入
			return false;
		}
	}
	bool _FindR(Node* root, const K& key) 
	{
		if (root == nullptr)
		{
			return false;
		}
		if (root->_key < key)
		{
			return _FindR(root->_right, key);
		}
		else if (root->_key > key)
		{
			return _FindR(root->_left, key);
		}
		else {
			return true;
		}
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << ' ';
		_InOrder(root->_right);
	}
	Node* _root;
};


