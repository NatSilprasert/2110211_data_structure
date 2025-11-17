int depth(node *n) {
  if (n == nullptr) return -1;
  if (n->left_child == nullptr) return 0;
  
  int result = depth(n->left_child);

  node *it = n->left_child;
  while (it->right_sibling != nullptr) {
    it = it->right_sibling;
    result = std::max(result, depth(it));
  }
  return result + 1;
}