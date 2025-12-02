#include <iostream>
#include "priority_queue.h"
#include "student.h"

const std::string LINE_BREAK = "----------------";

void test() {
  int n; std::cin >> n;
  CP::priority_queue<int, std::less<int>> pq;
  for (int i = 1; i <= n; ++i) {
    int x; std::cin >> x;
    pq.push(x);
  }
  size_t k; std::cin >> k;
  std::cout << "Before Swap:" << '\n';
  pq.print();
  pq.child_swap(k);
  std::cout << "After Swap:" << std::endl;
  pq.print();
  std::cout << LINE_BREAK << '\n';
}

signed main() {
  int T; std::cin >> T;
  while (T--) {
    test();
  }
}