#ifndef _CP_SPARSE_VECTOR_INCLUDED_
#define _CP_SPARSE_VECTOR_INCLUDED_

#include <iostream>
#include <stdexcept>
#include <map>

namespace CP {

template <typename T>
class sparse_vector {
  protected: 
    std::map<int, T> mData;
    size_t mSize;

  public:
    //-------------- constructor ----------

    // copy constructor
    sparse_vector(const sparse_vector<T>& a) {
      this->mData = a.mData;
      this->mSize = a.mSize;
    }

    // default constructor
    sparse_vector() {
      mSize = 0;
    }

    sparse_vector(size_t sz) {
      mSize = sz;
    }

    ~sparse_vector() {
    }

    //------------- capacity function -------------------
    bool empty() const {
      return mSize == 0;
    }

    size_t size() const {
      return mSize;
    }

    //----------------- modifiers -----------------
    void insert(int index, const T& element) {
      mSize++;
      auto it = mData.end();
      while (it != mData.begin()) {
        --it;
        if (it->first >= index) {
          mData.insert(std::make_pair(it->first + 1, it->second));
          it = mData.erase(it);
        } else {
          break;
        }
      }
      mData.insert(std::make_pair(index, element));
    }

    void push_back(const T& element) {
      int index = size();
      mData.insert(std::make_pair(index, element));
      mSize++;
    }

    void clear() {
      mSize = 0;
      mData.clear();
    }

    void resize(int newSize) {
      if (newSize < 0) {
        throw std::out_of_range("new size of out range") ;
      }
      auto it = mData.lower_bound(newSize);
      while (it != mData.end()) {
        it = mData.erase(it);
      }
      mSize = newSize;
    }

    void range_reserve(int left, int right);

    //----------------- access -----------------
    T& at(int index) {
      if (index < 0 || (size_t)index >= size()) {
        throw std::out_of_range("index of out range") ;
      }
      if (mData.find(index) == mData.end()) {
        mData[index] = T();
      }
      return mData[index];
    }

    const T& at(int index) const {
      if (index < 0 || (size_t)index >= size()) {
        throw std::out_of_range("index of out range") ;
      }
      auto it = mData.find(index);
      if (it == mData.end()) {
        static const T default_value = T();
        return default_value;
      }
      return it->second;
    }

    T& operator[](int index) {
      return at(index);
    }

    const T& operator[](int index) const {
      return at(index);
    }

    //----------------- for quiz -----------------
    void print() {
      std::cout << "Sparse Vector Size: " << mSize << std::endl;
      std::cout << "Sparse Vector Content:" << std::endl;
      for (const auto& pair : mData) {
        std::cout << "[" << pair.first << "] = " << pair.second << std::endl;
      }
    }
};

}

#endif
