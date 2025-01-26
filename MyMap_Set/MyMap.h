#pragma once
#include<iostream>
//#include<vector>
#include "RBTree.h"

using namespace std;

namespace lingze {
	template<class K, class V>
	class map {
		struct MapKeyOfT {
			MapKeyOfT(){}
			const K& operator()(const pair<K, V>& kv) {
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::const_iterator const_iterator;

		iterator begin() {
			return _t.begin();
		}
		iterator end() {
			return _t.end();
		}
		/*bool insert(const pair<K, V>& kv) {
			return _t.Insert(kv);
		}*/
		V& operator[](const K& key) {
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}
		pair<iterator, bool> insert(const pair<K, V>& kv) {
			return _t.Insert(kv);
		}
	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};
}