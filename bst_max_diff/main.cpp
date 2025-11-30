#include <cassert>
#include <iostream>
#include "map_bst.h"
#include "student.h"

int main() {
  CP::map_bst<int, int> mp;
  int n,k,m;
  std::cin >> n;
  for (int i=0;i<n;i++) {
    std::cin >> k >> m;
    mp[k] = m;
  }
  std::cout << mp.max_value_diff() << "\n";
  return 0;
}
