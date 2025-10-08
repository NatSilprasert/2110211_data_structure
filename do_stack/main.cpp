#include <iostream>

#include "stack.h"
#include "student.h"

static const std::string LINE_BREAK = "-------------------------";

void test() {
  CP::stack<int> stk;
  while (true) {
    std::string op; std::cin >> op;

    //quit
    if (op == "q") break;
    //print size
    if (op == "si") {
      std::cout << stk.size() << '\n';
    }
    //print top  
    if (op == "to") {
      std::cout << stk.top() << '\n';
    }
    //push
    if (op == "pu") {
      int x; std::cin >> x;
      stk.push(x);
    }
    //pop
    if (op == "po") stk.pop();
    //undo
    if (op == "un") stk.undo();
    //redo
    if (op == "re") stk.redo();
  }

  stk.print();
  std::cout << LINE_BREAK << '\n';
}

signed main() {
  int T; std::cin >> T;  
  while (T--) {
    test();
  }
}