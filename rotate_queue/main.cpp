#include <iostream>

#include "queue.h"
#include "student.h"

static const std::string LINE_BREAK = "-------------------------";

void test() {
  CP::queue<int> que;
  while (true) {
    std::string c; std::cin >> c;
    
    //quit
    if (c == "q") break;
    //print size
    if (c == "si") {
      std::cout << que.size() << '\n';
    }
    //print front
    if (c == "fr") {
      std::cout << que.front() << '\n';
    }
    //print back
    if (c == "ba") {
      std::cout << que.back() << '\n';
    }
    //push
    if (c == "pu") {
      int x; std::cin >> x;
      que.push(x);
    }
    //pop
    if (c == "po") que.pop();
    //rotate
    if (c == "ro") {
      int k; std::cin >> k;
      que.rotate(k);
    }
    //print (temporary)
    if (c == "pr") que.print();
  }

  que.print();
  std::cout << LINE_BREAK << '\n';
}

signed main() {
  // std::ios_base::sync_with_stdio(0); std::cin.tie(NULL);
  int T; std::cin >> T;
  while (T--) {
    test();
  }
}