void replace(const T& x, list<T>& y) {
  auto it = begin();
  while (it != end()) {

    if (*it == x) {
      auto insertPos = it;
      for (auto &item : y) {
        insert(insertPos, item);
      }
      it = erase(it);
    }

    else it++;

  } 
}
