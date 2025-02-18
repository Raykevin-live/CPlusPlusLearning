#pragma once
#include"HashTable.h"

namespace lingze {
	template<class K, class V>
	class unordered_map {
		//内部类
		struct MapKeyOfT {
			const K& operator()(const pair<const K, V>& kv) {
				return kv.first;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT>::const_iterator const_iterator;

		iterator begin() {
			return _ht.begin();
		}
		iterator end() {
			return _ht.end();
		}

		const_iterator begin() const {
			return _ht.begin();
		}

		const_iterator end() const {
			return _ht.end();
		}

		//注意这里pair中的实际上是const版本
		pair<const_iterator, bool> Insert(const pair<K, V>& kv) {
			return _ht.Insert(kv);
			/*pair<typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT>::iterator, bool> ret = _ht.Insert(key);
			return pair<const_iterator, bool>(ret.first, ret.second);*/
		}

		V& operator[](const K& key) {
			pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
			return ret.first->second;
		}
	private:
		hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT> _ht;
	};
}