#include "linked_list.h"
#include <bits/stdc++.h>

using namespace std;

namespace practice {

LinkedList::LinkedList() {
  head = nullptr;
  tail = nullptr;
  size_ = 0;
}
LinkedList::~LinkedList() {
  Node *current = head;
  Node *next = nullptr;

  while (current) {
    next = current->GetNext();
    delete current;
    current = next;
  }
}
int LinkedList::size() { return this->size_; }

bool LinkedList::empty() { return size() == 0; }

int &LinkedList::value_at(int index) {
  Node *current = head;
  int i = 0;
  while (current != nullptr && i < index) {
    i++;
    current = current->GetNext();
    if (current == nullptr) {
      cout << "out of bounds." << endl;
      exit(EXIT_FAILURE);
    }
  }

  return current->GetData();
}

void LinkedList::push_front(int value) {
  Node *node = new Node(value);
  node->SetNext(head);
  if (head != nullptr) {

    head->SetPrevious(node);
  }
  head = (node);
  // node->SetPrevious(nullptr);

  if (tail == nullptr) {
    tail = node;
  }
  size_++;
  // cout << size() << endl;
}

int LinkedList::pop_front() {
  Node *node = head;
  int item = head->GetData();
  head = head->GetNext();
  head->SetPrevious(nullptr);
  free(node);
  return item;
  size_--;
}

void LinkedList::push_back(int value) {
  Node *node = new Node(value);
  node->SetPrevious(tail);
  if (tail != nullptr) {

    tail->SetNext(node);
  }
  tail = node;
  // node->SetNext(nullptr);
  if (head == nullptr) {
    head = node;
  }
  size_++;
}

int LinkedList::pop_back() {
  Node *node = tail;
  int item = tail->GetData();
  tail = tail->GetPrevious();
  tail->SetNext(nullptr);
  free(node);
  size_--;
  return item;
}

int LinkedList::front() {
  int item;
  if (head != nullptr) {
    item = head->GetData();
  } else {
    cout << "NULL" << endl;
    exit(EXIT_FAILURE);
  }
  return item;
}

int LinkedList::back() {
  int item;
  if (tail != nullptr) {
    item = tail->GetData();
  } else {
    cout << "NULL" << endl;
    exit(EXIT_FAILURE);
  }
  return item;
}
void LinkedList::insert(int value, int index) {
  Node *node = new Node(value);
  Node *current = head;
  int i = 0;
  while (current != nullptr && i < index) {
    i++;
    current = current->GetNext();

    if (current == nullptr) {
      cout << "out of bounds." << endl;
      exit(EXIT_FAILURE);
    }
  }

  node->SetPrevious(current->GetPrevious());
  node->SetNext(current);
  current->SetPrevious(node);
  size_++;
}

void LinkedList::erase(int index) {
  Node *current = head;
  int i = 0;
  while (current != nullptr && i < index) {
    i++;
    current = current->GetNext();
    if (current == nullptr) {
      cout << "out of bounds." << endl;
      exit(EXIT_FAILURE);
    }
  }

  current->GetPrevious()->SetNext(current->GetNext());
  current->GetNext()->SetPrevious(current->GetPrevious());
  free(current);
  size_--;
}

int LinkedList::value_n_from_end(int index) {
  Node *current = tail;
  int i = 0;
  while (current != nullptr && i < index) {
    i++;
    current = current->GetPrevious();
  }

  if (current == nullptr) {
    cout << "out of bounds." << endl;
    exit(EXIT_FAILURE);
  }
  int item = current->GetData();
  return item;
}

void LinkedList::reverse() {
  Node *current = head;
  Node *tmp = nullptr;
  while (current != nullptr) {
    tmp = current->GetPrevious();
    current->SetPrevious(current->GetNext());
    current->SetNext(tmp);

    current = current->GetPrevious();
  }
  tmp = head;
  head = tail;
  tail = tmp;
}

void LinkedList::remove_value(int value) {
  Node *node = new Node(value);

  Node *current = head;
  int i = 0;
  while (current != nullptr) {
    i++;
    if (current->GetData() == value) {
      break;
    }
    current = current->GetNext();
    if (current == nullptr) {
      cout << value << "does not exist in the list!" << endl;
      exit(EXIT_FAILURE);
    }
  }

  current->GetPrevious()->SetNext(current->GetNext());
  current->GetNext()->SetPrevious(current->GetPrevious());
  free(current);
  size_--;
}

void LinkedList::print() {
  Node *current = head;
  int i = 0;
  while (current != nullptr) {
    cout << "list[" << i << "]: " << current->GetData() << endl;
    i++;
    current = current->GetNext();
  }
}

} // namespace practice
