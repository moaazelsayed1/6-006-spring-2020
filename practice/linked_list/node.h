#include <bits/stdc++.h>

using namespace std;

namespace practice {
class Node {
private:
  int data;
  Node *next;
  Node *previous;

public:
  Node() {
    this->next = nullptr;
    this->previous = nullptr;
    this->data = 0;
  }
  Node(int &value) {
    this->next = nullptr;
    this->previous = nullptr;
    this->data = value;
  }
  int &GetData() { return data; }
  void SetData(int &data) { this->data = data; }
  Node *GetNext() { return this->next; }
  void SetNext(Node *node) { next = node; }
  Node *GetPrevious() { return this->previous; }
  void SetPrevious(Node *node) { this->previous = node; }
  ~Node() {}
};
}; // namespace practice
