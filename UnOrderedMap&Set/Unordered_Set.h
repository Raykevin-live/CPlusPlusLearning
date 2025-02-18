#pragma once
#include"HashTable.h"

namespace lingze {
	template<class K>
	class unordered_set {
		struct SetKeyOfT {
			const K& operator()(const K& key) {
				return key;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename hash_bucket::HashTable<K, K, SetKeyOfT>::const_iterator const_iterator;

		iterator begin() const{
			return _ht.begin();
		}

		iterator end() const{
			return _ht.end();
		}

		pair<iterator, bool> Insert(const K& key) {
			//return _ht.Insert(key);
			pair<typename hash_bucket::HashTable<K, K, SetKeyOfT>::iterator, bool> ret = _ht.Insert(key);
			return pair<const_iterator, bool>(ret.first, ret.second);
		}

	private:
		hash_bucket::HashTable<K, K, SetKeyOfT> _ht;
	};
}