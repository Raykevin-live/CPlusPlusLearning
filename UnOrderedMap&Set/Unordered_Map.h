#pragma once
#include"HashTable.h"

namespace lingze {
	template<class K, class V>
	class unordered_map {
		//ÄÚ²¿Àà
		struct MapKeyOfT {
			const K& operator()(const pair<K, V>& kv) {
				return kv.first;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, pair<K, V>, MapKeyOfT>::iterator iterator;

		iterator begin() {
			return _ht.begin();
		}

		iterator end() {
			return _ht.end();
		}

		bool Insert(const pair<K, V>& kv) {
			return _ht.Insert(kv);
		}

	private:
		hash_bucket::HashTable<K, pair<K, V>, MapKeyOfT> _ht;
	};
}