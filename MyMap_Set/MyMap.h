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
		typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::iterator iterator;

		iterator begin() {
			return _t.begin();
		}
		iterator end() {
			return _t.end();
		}
		bool Insert(const pair<K, V>& kv) {
			return _t.Insert(kv);
		}
	private:
		RBTree<K, pair<K, V>, MapKeyOfT> _t;
	};
}