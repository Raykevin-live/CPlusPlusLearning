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
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;

		iterator begin() const{
			return _t.begin();
		}
		iterator end() const{
			return _t.end();
		}

		/*const_iterator begin() const {
			return _t.begin();
		}
		const_iterator end() const{
			return _t.end();
		}*/

		pair<iterator, bool> Insert(const K& key) {
			pair<typename RBTree<K, K, SetKeyOfT>::iterator, bool> ret = _t.Insert(key);
			return  ret;
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}