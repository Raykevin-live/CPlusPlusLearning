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
		typedef typename hash_bucket::HashTable<K, K, SetKeyOfT>::iterator iterator;

		iterator begin() {
			return _ht.begin();
		}

		iterator end() {
			return _ht.end();
		}

		bool Insert(const K& key) {
			return _ht.Insert(key);
		}

	private:
		hash_bucket::HashTable<K, K, SetKeyOfT> _ht;
	};
}