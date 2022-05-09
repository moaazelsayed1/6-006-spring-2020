#include "node.h"
#include <bits/stdc++.h>

// using namespace std;

namespace practice {
class LinkedList {
private:
  Node *head;
  Node *tail;
  int size_;

public:
  LinkedList();
  ~LinkedList();

  // returns number of data elements in list
  int size();
  // bool returns true if empty
  bool empty();
  // returns the value of the nth item (starting at 0 for first)
  int &value_at(int n);
  //  adds an item to the front of the list
  void push_front(int value);
  // remove front item and return its value
  int pop_front();
  //  adds an item to the back the list
  void push_back(int value);
  // remove back item and return its value
  int pop_back();
  // get value of front item
  int front();
  // get value of back item
  int back();
  // insert value at index
  void insert(int value, int n);
  // removes node at given index
  void erase(int n);
  //  returns the value of the node at nth position from the end of the list
  int value_n_from_end(int n);
  // reverses the list
  void reverse();
  // removes the first item in the list with this value
  void remove_value(int value);
  // prints the list
  void print();
};

}; // namespace practice
