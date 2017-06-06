#define fn auto
#include <iostream>
using namespace std;

template <typename t> struct Tree {
	t value;
  Tree* node1;
  Tree* node2;
  fn push_value(int n) -> Tree {
    Tree *node = n > this->value ? this->node2
                                 : this->node1;
    if(node == nullptr) {
      Tree *tree = new Tree;
      *tree = {n, nullptr, nullptr};
      node = tree;
    } else {
      node->push_value(n);
    }
  }
};

fn main() -> int {
  Tree<int> tree = {5, nullptr, nullptr};
  tree.push_value(7);
  tree.push_value(3);
  tree.push_value(5);
}

