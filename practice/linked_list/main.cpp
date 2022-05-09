#include "linked_list.h"
#include <bits/stdc++.h>

using namespace std;
using namespace practice;

int main() {
  LinkedList list;
  cout << sizeof(list) << endl;
  cout << list.size() << endl;
  cout << list.empty() << endl;
  list.push_back(6);

  cout << list.front() << endl;
  cout << list.back() << endl;
  for (int i = 0; i < 20; i++) {
    list.push_back(i);
  }
  list.print();

  cout << list.front() << endl;
  list.pop_front();
  cout << list.front() << endl;
  list.reverse();
  list.erase(21);
  list.remove_value(5);
  list.print();
  cout << list.value_at(5) << endl;
  cout << list.size() << endl;
  cout << list.empty() << endl;
}
