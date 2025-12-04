#ifndef _CP_NETWORK_MARKETING_INCLUDED_
#define _CP_NETWORK_MARKETING_INCLUDED_

// you can include anything here
#include <bits/stdc++.h>

namespace CP
{

	template <typename T>
	class network_marketing
	{
	public:
		std::map<T, T> mParent;
		std::map<T, size_t> mCount;
		std::map<T, bool> hasParent;

		size_t count_children(T x)
		{
			return mCount[x];
		}

		void helper(T child, size_t cnt)
		{
			mCount[mParent[child]] += cnt;
			child = mParent[child];
			if (hasParent[child])
			{
				helper(child, cnt);
			}
		}

		void setparent(T child, T parent)
		{
			if (mCount.find(child) == mCount.end())
			{
				mCount[child] = 0;
			}
			if (mCount.find(parent) == mCount.end())
			{
				mCount[parent] = 0;
				mParent[parent] = -1;
				hasParent[parent] = false;
			}
			mParent[child] = parent;
			hasParent[child] = true;
			helper(child, mCount[child] + 1);
		}
	};

}
#endif