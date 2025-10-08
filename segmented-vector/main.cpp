#include <iostream>

#include "segmented_vector.h"
#include "student.h"

static const std::string LINE_BREAK = "-------------------------";

void test(int bs) {
  CP::SegmentedVector<int> sv(bs);
  while (true) {
    std::string c; std::cin >> c;

    //quit
    if (c == "q") break;
    //print size
    if (c == "si") {
      std::cout << sv.size() << '\n';
    }
    //access
    if (c == "ac") {
      int i; 
      std::cin >> i;
      std::cout << sv[i] << '\n';
    }
    //push_back
    if (c == "pb") {
      int value; 
      std::cin >> value;
      sv.push_back(value);
    }
    //insert
    if (c == "in") {
      int position, value;
      std::cin >> position >> value;
      sv.insert(position, value);
    }
    //pop
    if (c == "po") sv.pop_back();
  }

  std::cout << "Final Vector: " << '\n';
  std::cout << "mCap = " << sv.capacity() << " " << "mSize = " << sv.size() << '\n';
  for (int i = 0; i < sv.size(); ++i) std::cout << sv[i] << " "; 
  std::cout << '\n'; 
  std::cout << LINE_BREAK << '\n';
}

signed main() {
  int T; std::cin >> T;
  while (T--) {
    int bs; std::cin >> bs;
    test(bs);
  }
}