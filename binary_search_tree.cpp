#define fn auto
#include <iostream>
using namespace std;

template <typename K, typename T> struct Tree {
  K key;
	T value;
  Tree* node1;
  Tree* node2;
  fn push(K key, T value) -> Tree {
    if(key > this->key){
      if(this->node2 == nullptr) {
        Tree<K, T> *tree = new Tree;
        *tree = {key, value, nullptr, nullptr};
        this->node2 = tree;
      } else {
        this->node2->push(key, value);
      }
    } else {
      if(this->node1 == nullptr) {
         Tree<K, T> *tree = new Tree;
        *tree = {key, value, nullptr, nullptr};
        this->node1 = tree;
      } else {
        this->node1->push(key, value);
      }
    }
  }
  fn get(K key) -> T {
    if(this->key == key){
      return this->value;
    } else {
      Tree* node = key > this->key ? this->node2
                                   : this->node1;
      if(node != nullptr){
        return node->get(key);
      } else {
  	    throw exception();
      }
    }
  }
};

fn main() -> int {
  Tree<int, int> tree = {5, 9, nullptr, nullptr};
  tree.push(7, 6);
  tree.push(3, 11);
  tree.push(5, 8);
  tree.push(6, 20);
  tree.push(9, 3);
  tree.push(0, -1);
  try {
    cout << tree.get(3) << endl;
    cout << tree.get(5) << endl;
    cout << tree.get(6) << endl;
    cout << tree.get(9) << endl;
    cout << tree.get(11) << endl;
  } catch (exception e) {
		cout << "error" << endl;
  }
}

