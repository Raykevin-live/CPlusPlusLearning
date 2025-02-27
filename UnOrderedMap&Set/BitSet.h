#pragma once

#include <vector>
using namespace std;

namespace lingze {

	//非类型模板参数
	template<size_t N>
	class bitset {
	public:
		bitset(){
			_a.resize(N/32 + 1, 0);
		}
		//x对应的位置标记为1
		void set(size_t x) {
			size_t i = x / 32;
			size_t j = x % 32;

			_a[i] |= (1 << j);
		}
		//x对应的位置标记为0
		void reset(size_t x) {
			size_t i = x / 32;
			size_t j = x % 32;

			_a[i] &= (~(1 << j));
		}
		bool test(size_t x) {
			size_t i = x / 32;
			size_t j = x % 32;

			return _a[i] & (1 << j);
		}

	private:
		vector<int> _a;
		size_t _bitCount;
	};
}