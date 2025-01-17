#pragma once
#include<iostream>
//#include<vector>
//#include "MySet.h"
//#include "MyMap.h"
using namespace std;

enum Color {
	RED,
	BLACK
};


//泛型编程
template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	Color _col;

	RBTreeNode(const T& data)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)
	{}
};

template<class T>
struct __TreeIterator {
	typedef RBTreeNode<T> Node;
public:
	typedef __TreeIterator<T> Self;
	Node* _node;

	__TreeIterator(Node* node)
		:_node(node)
	{}

	T& operator*() {
		return _node->_data;
	}
	T* operator->() {
		return &_node->_data;
	}
	bool operator!=(const Self& s) {
		return _node != s._node;
	}
	Self& operator++() {
		if (_node->_right) {
			// 右树的最左节点
			Node* subLeft = _node->_right;
			while (subLeft->_left) {
				subLeft = subLeft->_left;
			}
			_node = subLeft;
		}
		else {
			Node* cur = _node;
			Node* parent = cur->_parent;
			// 找父亲是左的那个祖先节点，就是下一个要访问的节点
			while (parent) {
				if (cur==parent->_left) {
					break;
				}
				else {
					cur = parent;
					parent = parent->_parent;
				}
			}
			_node = parent;
		}
		return *this;
	}
};

template<class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef __TreeIterator<T> iterator;

	iterator begin() {
		Node* leftMin = _root;
		while (leftMin && leftMin->_left) {
			leftMin = leftMin->_left;
		}
		return iterator(leftMin);
	}

	iterator end() {
		return iterator(nullptr);
	}
	bool Insert(const T& data )
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return true;
		}

		Node* cur = _root;
		Node* parent = cur->_parent;

		KeyOfT kot;
		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		// 插入
		cur = new Node(data);
		cur->_col = RED;
		//KeyOfT kot;
		if (kot(parent->_data) < kot(data))
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		// 调整
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					//变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					//继续向上更新
					cur = grandfather;
					parent = cur->_parent;
				}
				else //uncle不存在或者为黑
				{
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else // parent 在右
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					//变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					//继续向上更新
					cur = grandfather;
					parent = cur->_parent;
				}
				else //uncle不存在或者为黑
				{
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}

		_root->_col = BLACK;
		return true;
	}
	Node* Find(const K& key) {
		Node* cur = _root;
		KeyOfT kot;
		while (cur) {
			if (kot(cur->_data) < key) {
				cur = cur->_right;
			}
			else if(kot(cur->_data) > key){
				cur = cur->_left;
			}
			else {
				return cur;
			}
		}
		return nullptr;
	}
	void RotateL(Node* parent)
	{
		Node* cur = parent->_right;
		Node* curleft = cur->_left;

		parent->_right = curleft;
		if (curleft)
		{
			curleft->_parent = parent;
		}
		cur->_left = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = cur;

		if (parent == _root)
		{
			_root = cur;
			cur->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = cur;
			}
			else
			{
				ppnode->_right = cur;
			}
			cur->_parent = ppnode;
		}

	}
	void RotateR(Node* parent)
	{
		Node* cur = parent->_left;
		Node* curright = cur->_right;

		parent->_left = curright;
		if (curright)
		{
			curright->_parent = parent;
		}
		cur->_right = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = cur;

		if (parent == _root)
		{
			_root = cur;
			cur->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = cur;
			}
			else
			{
				ppnode->_right = cur;
			}
			cur->_parent = ppnode;
		}
	}
	bool CheckColor(Node* root, int blackNum, int benchmark)
	{
		if (root == nullptr)
		{
			if (blackNum != benchmark)
				return false;
			return true;
		}
		if (root->_col == BLACK)
		{
			++blackNum;
		}
		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			cout << root->_kv.first << "出现连续红色节点" << endl;
			return false;
		}
		return CheckColor(root->_left, blackNum, benchmark)
			&& CheckColor(root->_right, blackNum, benchmark);

	}
	bool IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;
		if (_root->_col == RED)
			return false;
		//基准值
		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
			{
				++benchmark;
			}

			cur = cur->_left;
		}
		return CheckColor(root, 0, benchmark);

	}

	bool IsBalance()
	{
		return IsBalance(_root);
	}
private:
	Node* _root = nullptr;
};


