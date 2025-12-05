#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "list.h"

template <typename T>
typename CP::list<T>::iterator CP::list<T>::insert(typename CP::list<T>::iterator it, const T &element)
{
    node *p = it.ptr->get_prev();
    node *q = it.ptr;

    node *n = (q != mHeader && q->get_next() != mHeader)
                  ? new node(element, p, q, q->get_next())
                  : new node(element, p, q, nullptr);

    p->set_next(n);
    q->set_prev(n);

    if (q != mHeader)
    {
        p->set_nextnext(q);
    }
    else
    {
        p->set_nextnext(nullptr);
    }

    if (p != mHeader)
    {
        p->get_prev()->set_nextnext(n);
    }
    else
    {
        p->get_prev()->set_nextnext(nullptr);
    }

    mSize++;
    return iterator(n);
}

template <typename T>
T CP::list<T>::at(size_t k)
{
    if (k >= mSize)
        throw std::out_of_range("index of out range");

    node *cur = mHeader->get_next();
    while (k >= 2)
    {
        cur = cur->get_nextnext();
        k -= 2;
    }
    while (k > 0)
    {
        cur = cur->get_next();
        k--;
    }

    return cur->data;
}

template <typename T>
typename CP::list<T>::iterator CP::list<T>::erase(typename CP::list<T>::iterator it)
{
    node *p = it.ptr->get_prev();
    node *q = it.ptr->get_next();
    node *r = it.ptr->get_nextnext();

    p->set_next(q);
    q->set_prev(p);

    delete it.ptr;
    mSize--;

    p->set_nextnext(r);

    if (p != mHeader && p->get_next() != mHeader)
    {
        p->get_prev()->set_nextnext(p->get_next());
    }
    else
    {
        p->get_prev()->set_nextnext(nullptr);
    }

    return iterator(q);
}

#endif
