#pragma once

namespace ling
{
	template<typename T, typename Container = vector<T>>
	class prority_queue
	{
	private:
		void AdjustDown(int parent)
		{
			// 找左右孩子的大的一个
			int child = parent * 2 + 1; //假设是左孩子
			if (child + 1 < _con.size() && _con[child + 1] > _con[child])
			{
				++child;
			}
			while (child <= _con.size())
			{
				if (_con[child] > _con[parent])
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void AdjustUp(int child)
		{
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (_con[child] > _con[parent])
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
	public:
		template<typename InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				_con.push_back(*first);
				++first;
			}

			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; i--)
			{
				AdjustDown(i);
			}
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);//根开始向下调整
		}

		void push(const T& x)
		{
			_con.push_back(x);

			AdjustUp(_con.size()-1);
		}

		bool empty()
		{
			return _con.empty();
		}

		size_t size()
		{
			return _con.size();
		}
	private:
		Container _con;
	};
}