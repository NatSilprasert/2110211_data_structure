#include <iostream>

#include "sparse_vector.h"
#include "student.h"

void test() {
  CP::sparse_vector<int> sv;

  while (true) {
    std::string c; std::cin >> c;

    //quit
    if (c == "q") break;
    
    //size
    if (c == "sz") {
      std::cout << sv.size() << '\n';
    }
    
    //push_back
    if (c == "pb") {
      int x; std::cin >> x;
      sv.push_back(x);
    }
    
    //insert
    if (c == "in") {
      int pos; int x;
      std::cin >> pos >> x;
      sv.insert(pos, x);
    }
    
    //resize
    if (c == "rz") {
      int newSize; std::cin >> newSize;
      sv.resize(newSize);
    }
    
    //range_reserve
    if (c == "rr") {
      int l, r;
      std::cin >> l >> r;
      sv.range_reserve(l, r);
    }
  }
  sv.print();
}

signed main() {
  int T; std::cin >> T;
  while (T--) {
    test();
  }
  return 0;
}