#include <iostream>
#include <vector>

#include "list.h"
#include "student.h"

signed main(int argc, char *argv[]) {
  int n;
  std::cin >> n;

  CP::list<char> l;
  for(int i=0; i<n; ++i) {
    char v;
    std::cin >> v;
    l.push_back(v);
  }

  int t;
  std::cin >> t;
  for(int i=0, p, d; i<t; ++i) {
    std::cin >> p >> d;
    l.change_prev(p, d);
  }

  size_t fixed_count = l.fix_wrong();
  std::cout << fixed_count << std::endl;

  return 0;
}