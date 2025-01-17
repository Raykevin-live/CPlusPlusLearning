#pragma once
#include<iostream>
//#include<vector>
#include "RBTree.h"

using namespace std;

namespace lingze {
	template<class K>
	class set {
		struct SetKeyOfT {
			SetKeyOfT(){}
			const K& operator()(const K& key) {
				return key;
			}
		};
	public:
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;

		iterator begin() {
			return _t.begin();
		}
		iterator end() {
			return _t.end();
		}

		bool Insert(const K& key) {
			return _t.Insert(key);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}