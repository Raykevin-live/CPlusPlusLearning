#pragma once
#include <string>
#include "BitSet.h"

using namespace std;


struct BKDRHash {
	size_t operator()(const string& str) {
		register size_t hash = 0;
		//BKDR
		for (auto ch : str) {
			hash *= 131;
			hash += ch;
		}
		return hash;
	}
};

struct APRHash
{
	size_t operator()(const string& str) {
		register size_t hash = 0;
		//BKDR
		for (size_t i = 0; i < str.size(); i++) {
			size_t ch = str[i];

			if ((i & 1) == 0) {
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else {
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
};

struct DJB2Hash
{
	size_t operator()(const string& str)
	{
		if (!str[0])   // 这是由本人添加，以保证空字符串返回哈希值0  
			return 0;
		register size_t hash = 5381;
		for (size_t i = 0; i < str.size(); i++)
		{
			size_t ch = str[i];
			hash = hash * 33 ^ ch;
		}
		return hash;
	}
};

//一般不支持删除
namespace lingze {

	template<size_t N, class K = string, class Hash1 = BKDRHash, class Hash2 = APRHash, class Hash3 = DJB2Hash>
	class bloomfilter {
	public:
		void set(const K& key) {
			size_t hash1 = Hash1()(key) % N;
			_bs.set(hash1);

			size_t hash2= Hash2()(key) % N;
			_bs.set(hash2);

			size_t hash3 = Hash3()(key) % N;
			_bs.set(hash3);

		}

		bool test(const K& key) {
			size_t hash1 = Hash1()(key) % N;
			if (_bs.test(hash1) == false)
				return false;

			size_t hash2 = Hash2()(key) % N;
			if (_bs.test(hash2) == false)
				return false;

			size_t hash3 = Hash3()(key) % N;
			if (_bs.test(hash2) == false)
				return false;

			return true;//存在误判
		}

	private:
		bitset<N> _bs;
	};
}