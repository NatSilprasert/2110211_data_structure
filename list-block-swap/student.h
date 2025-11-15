#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "list.h"

template <typename T>
void CP::list<T>::block_swap(iterator a1, iterator a2, iterator b1,
							 iterator b2)
{
	using std::swap;
	if (a2 == b1 || b2 == a1)
	{
		if (b2 == a1)
		{
			swap(a1, b1);
			swap(a2, b2);
		}
		a2--;
		b2--;
		a1.ptr->prev->next = b1.ptr;
		b1.ptr->prev = a1.ptr->prev;
		b2.ptr->next->prev = a2.ptr;
		a2.ptr->next = b2.ptr->next;
		b2.ptr->next = a1.ptr;
		a1.ptr->prev = b2.ptr;
		return;
	}

	swap(a1.ptr->prev->next, b1.ptr->prev->next);
	swap(a1.ptr->prev, b1.ptr->prev);
	swap(a2.ptr->prev->next, b2.ptr->prev->next);
	swap(a2.ptr->prev, b2.ptr->prev);
}

#endif