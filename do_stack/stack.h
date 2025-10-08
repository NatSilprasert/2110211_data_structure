#ifndef _CP_STACK_INCLUDED_
#define _CP_STACK_INCLUDED_

#include <iostream>
#include <stdexcept>
#include <stack>

namespace CP { 

template <typename T>
class stack
{
  protected:
    T *mData;
    size_t mCap;
    size_t mSize;
    
    //-------------- auxiliary ----------
    std::stack<std::pair<int, T>> aux_stack_1;
    std::stack<std::pair<int, T>> aux_stack_2;

    void expand(size_t capacity) {
      T *arr = new T[capacity]();
      for (size_t i = 0;i < mSize;i++) {
        arr[i] = mData[i];
      }
      delete [] mData;
      mData = arr;
      mCap = capacity;
    }

    void ensureCapacity(size_t capacity) {
      if (capacity > mCap) {
        size_t s = (capacity > 2 * mCap) ? capacity : 2 * mCap;
        expand(s);
      }
    }

  public:
    //-------------- constructor ----------

    // copy constructor
    stack(const stack<T>& a) {
      this->mData = new T[a.mCap]();
      this->mCap = a.mCap;
      this->mSize = a.size();
      for (size_t i = 0;i < a.size();i++) {
        mData[i] = a.mData[i];
      }
    }

    // default constructor
    stack() {
      int cap = 1;
      mData = new T[cap]();
      mCap = cap;
      mSize = 0;
    }

    // copy assignment operator
    stack<T>& operator=(stack<T> other) {
      using std::swap;
      swap(mSize,other.mSize);
      swap(mCap,other.mCap);
      swap(mData,other.mData);
      return *this;
    }

    ~stack() {
      delete [] mData;
    }

    //------------- capacity function -------------------
    bool empty() const {
      return mSize == 0;
    }

    size_t size() const {
      return mSize;
    }

    //----------------- access -----------------
    const T& top() {
      if (size() == 0) throw std::out_of_range("index of out range") ;
      return mData[mSize-1];
    }

    //----------------- modifier -------------
    void push(const T& element);
    void pop();
    void undo();
    void redo();

    //-------------- FOR QUIZ ----------
    void print() {
      std::cout << "Stack Size: " << size() << '\n';
      std::cout << "Stack Capacity: " << mCap << '\n';
      std::cout << "Data: ";
      for (int i = 0; i < size(); ++i) std::cout << mData[i] << " ";
      std::cout << '\n';
    }
};


}

#endif