#include <iostream>

#include "list.h"
#include "student.h"

signed main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  CP::list<char> l;
  for(int i=0; i<n; ++i) {
    char x;
    std::cin >> x;
    l.push_back(x);
  }
  std::cout << l.longest_palindrome() << std::endl;
  return 0;
}