#include "stack.h"
#include "queue.h"

namespace CP
{
    template <typename T>
    void stack<T>::appendStack(stack<T> s)
    {
        stack<T> ss(s);
        for (size_t i = 0; i < size(); i++)
        {
            ss.push(mData[i]);
        }
        *this = ss;
    }

    template <typename T>
    void stack<T>::appendQueue(queue<T> q)
    {
        stack<T> ss;
        for (size_t i = 0; i < q.size(); i++)
        {
            ss.push(q.mData[q.size() - 1 - i]);
        }
        for (size_t i = 0; i < size(); i++)
        {
            ss.push(mData[i]);
        }
        *this = ss;
    }

    template <typename T>
    void queue<T>::appendStack(stack<T> s)
    {
        queue<T> qq(*this);
        for (size_t i = 0; i < s.size(); i++)
        {
            qq.push(s.mData[s.size() - i - 1]);
        }
        *this = qq;
    }

    template <typename T>
    void queue<T>::appendQueue(queue<T> q)
    {
        for (size_t i = 0; i < q.size(); i++)
        {
            push(q.mData[i]);
        }
    }
}