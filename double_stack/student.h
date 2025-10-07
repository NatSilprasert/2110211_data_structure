#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <stack>
template <typename T>
void balance(std::stack<T> &a, std::stack<T> &b) {
	if (a.empty()) {
		std::stack<T> spare;
		for (int i = 0; i < b.size() / 2; i++)
		{
			spare.push(b.top());
			b.pop();
		}
		while (!b.empty())
		{
			a.push(b.top());
			b.pop();
		}
		while (!spare.empty())
		{
			b.push(spare.top());
			spare.pop();
		}
	}
}

template <typename T>
void CP::stack<T>::pop()
{
	// modify method here
	balance(stack_a, stack_b);
	stack_a.pop();
}

template <typename T>
const T &CP::stack<T>::top()
{
	// modify method here
	balance(stack_a, stack_b);
	return stack_a.top();
}

template <typename T>
const T &CP::stack<T>::bottom()
{
	// write your code here
	balance(stack_b, stack_a);
	return stack_b.top();
}

template <typename T>
void CP::stack<T>::push_bottom(const T &element)
{
	// write your code here
	balance(stack_b, stack_a);
	stack_b.push(element);
}

template <typename T>
void CP::stack<T>::pop_bottom()
{
	// write your code here
	balance(stack_b, stack_a);
	stack_b.pop();
}
#endif