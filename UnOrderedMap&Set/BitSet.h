#pragma once

#include <vector>
using namespace std;

namespace lingze {

	//������ģ�����
	template<size_t N>
	class bitset {
	public:
		bitset(){
			_a.resize(N/32 + 1, 0);
		}
		//x��Ӧ��λ�ñ��Ϊ1
		void set(size_t x) {
			size_t i = x / 32;
			size_t j = x % 32;

			_a[i] |= (1 << j);
		}
		//x��Ӧ��λ�ñ��Ϊ0
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