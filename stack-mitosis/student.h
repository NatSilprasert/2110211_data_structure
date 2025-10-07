// #ifndef __STACK_STUDENT_H__
// #define __STACK_STUDENT_H__
// #include "stack.h"

// template <typename T>
// void CP::stack<T>::mitosis(int a, int b)
// {
//     CP::stack<T> st;
//     for(int i=0;i<a;i++){
//         st.push(top());
//         pop();
//     }
//     for(int i=a;i<=b;i++){
//         st.push(top());
//         st.push(top());
//         pop();
//     }
//     while(!st.empty()){
//         push(st.top());
//         st.pop();
//     }

// }

// #endif

#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    CP::stack<T> st;
    for (int i = 0; i < a; i++)
    {
        st.push(top());
        pop();
    }
    for (int i = a; i <= b; i++)
    {
        st.push(top());
        st.push(top());
        pop();
    }
    while (!st.empty())
    {
        push(st.top());
        st.pop();
    }
}

#endif
