#pragma once
#include<vector>
#include<string>
#include<iostream>
using namespace std;

namespace open_addr {
	enum STATE {
		EXIST,
		EMPTY,
		DELETE
	};

	template<class K, class V>
	struct HashData {
		pair<K, V> _kv;
		STATE _state = EMPTY;
	};

	// 仿函数
	template<class K>
	struct DefaultHashFunc {
		size_t operator()(const K& key) {
			return (size_t)key;
		}
	};
	//struct StringHashFunc {
	//	size_t operator()(const string& str) {
	//		return str[0];
	//	}
	//};
	// 模板特化
	template<>
	struct DefaultHashFunc<string> {
		size_t operator()(const string& str) {
			size_t hash = 0;
			//BKDR
			for (auto ch : str) {
				hash *= 131;
				hash += ch;
			}
			return hash;
		}
	};

	template<class K, class V, class HashFunc = DefaultHashFunc<K>>
	class HashTable {
	public:
		HashTable() {
			_table.resize(10);
		}
		bool Insert(const pair<K, V>& kv) {
			if (Find(kv.first)) {
				return false;
			}
			//扩容
			if (_n * 10 / _table.size() >= 7) {
				size_t newSize = _table.size() * 2;
				_table.resize(newSize);

				//遍历旧表重新映射到新表
				HashTable<K, V, HashFunc> newT;
				newT._table.resize(newSize);

				//遍历旧表插入到新表
				for (size_t i = 0; i < _table.size(); i++) {
					if (_table[i]._state == EXIST) {
						newT.Insert(_table[i]._kv);
					}
				}

				_table.swap(newT._table);
			}

			//线性探测
			HashFunc hf;
			size_t hashi = hf(kv.first) % _table.size();

			while (_table[hashi]._state == EXIST) {
				++hashi;
				hashi %= _table.size();
			}
			_table[hashi]._kv = kv;
			_table[hashi]._state = EXIST;
			++_n;

			return true;
		}

		HashData<const K, V>* Find(const K& key) {
			//线性探测
			HashFunc hf;
			size_t hashi = hf(key) % _table.size();
			while (_table[hashi]._state != EMPTY) {
				if (_table[hashi]._state == EXIST &&
					_table[hashi]._kv.first == key) {
					return (HashData<const K, V>*) & _table[hashi];
				}
				++hashi;
				hashi %= _table.size();
			}
			return nullptr;
		}

		bool Erase(const K& key) {
			HashData<const K, V>* ret = Find(key);
			if (ret) {
				ret->_state = DELETE;
				--_n;

				return true;
			}
			else {
				return false;
			}
		}
	private:
		vector<HashData<K, V>> _table;
		size_t _n = 0; // 存储的有效数据的个数
	};
}

namespace hash_bucket {
	template<class T>
	struct HashNode {
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			,_next(nullptr)
		{}
	};

	// 前置声明
	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable;

	template<class K, class T, class KeyOfT, class HashFunc>
	struct HTIterator {
		typedef HashNode<T> Node;
		typedef HTIterator<K, T, KeyOfT, HashFunc> Self;

		Node* _node;
		HashTable<K, T, KeyOfT, HashFunc>* _pht;

	public:
		HTIterator( Node* node, HashTable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node) 
			,_pht(pht)
		{}

		Self& operator++() {
			//当前桶没完
			if (_node->_next) {
				_node = _node->_next;
			}
			else {
				//当前桶完了
				KeyOfT kot;
				HashFunc hf;
				size_t hashi = hf(kot(_node->_data)) % _pht->_table.size();
				++hashi;
				//查找下一个不为空的桶
				while (hashi < _pht->_table.size()) {
					if (_pht->_table[hashi]) {
						_node = _pht->_table[hashi];
						return *this;
					}
					else {
						++hashi;
					}
				}

				_node = nullptr;
			}
			return *this;
		}

		T& operator*() {
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const Self& s) {
			return _node != s._node;
		}
	};

	template<class K>
	struct DefaultHashFunc {
		size_t operator()(const K& key) {
			return (size_t)key;
		}
	};
	// 模板特化
	template<>
	struct DefaultHashFunc<string> {
		size_t operator()(const string& str) {
			size_t hash = 0;
			//BKDR
			for (auto ch : str) {
				hash *= 131;
				hash += ch;
			}
			return hash;
		}
	};

	// set-> hash_bucket::HashTable<K, K> _ht;
	// map-> hash_bucket::HashTable<K, pair<K, V>> _ht;
	template<class K, class T, class KeyOfT, class HashFunc = DefaultHashFunc<K>>
	class HashTable {
		typedef HashNode<T> Node;
		//友元声明
		template<class K, class T, class KeyOfT, class HashFunc>
		friend struct HTIterator;
	public:
		typedef HTIterator<K, T, KeyOfT, HashFunc> iterator;
		iterator begin() {
			//找第一个桶
			for (size_t i = 0; i < _table.size(); i++) {
				Node* cur = _table[i];
				if (cur) {
					return iterator(cur, this);
				}
			}
			return iterator(nullptr, this);
		}

		iterator end() {
			return iterator(nullptr, this);
		}
	public:
		HashTable() {
			_table.resize(10, nullptr);
		}

		HashTable(HashTable<K, T, KeyOfT>& HT) {
			_table.resize(HT._table.size(), nullptr);

			for (size_t i = 0; i < HT._table.size(); i++) {
				Node* cur = HT._table[i];
				while (cur) {
					Insert(cur->_data);
					cur = cur->_next;
				}
			}
		}

		~HashTable() {
			for (size_t i = 0; i < _table.size(); i++) {
				Node* cur = _table[i];
				while (cur) {
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
		}
		bool Insert(const T& data) {
			KeyOfT kot;
			if (Find(kot(data))){
				return false;
			}
			HashFunc hf;
			// 负载因子到1 就开始扩容
			if (_n == _table.size()) {
				size_t newSize = _table.size() * 2;
				vector<Node*> newTable;
				newTable.resize(newSize, nullptr);

				//遍历旧表，顺手牵羊，挂到新表（头插）
				for (size_t i = 0; i < _table.size(); i++) {
					Node* cur = _table[i];
					while (cur) {
						Node* next = cur->_next;

						//头插到新表
						size_t hashi = hf(kot(cur->_data)) % newSize;
						cur->_next = newTable[hashi];
						newTable[hashi] = cur;

						cur = next;
					}
					//旧表置空
					_table[i] = nullptr;
				}
				//交换
				_table.swap(newTable);
			}
			size_t hashi = hf(kot(data)) % _table.size();
			Node* newnode = new Node(data);
			// 头插
			newnode->_next = _table[hashi];
			_table[hashi] = newnode;
			++_n;
			return true;
		}

		Node* Find(const K& key) {
			HashFunc hf;
			KeyOfT kot;
			size_t hashi = hf(key) % _table.size();
			Node* cur = _table[hashi];
			while (cur) {
				if (kot(cur->_data) == key) {
					return cur;
				}
				cur = cur->_next;
			}
			return nullptr;
		}

		bool Erase(const K& key) {
			HashFunc hf;

			size_t hashi = hf(key) % _table.size();
			Node* prev = nullptr;
			Node* cur = _table[hashi];
			while (cur) {
				if (cur->_kv.first == key) {
					if (prev == nullptr) {
						_table[hashi] = cur->_next;
					}
					else {
						prev->_next = cur->_next;
					}

					delete cur;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}

		void Print() {
			for (size_t i = 0; i < _table.size(); i++) {
				printf("[%d]->", i);
				Node* cur = _table[i];
				while (cur) {
					cout << cur->_kv.first << ":"<<cur->_kv.second<< "->";
					cur = cur->_next;
				}
				printf("NULL\n");
			}
			cout << endl;

		}
	private:
		//Node** _table; //每个数据是Node*
		vector<Node*> _table;//使用vector更简单
		size_t _n = 0;
	};
}